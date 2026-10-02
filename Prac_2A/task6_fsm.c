  /******************************************************************************
  * @file    task6_fsm.c
  * @brief   TASK 6 : NON-BLOCKING EEPROM TRANSACTION STATE MACHINE
  *
  * Restructure the Task 4 transaction so the main loop never stops:
  *
  *   request -> write-enable -> write -> wait for EEPROM
  *           -> read-back -> verify -> result
  *
  * Rules (handout, Task 6):
  *   - No HAL_Delay(), and no software busy-wait for the EEPROM's internal
  *     write cycle. You may use HAL_GetTick() to decide when the next status
  *     check is due.
  *   - Each call does a small amount of work, updates the state, and returns.
  *   - Do not put the whole transaction inside one blocking function called
  *     from the loop.
  *   - While a transaction is in progress the loop must still respond to PA3.
  *
  * Controls: PA0 starts, PA3 aborts. PB0..PB7 show the last byte read, PB11
  * (green) a successful verification, PB10 (red) a failed one.
  ******************************************************************************
  */
#include "prac2a.h"

/* Task 6 State Definitions */
typedef enum {
    STATE_IDLE = 0,
    STATE_WREN_SEND,
    STATE_WRITE_SEND,
    STATE_POLL_WIP,
    STATE_READ_SEND,
    STATE_VERIFY,
    STATE_SUCCESS,
    STATE_FAILURE,
    STATE_ABORTED
} ee_state_t;

volatile uint8_t ee_state     = (uint8_t)STATE_IDLE;
volatile uint8_t ee_last_read = 0u;
volatile uint8_t ee_use_fsm   = 1u;

/* State Machine Tracking Variables */
static uint32_t last_poll_time  = 0u;
static uint32_t poll_start_time = 0u;

/* Timing constants */
#define EEPROM_WRITE_TIMEOUT_MS  50u
#define EEPROM_POLL_INTERVAL_MS   1u

void update_eeprom_state_machine(uint32_t now)
{
    /* Abort Priority Check: PA3 abandons transaction immediately */
    if (btn_abort_edge)
    {
        btn_abort_edge = 0u;
        btn_start_edge = 0u;

        /* Ensure CS line is released high */
        eeprom_cs_high();

        eeprom_verify_ok = 0u;
        ee_state = (uint8_t)STATE_ABORTED;
        return;
    }

    switch ((ee_state_t)ee_state)
    {
    case STATE_IDLE:
    case STATE_SUCCESS:
    case STATE_FAILURE:
    case STATE_ABORTED:
        if (btn_start_edge)
        {
            btn_start_edge = 0u;
            ee_state = (uint8_t)STATE_WREN_SEND;
        }
        break;

    case STATE_WREN_SEND:
        eeprom_cs_low();
        (void)spi_transfer(EEPROM_CMD_WREN);      /* Send Write Enable command */
        eeprom_cs_high();

        ee_state = (uint8_t)STATE_WRITE_SEND;
        break;

    case STATE_WRITE_SEND:
        eeprom_cs_low();
        (void)spi_transfer(EEPROM_CMD_WRITE);     /* Send Write command */
        (void)spi_transfer((uint8_t)(EEPROM_ADDR_A >> 8));
        (void)spi_transfer((uint8_t)(EEPROM_ADDR_A & 0xFFu));
        (void)spi_transfer(TEST_BYTE_B);
        eeprom_cs_high();

        last_poll_time  = now;
        poll_start_time = now;
        ee_state = (uint8_t)STATE_POLL_WIP;
        break;

    case STATE_POLL_WIP:
        if ((now - last_poll_time) >= EEPROM_POLL_INTERVAL_MS)
        {
            last_poll_time = now;

            eeprom_cs_low();
            (void)spi_transfer(EEPROM_CMD_RDSR);  /* Read Status Register */
            uint8_t sr = spi_transfer(0xFFu);
            eeprom_cs_high();

            /* Check if Write In Progress (WIP - bit 0) is cleared */
            if ((sr & 0x01u) == 0u)
            {
                ee_state = (uint8_t)STATE_READ_SEND;
            }
            else if ((now - poll_start_time) >= EEPROM_WRITE_TIMEOUT_MS)
            {
                eeprom_verify_ok = 0u;
                ee_state = (uint8_t)STATE_FAILURE;
            }
        }
        break;

    case STATE_READ_SEND:
        eeprom_cs_low();
        (void)spi_transfer(EEPROM_CMD_READ);      /* Send Read command */
        (void)spi_transfer((uint8_t)(EEPROM_ADDR_A >> 8));
        (void)spi_transfer((uint8_t)(EEPROM_ADDR_A & 0xFFu));
        ee_last_read = spi_transfer(0xFFu);
        eeprom_cs_high();

        ee_state = (uint8_t)STATE_VERIFY;
        break;

    case STATE_VERIFY:
        if (ee_last_read == TEST_BYTE_B)
        {
            eeprom_verify_ok = 1u;
            ee_state = (uint8_t)STATE_SUCCESS;
        }
        else
        {
            eeprom_verify_ok = 0u;
            ee_state = (uint8_t)STATE_FAILURE;
        }
        break;

    default:
        ee_state = (uint8_t)STATE_IDLE;
        break;
    }
}

void update_outputs(void)
{
    leds_write_byte(ee_last_read);

    switch ((ee_state_t)ee_state)
    {
    case STATE_SUCCESS:
        status_leds_show(STATUS_PASS);
        break;

    case STATE_FAILURE:
    case STATE_ABORTED:
        status_leds_show(STATUS_FAIL);
        break;

    case STATE_WREN_SEND:
    case STATE_WRITE_SEND:
    case STATE_POLL_WIP:
    case STATE_READ_SEND:
    case STATE_VERIFY:
        /* Activity indicator while transaction is active */
        status_leds_show(STATUS_OFF);
        break;

    case STATE_IDLE:
    default:
        if (eeprom_verify_ok)
        {
            status_leds_show(STATUS_PASS);
        }
        else
        {
            status_leds_show(STATUS_FAIL);
        }
        break;
    }
}

void task6_setup(void)
{
    task1_gpio_init();
    eeprom_spi_init();
    board_io_init();

    eeprom_read_only_path();
    ee_last_read = eeprom_read_value;

    ee_state = (uint8_t)STATE_IDLE;
}

void task6_loop(uint32_t now)
{
    task1_gpio_update(now);
    read_inputs(now);

    if (ee_use_fsm)
    {
        update_eeprom_state_machine(now);
        update_outputs();
    }
    else
    {
        if (btn_start_edge)
        {
            btn_start_edge = 0u;
            eeprom_write_verify_path();     /* Task 4: blocks for the write */
            ee_last_read = eeprom_read_value;
        }
        btn_abort_edge = 0u;
    }
}

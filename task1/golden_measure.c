/*
 * Task 1: The Golden Measure on the PC
 *
 * Integer square root of a 32-bit unsigned input x: the largest integer
 * whose square does not exceed x.  Golden version uses double precision
 * arithmetic and the standard library square root.
 *
 * Prediction (written before running):
 *   On a ~3 GHz x86-64 CPU, sqrt + floor + conversion is roughly
 *   20..40 instructions.  Estimate: 40 instructions * 0.33 ns/instr
 *   ~= 13 ns per call.  One call alone cannot be timed reliably because
 *   clock_gettime resolution is ~10..50 ns and scheduling noise is larger
 *   than the call itself, so we loop and divide.
 *
 * Build:   gcc -O2 -o golden_measure golden_measure.c -lm
 * Run:     ./golden_measure
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

static const uint32_t inputs[10] = {
    0, 1, 15, 16, 4095, 65535,
    123456789, 987654321, 4294836225u, 4294967295u
};

static uint32_t golden_isqrt(uint32_t x)
{
    return (uint32_t)floor(sqrt((double)x));
}

static double timestamp_us(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);  //CLOCK_MONOTONIC is a clock source measuring abs elapsed CPU time (doesnt jump back/forward due to system time adjustments)
    //return sum of seconds and nanoseconds (both converted to microseconds)/ time since computer booted up
    return (double)t.tv_sec*1e6 + (double)t.tv_nsec/1e3;

}

/* Hand check: r^2 <= x < (r+1)^2, written out in full. */
static int hand_check(uint32_t x, uint32_t r)
{
    uint64_t r2 = (uint64_t)r * r;    //squaring the result
    uint64_t r2_next = (uint64_t)(r + 1) * (r + 1); //squaring the result +1
    bool condition_1 = true;
    bool condition_2 = true;

    if (r2 > x){
        condition_1 = false;  // i.e., condition fails if result squared exceeds the input
    }
    
    if (r2_next <= x){
        condition_2 = false; //i.e., condition fails if the next int after result squared doesnt exceed input
    }

    return (condition_1 && condition_2); //returns 1 if both are true and 0 if either is false
}

static double time_n_calls(long reps)
{
    const uint32_t test_input = 987654321u;
    volatile uint32_t sink; //dummy assignment target forcing compiler to execute loop
    // note: sink is volatile to force the compiler to write the output of golden_isqrt to memory

    double start_us = timestamp_us(); //capture initial sys timestamp

    for ( long i =0; i<reps; i++){
        sink = golden_isqrt(test_input);
    }

    double end_us = timestamp_us(); //capture sys timestamp after loop completes
    return ((end_us - start_us)*1000)/((double) reps); // returns average execution time of a single func call in nanoseconds

}

int main(void)
{
    printf("Task 1: Golden Measure Output\n");
    printf("Input        | Result        | r^2 <= x < (r+1)^2 Validity\n");
    for (int i = 0; i < 10; i++){
        uint32_t x = inputs[i];
        uint32_t r = golden_isqrt(x);
        uint64_t r2 = (uint64_t)r * r;
        uint64_t next_r = (uint64_t)(r + 1) * (r + 1);

        int hand_validity_check = hand_check(x, r);
        
        const char* validity_status = (hand_validity_check == 1) ? "Pass" : "Fail";

        printf("%-12" PRIu32 " | %-12" PRIu32 "  | %" PRIu64 " <= %" PRIu32 " < %-10" PRIu64 ": %s\n",
               x, r, r2, x, next_r, validity_status);
    }


    printf("\nPC Timing Benchmark (x=987654321)\n");
    long run1_reps = 2000000L;
    long run2_reps = 10000000L;

    double time_run1 = time_n_calls(run1_reps);
    double time_run2 = time_n_calls(run2_reps);

    double tottal_time_1 = time_run1 * run1_reps;
    double tottal_time_2 = time_run2 * run2_reps;

    double mean_time = (time_run1 + time_run2) / 2.0;
    double spread = fabs(time_run1 - time_run2);

    printf("Run 1 Repetitions : %ld\n", run1_reps);
    printf("Run 1 Time/Call   : %.2f ns\n\n", time_run1);
    printf("Total Time Run 1  : %.2f us\n", tottal_time_1/1000);

    printf("Run 2 Repetitions : %ld\n", run2_reps);
    printf("Run 2 Time/Call   : %.2f ns\n\n", time_run2);
    printf("Total Time Run 2  : %.2f us\n", tottal_time_2/1000);

    printf("Mean Time/Call    : %.2f ns\n", mean_time);
    printf("Spread Across Runs: %.2f ns\n", spread);
    return 0;
    }


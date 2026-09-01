################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Practical1B-Assembly/Core/Src/dsp.s \
../Practical1B-Assembly/Core/Src/lcd.s 

C_SRCS += \
../Practical1B-Assembly/Core/Src/main.c \
../Practical1B-Assembly/Core/Src/stm32f0xx_hal_msp.c \
../Practical1B-Assembly/Core/Src/stm32f0xx_it.c \
../Practical1B-Assembly/Core/Src/syscalls.c \
../Practical1B-Assembly/Core/Src/sysmem.c \
../Practical1B-Assembly/Core/Src/system_stm32f0xx.c 

S_DEPS += \
./Practical1B-Assembly/Core/Src/dsp.d \
./Practical1B-Assembly/Core/Src/lcd.d 

C_DEPS += \
./Practical1B-Assembly/Core/Src/main.d \
./Practical1B-Assembly/Core/Src/stm32f0xx_hal_msp.d \
./Practical1B-Assembly/Core/Src/stm32f0xx_it.d \
./Practical1B-Assembly/Core/Src/syscalls.d \
./Practical1B-Assembly/Core/Src/sysmem.d \
./Practical1B-Assembly/Core/Src/system_stm32f0xx.d 

OBJS += \
./Practical1B-Assembly/Core/Src/dsp.o \
./Practical1B-Assembly/Core/Src/lcd.o \
./Practical1B-Assembly/Core/Src/main.o \
./Practical1B-Assembly/Core/Src/stm32f0xx_hal_msp.o \
./Practical1B-Assembly/Core/Src/stm32f0xx_it.o \
./Practical1B-Assembly/Core/Src/syscalls.o \
./Practical1B-Assembly/Core/Src/sysmem.o \
./Practical1B-Assembly/Core/Src/system_stm32f0xx.o 


# Each subdirectory must supply rules for building sources it contributes
Practical1B-Assembly/Core/Src/%.o: ../Practical1B-Assembly/Core/Src/%.s Practical1B-Assembly/Core/Src/subdir.mk
	$(error unable to generate command line)
Practical1B-Assembly/Core/Src/%.o Practical1B-Assembly/Core/Src/%.su Practical1B-Assembly/Core/Src/%.cyclo: ../Practical1B-Assembly/Core/Src/%.c Practical1B-Assembly/Core/Src/subdir.mk
	$(error unable to generate command line)

clean: clean-Practical1B-2d-Assembly-2f-Core-2f-Src

clean-Practical1B-2d-Assembly-2f-Core-2f-Src:
	-$(RM) ./Practical1B-Assembly/Core/Src/dsp.d ./Practical1B-Assembly/Core/Src/dsp.o ./Practical1B-Assembly/Core/Src/lcd.d ./Practical1B-Assembly/Core/Src/lcd.o ./Practical1B-Assembly/Core/Src/main.cyclo ./Practical1B-Assembly/Core/Src/main.d ./Practical1B-Assembly/Core/Src/main.o ./Practical1B-Assembly/Core/Src/main.su ./Practical1B-Assembly/Core/Src/stm32f0xx_hal_msp.cyclo ./Practical1B-Assembly/Core/Src/stm32f0xx_hal_msp.d ./Practical1B-Assembly/Core/Src/stm32f0xx_hal_msp.o ./Practical1B-Assembly/Core/Src/stm32f0xx_hal_msp.su ./Practical1B-Assembly/Core/Src/stm32f0xx_it.cyclo ./Practical1B-Assembly/Core/Src/stm32f0xx_it.d ./Practical1B-Assembly/Core/Src/stm32f0xx_it.o ./Practical1B-Assembly/Core/Src/stm32f0xx_it.su ./Practical1B-Assembly/Core/Src/syscalls.cyclo ./Practical1B-Assembly/Core/Src/syscalls.d ./Practical1B-Assembly/Core/Src/syscalls.o ./Practical1B-Assembly/Core/Src/syscalls.su ./Practical1B-Assembly/Core/Src/sysmem.cyclo ./Practical1B-Assembly/Core/Src/sysmem.d ./Practical1B-Assembly/Core/Src/sysmem.o ./Practical1B-Assembly/Core/Src/sysmem.su ./Practical1B-Assembly/Core/Src/system_stm32f0xx.cyclo ./Practical1B-Assembly/Core/Src/system_stm32f0xx.d ./Practical1B-Assembly/Core/Src/system_stm32f0xx.o ./Practical1B-Assembly/Core/Src/system_stm32f0xx.su

.PHONY: clean-Practical1B-2d-Assembly-2f-Core-2f-Src


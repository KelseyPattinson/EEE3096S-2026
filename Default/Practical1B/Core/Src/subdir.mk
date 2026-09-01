################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Practical1B/Core/Src/main.c \
../Practical1B/Core/Src/stm32f0xx_hal_msp.c \
../Practical1B/Core/Src/stm32f0xx_it.c \
../Practical1B/Core/Src/syscalls.c \
../Practical1B/Core/Src/sysmem.c \
../Practical1B/Core/Src/system_stm32f0xx.c 

C_DEPS += \
./Practical1B/Core/Src/main.d \
./Practical1B/Core/Src/stm32f0xx_hal_msp.d \
./Practical1B/Core/Src/stm32f0xx_it.d \
./Practical1B/Core/Src/syscalls.d \
./Practical1B/Core/Src/sysmem.d \
./Practical1B/Core/Src/system_stm32f0xx.d 

OBJS += \
./Practical1B/Core/Src/main.o \
./Practical1B/Core/Src/stm32f0xx_hal_msp.o \
./Practical1B/Core/Src/stm32f0xx_it.o \
./Practical1B/Core/Src/syscalls.o \
./Practical1B/Core/Src/sysmem.o \
./Practical1B/Core/Src/system_stm32f0xx.o 


# Each subdirectory must supply rules for building sources it contributes
Practical1B/Core/Src/%.o Practical1B/Core/Src/%.su Practical1B/Core/Src/%.cyclo: ../Practical1B/Core/Src/%.c Practical1B/Core/Src/subdir.mk
	$(error unable to generate command line)

clean: clean-Practical1B-2f-Core-2f-Src

clean-Practical1B-2f-Core-2f-Src:
	-$(RM) ./Practical1B/Core/Src/main.cyclo ./Practical1B/Core/Src/main.d ./Practical1B/Core/Src/main.o ./Practical1B/Core/Src/main.su ./Practical1B/Core/Src/stm32f0xx_hal_msp.cyclo ./Practical1B/Core/Src/stm32f0xx_hal_msp.d ./Practical1B/Core/Src/stm32f0xx_hal_msp.o ./Practical1B/Core/Src/stm32f0xx_hal_msp.su ./Practical1B/Core/Src/stm32f0xx_it.cyclo ./Practical1B/Core/Src/stm32f0xx_it.d ./Practical1B/Core/Src/stm32f0xx_it.o ./Practical1B/Core/Src/stm32f0xx_it.su ./Practical1B/Core/Src/syscalls.cyclo ./Practical1B/Core/Src/syscalls.d ./Practical1B/Core/Src/syscalls.o ./Practical1B/Core/Src/syscalls.su ./Practical1B/Core/Src/sysmem.cyclo ./Practical1B/Core/Src/sysmem.d ./Practical1B/Core/Src/sysmem.o ./Practical1B/Core/Src/sysmem.su ./Practical1B/Core/Src/system_stm32f0xx.cyclo ./Practical1B/Core/Src/system_stm32f0xx.d ./Practical1B/Core/Src/system_stm32f0xx.o ./Practical1B/Core/Src/system_stm32f0xx.su

.PHONY: clean-Practical1B-2f-Core-2f-Src


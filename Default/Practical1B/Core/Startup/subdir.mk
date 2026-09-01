################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Practical1B/Core/Startup/startup_stm32f051c8tx.s 

S_DEPS += \
./Practical1B/Core/Startup/startup_stm32f051c8tx.d 

OBJS += \
./Practical1B/Core/Startup/startup_stm32f051c8tx.o 


# Each subdirectory must supply rules for building sources it contributes
Practical1B/Core/Startup/%.o: ../Practical1B/Core/Startup/%.s Practical1B/Core/Startup/subdir.mk
	$(error unable to generate command line)

clean: clean-Practical1B-2f-Core-2f-Startup

clean-Practical1B-2f-Core-2f-Startup:
	-$(RM) ./Practical1B/Core/Startup/startup_stm32f051c8tx.d ./Practical1B/Core/Startup/startup_stm32f051c8tx.o

.PHONY: clean-Practical1B-2f-Core-2f-Startup


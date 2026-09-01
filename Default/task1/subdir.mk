################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../task1/golden_measure.c 

C_DEPS += \
./task1/golden_measure.d 

OBJS += \
./task1/golden_measure.o 


# Each subdirectory must supply rules for building sources it contributes
task1/%.o task1/%.su task1/%.cyclo: ../task1/%.c task1/subdir.mk
	$(error unable to generate command line)

clean: clean-task1

clean-task1:
	-$(RM) ./task1/golden_measure.cyclo ./task1/golden_measure.d ./task1/golden_measure.o ./task1/golden_measure.su

.PHONY: clean-task1


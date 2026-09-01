################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := del

# All of the sources participating in the build are defined here
-include sources.mk
-include task1/subdir.mk
-include Practical1B/Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Practical1B/Debug/Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Practical1B/Debug/Core/Startup/subdir.mk
-include Practical1B/Debug/Core/Src/subdir.mk
-include Practical1B/Debug/subdir.mk
-include Practical1B/Core/Startup/subdir.mk
-include Practical1B/Core/Src/subdir.mk
-include Practical1B-Assembly/Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Practical1B-Assembly/Debug/Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Practical1B-Assembly/Debug/Core/Startup/subdir.mk
-include Practical1B-Assembly/Debug/Core/Src/subdir.mk
-include Practical1B-Assembly/Debug/subdir.mk
-include Practical1B-Assembly/Core/Startup/subdir.mk
-include Practical1B-Assembly/Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME :=
BUILD_ARTIFACT_EXTENSION :=
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \

MAP_FILES += \
.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
.list \


# All Target
all: main-build

# Main-build Target
main-build:  secondary-outputs

# Tool invocations
 .map: $(OBJS) $(USER_OBJS) fail-specified-linker-script-missing makefile objects.list $(OPTIONAL_TOOL_DEPS)
	$(error unable to generate command line)
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > ".list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM)  .list .map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Bluetooth.lss \

FLASH_IMAGE += \
Bluetooth.hex \

EEPROM_IMAGE += \
Bluetooth.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Bluetooth.elf secondary-outputs

# Tool invocations
Bluetooth.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Bluetooth.map -mmcu=atmega8 -o "Bluetooth.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Bluetooth.lss: Bluetooth.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Bluetooth.elf  >"Bluetooth.lss"
	@echo 'Finished building: $@'
	@echo ' '

Bluetooth.hex: Bluetooth.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Bluetooth.elf  "Bluetooth.hex"
	@echo 'Finished building: $@'
	@echo ' '

Bluetooth.eep: Bluetooth.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Bluetooth.elf  "Bluetooth.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Bluetooth.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega8 Bluetooth.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Bluetooth.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

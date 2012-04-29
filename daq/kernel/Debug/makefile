################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500

ORDERED_OBJS += \
"./zen.obj" \
"./util.obj" \
"./tmr.obj" \
"./time.obj" \
"./task.obj" \
"./sem.obj" \
"./queue.obj" \
"./mutex.obj" \
"./mem.obj" \
"./mbox.obj" \
"./flag.obj" \
"./demo.obj" \
"./dbg_r.obj" \
"./cpu_c.obj" \
"./cpu_a.obj" \
"./core.obj" \
"./boot.obj" \
"./autoinit.obj" \
"./TEST.obj" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: kernel.lib

# Tool invocations
kernel.lib: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: C5500 Archiver'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/ar55" r "kernel.lib" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C5500_LIBRARY_OUTPUTS__QUOTED) "kernel.lib"
	-$(RM) "core.pp" "cpu_c.pp" "dbg_r.pp" "demo.pp" "flag.pp" "mbox.pp" "mem.pp" "mutex.pp" "queue.pp" "sem.pp" "task.pp" "time.pp" "tmr.pp" "util.pp" "zen.pp" 
	-$(RM) "TEST.pp" 
	-$(RM) "TEST.obj" "autoinit.obj" "boot.obj" "core.obj" "cpu_a.obj" "cpu_c.obj" "dbg_r.obj" "demo.obj" "flag.obj" "mbox.obj" "mem.obj" "mutex.obj" "queue.obj" "sem.obj" "task.obj" "time.obj" "tmr.obj" "util.obj" "zen.obj" 
	-$(RM) "autoinit.pp" "boot.pp" "cpu_a.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_sys/da225/src/pal_sys.c 

OBJS += \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_sys/build/Release/pal_sys.obj 

C_DEPS += \
./pal_sys.pp 

OBJS__QTD += \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\pal_sys\build\Release\pal_sys.obj" 

C_DEPS__QTD += \
".\pal_sys.pp" 

C_SRCS_QUOTED += \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_sys/da225/src/pal_sys.c" 


# Each subdirectory must supply rules for building sources it contributes
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_sys/build/Release/pal_sys.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_sys/da225/src/pal_sys.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O2 --define="BIOS_BUILD" --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_sys/da225/src" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_sys/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/da225/dsp/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/inc" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_sys/build/Release" --preproc_with_compile --preproc_dependency="pal_sys.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '



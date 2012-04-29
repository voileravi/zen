################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/src/dda_i2s.c \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/src/ddc_i2s.c \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/src/llc_i2s.c 

OBJS += \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/build/Release/dda_i2s.obj \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/build/Release/ddc_i2s.obj \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/build/Release/llc_i2s.obj 

C_DEPS += \
./dda_i2s.pp \
./ddc_i2s.pp \
./llc_i2s.pp 

OBJS__QTD += \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\i2s\build\Release\dda_i2s.obj" \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\i2s\build\Release\ddc_i2s.obj" \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\i2s\build\Release\llc_i2s.obj" 

C_DEPS__QTD += \
".\dda_i2s.pp" \
".\ddc_i2s.pp" \
".\llc_i2s.pp" 

C_SRCS_QUOTED += \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/src/dda_i2s.c" \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/src/ddc_i2s.c" \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/src/llc_i2s.c" 


# Each subdirectory must supply rules for building sources it contributes
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/build/Release/dda_i2s.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/src/dda_i2s.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O3 --define="BIOS_BUILD" --define="I2S_POLLED_INTERRUPT" --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/da225/dsp/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/src" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2c/inc" --include_path="/ASRC/inc" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/build/Release" --preproc_with_compile --preproc_dependency="dda_i2s.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/build/Release/ddc_i2s.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/src/ddc_i2s.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O3 --define="BIOS_BUILD" --define="I2S_POLLED_INTERRUPT" --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/da225/dsp/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/src" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2c/inc" --include_path="/ASRC/inc" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/build/Release" --preproc_with_compile --preproc_dependency="ddc_i2s.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/build/Release/llc_i2s.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/src/llc_i2s.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O3 --define="BIOS_BUILD" --define="I2S_POLLED_INTERRUPT" --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/da225/dsp/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/src" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2c/inc" --include_path="/ASRC/inc" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/i2s/build/Release" --preproc_with_compile --preproc_dependency="llc_i2s.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '



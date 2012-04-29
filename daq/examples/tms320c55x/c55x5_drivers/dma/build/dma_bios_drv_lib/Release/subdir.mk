################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/src/dda_dma.c \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/src/ddc_dma.c 

OBJS += \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/build/Release/dda_dma.obj \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/build/Release/ddc_dma.obj 

C_DEPS += \
./dda_dma.pp \
./ddc_dma.pp 

OBJS__QTD += \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\dma\build\Release\dda_dma.obj" \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\dma\build\Release\ddc_dma.obj" 

C_DEPS__QTD += \
".\dda_dma.pp" \
".\ddc_dma.pp" 

C_SRCS_QUOTED += \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/src/dda_dma.c" \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/src/ddc_dma.c" 


# Each subdirectory must supply rules for building sources it contributes
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/build/Release/dda_dma.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/src/dda_dma.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O3 --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/src" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/DA225/dsp/inc" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/build/Release" --preproc_with_compile --preproc_dependency="dda_dma.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/build/Release/ddc_dma.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/src/ddc_dma.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O3 --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/src" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/DA225/dsp/inc" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/dma/build/Release" --preproc_with_compile --preproc_dependency="ddc_dma.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '



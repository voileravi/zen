################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osCache.c \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osList.c \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osMem.c \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osprotect.c \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osSem.c \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osTime.c \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osWait.c 

OBJS += \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osCache.obj \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osList.obj \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osMem.obj \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osprotect.obj \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osSem.obj \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osTime.obj \
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osWait.obj 

C_DEPS += \
./pal_osCache.pp \
./pal_osList.pp \
./pal_osMem.pp \
./pal_osProtect.pp \
./pal_osSem.pp \
./pal_osTime.pp \
./pal_osWait.pp 

OBJS__QTD += \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\pal_os\build\Release\pal_osCache.obj" \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\pal_os\build\Release\pal_osList.obj" \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\pal_os\build\Release\pal_osMem.obj" \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\pal_os\build\Release\pal_osprotect.obj" \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\pal_os\build\Release\pal_osSem.obj" \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\pal_os\build\Release\pal_osTime.obj" \
"C:\Research\audioUsb_1_52_01_00\c55_caf\c55x5_drivers\pal_os\build\Release\pal_osWait.obj" 

C_DEPS__QTD += \
".\pal_osCache.pp" \
".\pal_osList.pp" \
".\pal_osMem.pp" \
".\pal_osProtect.pp" \
".\pal_osSem.pp" \
".\pal_osTime.pp" \
".\pal_osWait.pp" 

C_SRCS_QUOTED += \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osCache.c" \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osList.c" \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osMem.c" \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osprotect.c" \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osSem.c" \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osTime.c" \
"C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osWait.c" 


# Each subdirectory must supply rules for building sources it contributes
C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osCache.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osCache.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O2 --define="BIOS_BUILD" --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/da225/dsp/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release" --preproc_with_compile --preproc_dependency="pal_osCache.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osList.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osList.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O2 --define="BIOS_BUILD" --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/da225/dsp/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release" --preproc_with_compile --preproc_dependency="pal_osList.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osMem.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osMem.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O2 --define="BIOS_BUILD" --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/da225/dsp/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release" --preproc_with_compile --preproc_dependency="pal_osMem.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osprotect.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osprotect.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O2 --define="BIOS_BUILD" --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/da225/dsp/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release" --preproc_with_compile --preproc_dependency="pal_osProtect.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osSem.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osSem.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O2 --define="BIOS_BUILD" --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/da225/dsp/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release" --preproc_with_compile --preproc_dependency="pal_osSem.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osTime.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osTime.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O2 --define="BIOS_BUILD" --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/da225/dsp/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release" --preproc_with_compile --preproc_dependency="pal_osTime.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release/pal_osWait.obj: C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src/pal_osWait.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/bin/cl55" -vcpu:3.3 -g -O2 --define="BIOS_BUILD" --include_path="C:/Program Files/Texas Instruments/C5500 Code Generation Tools 4.3.9/include" --include_path="" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files/Texas Instruments/xdais_6_25_01_08/packages/ti/xdais" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/soc/da225/dsp/inc" --include_path="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/src/bios/src" --diag_warning=225 --large_memory_model --obj_directory="C:/Research/audioUsb_1_52_01_00/c55_caf/c55x5_drivers/pal_os/build/Release" --preproc_with_compile --preproc_dependency="pal_osWait.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
bsp.obj: ../bsp.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="c:/project/daq/examples/tms320c55x/c55xx_csl/inc" --include_path="c:/project/daq/ports/tms320c55x/qk/c5500" --include_path="c:/project/daq/include" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="bsp.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

i2s.obj: ../i2s.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="c:/project/daq/examples/tms320c55x/c55xx_csl/inc" --include_path="c:/project/daq/ports/tms320c55x/qk/c5500" --include_path="c:/project/daq/include" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="i2s.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="c:/project/daq/examples/tms320c55x/c55xx_csl/inc" --include_path="c:/project/daq/ports/tms320c55x/qk/c5500" --include_path="c:/project/daq/include" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

usb.obj: ../usb.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="c:/project/daq/examples/tms320c55x/c55xx_csl/inc" --include_path="c:/project/daq/ports/tms320c55x/qk/c5500" --include_path="c:/project/daq/include" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="usb.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



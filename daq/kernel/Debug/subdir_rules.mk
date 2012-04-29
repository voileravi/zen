################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
TEST.obj: C:/project/daq/kernel/TEST.C $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="TEST.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

autoinit.obj: C:/project/daq/kernel/autoinit.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="autoinit.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

boot.obj: C:/project/daq/kernel/boot.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="boot.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

core.obj: C:/project/daq/kernel/core.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="core.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cpu_a.obj: C:/project/daq/kernel/cpu_a.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="cpu_a.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cpu_c.obj: C:/project/daq/kernel/cpu_c.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="cpu_c.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

dbg_r.obj: C:/project/daq/kernel/dbg_r.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="dbg_r.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

demo.obj: C:/project/daq/kernel/demo.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="demo.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

flag.obj: C:/project/daq/kernel/flag.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="flag.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mbox.obj: C:/project/daq/kernel/mbox.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="mbox.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mem.obj: C:/project/daq/kernel/mem.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="mem.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mutex.obj: C:/project/daq/kernel/mutex.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="mutex.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

queue.obj: C:/project/daq/kernel/queue.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="queue.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

sem.obj: C:/project/daq/kernel/sem.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="sem.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

task.obj: C:/project/daq/kernel/task.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="task.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

time.obj: C:/project/daq/kernel/time.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="time.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

tmr.obj: C:/project/daq/kernel/tmr.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="tmr.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

util.obj: C:/project/daq/kernel/util.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="util.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

zen.obj: C:/project/daq/kernel/zen.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/bin/cl55" -g --include_path="C:/Program Files/Texas Instruments/ccsv5/ccsv5/tools/compiler/c5500/include" --include_path="C:/project/daq/kernel/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="zen.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



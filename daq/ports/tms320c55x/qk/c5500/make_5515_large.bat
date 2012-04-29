@echo off
:: ==========================================================================
:: Product: QP/C buld script for TMS320C55x, QK port, C5500-compiler
:: Last Updated for Version: 4.4.00
:: Date of the Last Update:  Feb 22, 2012
::
::                    Q u a n t u m     L e a P s
::                    ---------------------------
::                    innovating embedded systems
::
:: Copyright (C) 2002-2012 Quantum Leaps, LLC. All rights reserved.
::
:: This software may be distributed and modified under the terms of the GNU
:: General Public License version 2 (GPL) as published by the Free Software
:: Foundation and appearing in the file GPL.TXT included in the packaging of
:: this file. Please note that GPL Section 2[b] requires that all works based
:: on this software must also be made publicly available under the terms of
:: the GPL ("Copyleft").
::
:: Alternatively, this software may be distributed and modified under the
:: terms of Quantum Leaps commercial licenses, which expressly supersede
:: the GPL and are specifically designed for licensees interested in
:: retaining the proprietary status of their code.
::
:: Contact information:
:: Quantum Leaps Web site:  http://www.quantum-leaps.com
:: e-mail:                  info@quantum-leaps.com
:: ==========================================================================
setlocal

:: adjust the following path to the location where you've installed
:: the TI CodeComposer/C5500 toolset...
::
set TI_C5500=C:\Program Files\Texas Instruments\ccsv5\ccsv5\tools\compiler\c5500


:: Typically, you don't need to modify this file past this line -------------

set PATH=%TI_C5500%\bin;%PATH%

set CC=cl55
set ASM=acp55
set LIB=ar55

set QP_INCDIR=..\..\..\..\include
set QP_PRTDIR=.

:: Specify TMS320Cxx architecture
set TMS320_VER=5515

:: Specify memory model
set MEM_MODEL=large

if "%1"=="" (
    echo default selected
    set BINDIR=dbg
    set CCFLAGS=-v%TMS320_VER% --memory_model=%MEM_MODEL% -g --include_path="%TI_C5500%\include"
)
if "%1"=="rel" (
    echo rel selected
    set BINDIR=rel
    set CCFLAGS=-v%TMS320_VER% --memory_model=%MEM_MODEL% -oi0 --define=NDEBUG --include_path="%TI_C5500%\include"
)
if "%1"=="spy" (
    echo spy selected
    set BINDIR=spy
    set CCFLAGS=-v%TMS320_VER% --memory_model=%MEM_MODEL% -g --define=Q_SPY --include_path="%TI_C5500%\include"
)

set LIBDIR=%BINDIR%
set LIBFLAGS=a

erase %BINDIR%\qp%TMS320_VER%_%MEM_MODEL%.lib

:: QEP ----------------------------------------------------------------------
set SRCDIR=..\..\..\..\qep\source
set CCINC=--include_path=%QP_PRTDIR% --include_path=%QP_INCDIR% --include_path=%SRCDIR%

@echo on
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qep.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qfsm_ini.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qfsm_dis.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qhsm_ini.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qhsm_dis.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qhsm_top.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qhsm_in.c 

%LIB% %LIBFLAGS% %LIBDIR%\qp%TMS320_VER%_%MEM_MODEL%.lib %BINDIR%\qep.obj %BINDIR%\qfsm_ini.obj %BINDIR%\qfsm_dis.obj %BINDIR%\qhsm_ini.obj %BINDIR%\qhsm_dis.obj %BINDIR%\qhsm_top.obj %BINDIR%\qhsm_in.obj
@echo off

:: QF -----------------------------------------------------------------------
set SRCDIR=..\..\..\..\qf\source
set CCINC=--include_path=%QP_PRTDIR% --include_path=%QP_INCDIR% --include_path=%SRCDIR%

@echo on
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qa_defer.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qa_fifo.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qa_lifo.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qa_get_.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qa_sub.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qa_usub.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qa_usuba.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qeq_fifo.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qeq_get.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qeq_init.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qeq_lifo.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qf_act.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qf_gc.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qf_log2.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qf_new.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qf_pool.c
::%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qf_psini.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qf_pspub.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qf_pwr2.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qf_tick.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qmp_get.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qmp_init.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qmp_put.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qte_ctor.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qte_arm.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qte_darm.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qte_rarm.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qte_ctr.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" src\qf_port.c

%LIB% %LIBFLAGS% %LIBDIR%\qp%TMS320_VER%_%MEM_MODEL%.lib %BINDIR%\qa_defer.obj %BINDIR%\qa_fifo.obj %BINDIR%\qa_lifo.obj %BINDIR%\qa_get_.obj %BINDIR%\qa_sub.obj %BINDIR%\qa_usub.obj %BINDIR%\qa_usuba.obj %BINDIR%\qeq_fifo.obj %BINDIR%\qeq_get.obj %BINDIR%\qeq_init.obj %BINDIR%\qeq_lifo.obj %BINDIR%\qf_act.obj %BINDIR%\qf_gc.obj %BINDIR%\qf_log2.obj %BINDIR%\qf_new.obj %BINDIR%\qf_pool.obj %BINDIR%\qf_pspub.obj %BINDIR%\qf_pwr2.obj %BINDIR%\qf_tick.obj %BINDIR%\qmp_get.obj %BINDIR%\qmp_init.obj %BINDIR%\qmp_put.obj %BINDIR%\qte_ctor.obj %BINDIR%\qte_arm.obj %BINDIR%\qte_darm.obj %BINDIR%\qte_rarm.obj %BINDIR%\qte_ctr.obj %BINDIR%\qf_port.obj
@echo off

:: QK -----------------------------------------------------------------------
set SRCDIR=..\..\..\..\qk\source
set CCINC=--include_path=%QP_PRTDIR% --include_path=%QP_INCDIR% --include_path=%SRCDIR%

@echo on
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qk.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qk_sched.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qk_mutex.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" src\qk_port.c

%LIB% %LIBFLAGS% %LIBDIR%\qp%TMS320_VER%_%MEM_MODEL%.lib %BINDIR%\qk.obj %BINDIR%\qk_sched.obj %BINDIR%\qk_mutex.obj %BINDIR%\qk_port.obj
@echo off

:: QS -----------------------------------------------------------------------
if not "%1"=="spy" goto clean

set SRCDIR=..\..\..\..\qs\source
set CCINC=--include_path=%QP_PRTDIR% --include_path=%QP_INCDIR% --include_path=%SRCDIR%

@echo on
::%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qs.c
::%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qs_.c
::%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qs_blk.c
::%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qs_byte.c
::%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qs_f32.c
::%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qs_f64.c
::%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qs_mem.c
::%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" %SRCDIR%\qs_str.c
%CC% %CCFLAGS% %CCINC% --obj_directory="%QP_PRTDIR%\%BINDIR%" src\qs_port.c

%LIB% %LIBFLAGS% %LIBDIR%\qp%TMS320_VER%_%MEM_MODEL%.lib %BINDIR%\qs_port.obj
@echo off

:: --------------------------------------------------------------------------

:clean
@echo off

erase %BINDIR%\*.obj

endlocal
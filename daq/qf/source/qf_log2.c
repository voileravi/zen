/*****************************************************************************
* Product: QF/C
* Last Updated for Version: 4.4.00
* Date of the Last Update:  Jan 05, 2012
*
*                    Q u a n t u m     L e a P s
*                    ---------------------------
*                    innovating embedded systems
*
* Copyright (C) 2002-2012 Quantum Leaps, LLC. All rights reserved.
*
* This software may be distributed and modified under the terms of the GNU
* General Public License version 2 (GPL) as published by the Free Software
* Foundation and appearing in the file GPL.TXT included in the packaging of
* this file. Please note that GPL Section 2[b] requires that all works based
* on this software must also be made publicly available under the terms of
* the GPL ("Copyleft").
*
* Alternatively, this software may be distributed and modified under the
* terms of Quantum Leaps commercial licenses, which expressly supersede
* the GPL and are specifically designed for licensees interested in
* retaining the proprietary status of their code.
*
* Contact information:
* Quantum Leaps Web site:  http://www.quantum-leaps.com
* e-mail:                  info@quantum-leaps.com
*****************************************************************************/
#include "qf_pkg.h"

/**
* \file
* \ingroup qf
* \brief QF_log2Lkup[] definition.
*/

/* Global objects ----------------------------------------------------------*/
uint8_t const Q_ROM Q_ROM_VAR QF_log2Lkup[256] = {
    (uint8_t)0, (uint8_t)1, (uint8_t)2, (uint8_t)2,
    (uint8_t)3, (uint8_t)3, (uint8_t)3, (uint8_t)3,
    (uint8_t)4, (uint8_t)4, (uint8_t)4, (uint8_t)4,
    (uint8_t)4, (uint8_t)4, (uint8_t)4, (uint8_t)4,
    (uint8_t)5, (uint8_t)5, (uint8_t)5, (uint8_t)5,
    (uint8_t)5, (uint8_t)5, (uint8_t)5, (uint8_t)5,
    (uint8_t)5, (uint8_t)5, (uint8_t)5, (uint8_t)5,
    (uint8_t)5, (uint8_t)5, (uint8_t)5, (uint8_t)5,
    (uint8_t)6, (uint8_t)6, (uint8_t)6, (uint8_t)6,
    (uint8_t)6, (uint8_t)6, (uint8_t)6, (uint8_t)6,
    (uint8_t)6, (uint8_t)6, (uint8_t)6, (uint8_t)6,
    (uint8_t)6, (uint8_t)6, (uint8_t)6, (uint8_t)6,
    (uint8_t)6, (uint8_t)6, (uint8_t)6, (uint8_t)6,
    (uint8_t)6, (uint8_t)6, (uint8_t)6, (uint8_t)6,
    (uint8_t)6, (uint8_t)6, (uint8_t)6, (uint8_t)6,
    (uint8_t)6, (uint8_t)6, (uint8_t)6, (uint8_t)6,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)7, (uint8_t)7, (uint8_t)7, (uint8_t)7,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8,
    (uint8_t)8, (uint8_t)8, (uint8_t)8, (uint8_t)8
};

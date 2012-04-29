/*****************************************************************************
* Product: QK/C
* Last Updated for Version: 4.4.00
* Date of the Last Update:  Jan 04, 2012
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
#ifndef qk_pkg_h
#define qk_pkg_h

/**
* \file
* \ingroup qk
* \brief Internal (package scope) QK/C interface.
*/

#include "qf_port.h"                 /* QF port include; includes qk_port.h */

                                            /* QF-specific critical section */
#ifndef QF_CRIT_STAT_TYPE
    /** \brief This is an internal macro for defining the critical section
    * status type.
    *
    * The purpose of this macro is to enable writing the same code for the
    * case when critical sectgion status type is defined and when it is not.
    * If the macro #QF_CRIT_STAT_TYPE is defined, this internal macro
    * provides the definition of the critical section status varaible.
    * Otherwise this macro is empty.
    * \sa #QF_CRIT_STAT_TYPE
    */
    #define QF_CRIT_STAT_

    /** \brief This is an internal macro for entering a critical section.
    *
    * The purpose of this macro is to enable writing the same code for the
    * case when critical sectgion status type is defined and when it is not.
    * If the macro #QF_CRIT_STAT_TYPE is defined, this internal macro
    * invokes #QF_CRIT_ENTRY passing the key variable as the parameter.
    * Otherwise #QF_CRIT_ENTRY is invoked with a dummy parameter.
    * \sa #QF_CRIT_ENTRY
    */
    #define QF_CRIT_ENTRY_()    QF_CRIT_ENTRY(dummy)

    /** \brief This is an internal macro for exiting a cricial section.
    *
    * The purpose of this macro is to enable writing the same code for the
    * case when critical sectgion status type is defined and when it is not.
    * If the macro #QF_CRIT_STAT_TYPE is defined, this internal macro
    * invokes #QF_CRIT_EXIT passing the key variable as the parameter.
    * Otherwise #QF_CRIT_EXIT is invoked with a dummy parameter.
    * \sa #QF_CRIT_EXIT
    */
    #define QF_CRIT_EXIT_()     QF_CRIT_EXIT(dummy)

#else
    #define QF_CRIT_STAT_       QF_CRIT_STAT_TYPE critStat_;
    #define QF_CRIT_ENTRY_()    QF_CRIT_ENTRY(critStat_)
    #define QF_CRIT_EXIT_()     QF_CRIT_EXIT(critStat_)
#endif
                          /* define for backwards compatibility, see NOTE01 */
#ifndef QF_CRIT_STAT_TYPE
#if !defined(QF_INT_DISABLE) && defined(QF_CRIT_ENTRY)
    #define QF_INT_DISABLE()    QF_CRIT_ENTRY(dummy)
#endif
#if !defined(QF_INT_ENABLE) && defined(QF_CRIT_EXIT)
    #define QF_INT_ENABLE()     QF_CRIT_EXIT(dummy)
#endif
#endif                                                 /* QF_CRIT_STAT_TYPE */

                                                /* package-scope objects... */
#ifndef QK_NO_MUTEX
    extern uint8_t QK_ceilingPrio_;          /**< QK mutex priority ceiling */
#endif

/*****************************************************************************
* NOTE01: For older QK ports that used the simple "unconditional interrupt
* locking and unlocking" policy, the interrupt disabling and enabling can be
* derived from the critical section definition.
*/

#endif                                                          /* qk_pkg_h */

/****************************************************************************/
/* QS software tracing integration, only if enabled                         */
#ifdef Q_SPY                                /* QS software tracing enabled? */
    #ifndef qs_h
    #include "qs_port.h"                                 /* include QS port */
    #endif                                                          /* qs_h */
#else
    #ifndef qs_dummy_h
    #include "qs_dummy.h"                /* disable the QS software tracing */
    #endif
#endif                                                             /* Q_SPY */

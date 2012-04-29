/*****************************************************************************
* Product: QF/C
* Last Updated for Version: 4.4.00
* Date of the Last Update:  Jan 15, 2012
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
#include "qassert.h"

Q_DEFINE_THIS_MODULE("qf_gc")

/**
* \file
* \ingroup qf
* \brief QF_gc() implementation.
*/

/*..........................................................................*/
void QF_gc(QEvent const *e) {
    if (QF_EVT_POOL_ID_(e) != (uint8_t)0) {       /* is it a dynamic event? */
        QF_CRIT_STAT_
        QF_CRIT_ENTRY_();

        if (QF_EVT_REF_CTR_(e) > (uint8_t)1) {  /* isn't this the last ref? */
            QF_EVT_REF_CTR_DEC_(e);            /* decrement the ref counter */

            QS_BEGIN_NOCRIT_(QS_QF_GC_ATTEMPT, (void *)0, (void *)0)
                QS_TIME_();                                    /* timestamp */
                QS_SIG_(e->sig);                 /* the signal of the event */
                QS_U8_(QF_EVT_POOL_ID_(e));     /* the pool Id of the event */
                QS_U8_(QF_EVT_REF_CTR_(e));   /* the ref count of the event */
            QS_END_NOCRIT_()

            QF_CRIT_EXIT_();
        }
        else {      /* this is the last reference to this event, recycle it */
                                                      /* cannot wrap around */
            uint8_t idx = (uint8_t)(QF_EVT_POOL_ID_(e) - (uint8_t)1);

            QS_BEGIN_NOCRIT_(QS_QF_GC, (void *)0, (void *)0)
                QS_TIME_();                                    /* timestamp */
                QS_SIG_(e->sig);                 /* the signal of the event */
                QS_U8_(QF_EVT_POOL_ID_(e));     /* the pool Id of the event */
                QS_U8_(QF_EVT_REF_CTR_(e));   /* the ref count of the event */
            QS_END_NOCRIT_()

            QF_CRIT_EXIT_();

            Q_ASSERT(idx < QF_maxPool_);

            QF_EPOOL_PUT_(QF_pool_[idx], (QEvent *)e);  /* cast const away, */
                          /* which is legitimate, because it's a pool event */
        }
    }
}

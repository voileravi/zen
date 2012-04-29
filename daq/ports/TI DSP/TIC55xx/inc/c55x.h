/*****************************************************************************/
/*  C55X.H v2.55                                                            */
/*  Copyright (c) 2000-2002 Texas Instruments Incorporated                   */
/*****************************************************************************/

#ifndef _C55X
#define _C55X

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

int        _sadd    (int, int);
int        _a_sadd  (int, int);
long       _lsadd   (long, long);
long       _a_lsadd (long, long);
long long  _llsadd  (long long, long long);
long long  _a_llsadd(long long, long long);

int        _ssub   (int, int);
long       _lssub  (long, long);
long long  _llssub (long long, long long);

int        _sneg   (int);
long       _lsneg  (long);
long long  _llsneg (long long);

int        _abss   (int);
long       _labss  (long);
long long  _llabss (long long);

int        _smpy   (int, int);
long       _lsmpy  (int, int);
long       _smpyr  (int, int);

long       _smac   (long, int, int);
long       _a_smac (long, int, int);
long       _smacr  (long, int, int);
long       _a_smacr(long, int, int);
long       _smas   (long, int, int);
long       _a_smas (long, int, int);
long       _smasr  (long, int, int);
long       _a_smasr(long, int, int);

int        _sshl   (int, int);
long       _lsshl  (long, int);
int        _shrs   (int, int);
long       _lshrs  (long, int);

int        _shl    (int, int);
long       _lshl   (long, int);
long long  _llshl  (long long, int);

long       _round  (long);
long       _sround (long);
long       _roundn (long);
long       _sroundn(long);
long       _rnd    (long); /* old name for _sround */

int        _norm   (int);
int        _lnorm  (long);
long       _lsat   (long long);

int        _count  (unsigned long long, unsigned long long);

int        _max    (int, int);
long       _lmax   (long, long);
long long  _llmax  (long long, long long);
int        _min    (int, int);
long       _lmin   (long, long);
long long  _llmin  (long long, long long);

void       _enable_interrupts(void);
void       _disable_interrupts(void);

#ifdef __cplusplus
void       _firs        (int *, int *, int *, int&, long&);
void       _firsn       (int *, int *, int *, int&, long&);
void       _lms         (int *, int *, int&, long&);
void       _abdst       (int *, int *, int&, long&);
void       _sqdst       (int *, int *, int&, long&);
void       _max_diff_dbl(long, long, long&, long&, unsigned int&);
void       _min_diff_dbl(long, long, long&, long&, unsigned int&);
int        _exp_mant    (long, long&);
#endif /* __cplusplus */

   /* No C prototypes included for _firs, _firsn, _max_diff_dbl,
      min_diff_dbl, _lms, _abdst, _sqdst, _exp_mant, due to their
      having "pass-by-reference" parameters. */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* !_C55X */

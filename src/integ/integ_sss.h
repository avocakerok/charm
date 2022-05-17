/* This header file is not a part of API. */


#ifndef __INTEG_SSS_H__
#define __INTEG_SSS_H__


#include <config.h>
#include "../prec.h"


#ifdef __cplusplus
extern "C"
{
#endif


/**
 * Analytically computes the integral:
 *
 * \verbatim embed:rst:leading-asterisk
 *      .. math::
 *
 *          s = \int_{u_0}^{u_0 + \Delta
 *          u} \sin(a_1 \, u) \, \sin(a_2 \, u) \, \sin(u) \, \mathrm{d} u \,.
 *
 * \endverbatim
 *
 *
 * @param[in] u0 Lower integration limit for ``j = 0``.
 * @param[in] du Integration width.
 * @param[in] a1 Real number.
 * @param[in] a2 Real number.
 *
 * @return Value ``s`` of the integral.
 *
 * */
extern REAL CHARM(integ_sss)(REAL u0,
                             REAL du,
                             REAL a1,
                             REAL a2);


#ifdef __cplusplus
}
#endif


#endif

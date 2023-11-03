/* Header files */
/* ------------------------------------------------------------------------- */
#include <config.h>
#include <stdio.h>
#include "../prec.h"
#include "../simd/simd.h"
#include "../crd/crd_cell_isSctr.h"
/* ------------------------------------------------------------------------- */






void CHARM(shs_sctr_mulc)(size_t i, size_t n, int type, REAL_SIMD c,
                          REAL_SIMD tmp, REAL *tmpv, REAL_SIMD *fi, REAL *f)
{
    size_t ipv;
    size_t il;
    size_t simd_blk = CHARM(crd_cell_isSctr)(type) ? 1 : SIMD_BLOCK;


    for (size_t l = 0; l < simd_blk; l++)
    {
        il = i + l * SIMD_SIZE;
        tmp = MUL_R(c, fi[l]);
        if ((il + SIMD_SIZE) <= n)
            STOREU_R(&f[il], tmp);
        else
        {
            STORE_R(&tmpv[0], tmp);
            for (size_t v = 0; v < SIMD_SIZE; v++)
            {
                ipv = il + v;
                if (ipv < n)
                    f[ipv] = tmpv[v];
                else
                    continue;
            }
        }
    }


    return;
}

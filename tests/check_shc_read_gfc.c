/* Header files */
/* ------------------------------------------------------------------------- */
#include <config.h>
#include <stdio.h>
#include "../src/prec.h"
#include "validate.h"
#include "write.h"
#include "parameters.h"
#include "check_shc_read_gfc.h"
/* ------------------------------------------------------------------------- */






long int check_shc_read_gfc(void)
{
    CHARM(err) *err = CHARM(err_init)();
    if (err == NULL)
    {
        fprintf(stderr, "Failed to initialize an \"err\" structure.\n");
        exit(CHARM_FAILURE);
    }


    int long e = 0;
    char file_c[NSTR_LONG];
    char file_s[NSTR_LONG];


    CHARM(shc) *shcs = CHARM(shc_calloc)(SHCS_NMAX_POT, PREC(1.0), PREC(1.0));
    if (shcs == NULL)
    {
        fprintf(stderr, "Failed to initlize a \"shc\" structure");
        exit(CHARM_FAILURE);
    }


    char *stat = "static";
    char *tvg = "tvg";
    char *stat_tvg;
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
            CHARM(shc_read_gfc)(SHCS_IN_PATH_POT_GFC, SHCS_NMAX_POT, NULL,
                                shcs, err);
        else if (i == 1)
            CHARM(shc_read_gfc)(SHCS_IN_PATH_POT_GFC_TVG, SHCS_NMAX_POT,
                                TVG_EPOCH, shcs, err);
        CHARM(err_handler)(err, 1);


        if (i == 0)
            stat_tvg = stat;
        else if (i == 1)
            stat_tvg = tvg;


        sprintf(file_c, "%s/shc_nx%lu_c_gfc_%s%s",
                FOLDER, shcs->nmax, stat_tvg, FTYPE);
        sprintf(file_s, "%s/shc_nx%lu_s_gfc_%s%s",
                FOLDER, shcs->nmax, stat_tvg, FTYPE);


#ifdef GENREF
        e += write(file_c, shcs->c[0], shcs->nc);
        e += write(file_s, shcs->s[0], shcs->ns);
#else
        e += validate(file_c, shcs->c[0], shcs->nc,
                      PREC(10.0) * CHARM(glob_threshold));
        e += validate(file_s, shcs->s[0], shcs->ns,
                      PREC(10.0) * CHARM(glob_threshold));
#endif
    }
    /* --------------------------------------------------------------------- */


    /* --------------------------------------------------------------------- */
    CHARM(shc_free)(shcs);
    CHARM(err_free)(err);


    return e;
    /* --------------------------------------------------------------------- */
}

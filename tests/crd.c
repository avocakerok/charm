/* Header files */
/* ------------------------------------------------------------------------- */
#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _MSC_VER
#   define _USE_MATH_DEFINES
#endif
#include <math.h>
#include "../src/prec.h"
/* ------------------------------------------------------------------------- */






/* Function prototypes */
/* ------------------------------------------------------------------------- */
static int grids(CHARM(crd) *, REAL *, REAL *, REAL *, REAL *);
int cmp_arrays(REAL *, REAL *, size_t, REAL);
/* ------------------------------------------------------------------------- */






/* Function to test the "src" module */
/* ------------------------------------------------------------------------- */
int crd(unsigned long nmax)
{
    /* --------------------------------------------------------------------- */
    if (nmax != 4)
    {
        fprintf(stderr, "\"nmax\" has to be \"4\".\n");
        exit(CHARM_FAILURE);
    }
    /* --------------------------------------------------------------------- */






    /* Reference values for the Gauss--Legendre grid */
    /* --------------------------------------------------------------------- */
    REAL glg_ref_lats[5] = {
                              ADDP( 1.1341613775693744571938561048112866e+00),
                              ADDP( 5.6861952315177497748140627112297054e-01),
                              ADDP( 0.0000000000000000000000000000000000e+00),
                              ADDP(-5.6861952315177497748140627112297054e-01),
                              ADDP(-1.1341613775693744571938561048112866e+00)};


    REAL glg_ref_lons[10] = {
                             ADDP(0.0000000000000000000000000000000000e+00),
                             ADDP(6.2831853071795864769252867665590058e-01),
                             ADDP(1.2566370614359172953850573533118012e+00),
                             ADDP(1.8849555921538759430775860299677018e+00),
                             ADDP(2.5132741228718345907701147066236023e+00),
                             ADDP(3.1415926535897932384626433832795028e+00),
                             ADDP(3.7699111843077518861551720599354037e+00),
                             ADDP(4.3982297150257105338477007365913038e+00),
                             ADDP(5.0265482457436691815402294132472046e+00),
                             ADDP(5.6548667764616278292327580899031055e+00)};


    REAL glg_ref_r[5] = {
                         ADDP(1.0),
                         ADDP(1.0),
                         ADDP(1.0),
                         ADDP(1.0),
                         ADDP(1.0)};


    REAL glg_ref_weights[5] = {
                              ADDP(2.3692688505618908751426404071991702e-01),
                              ADDP(4.7862867049936646804129151483563827e-01),
                              ADDP(5.6888888888888888888888888888888889e-01),
                              ADDP(4.7862867049936646804129151483563827e-01),
                              ADDP(2.3692688505618908751426404071991702e-01)};
    /* --------------------------------------------------------------------- */






    /* Reference values for the dhg1 grid */
    /* --------------------------------------------------------------------- */
    REAL dhg1_ref_lats[10] = {
                              ADDP( 1.5707963267948966192313216916397514e+00),
                              ADDP( 1.2566370614359172953850573533118012e+00),
                              ADDP( 9.4247779607693797153879301498385082e-01),
                              ADDP( 6.2831853071795864769252867665590048e-01),
                              ADDP( 3.1415926535897932384626433832795024e-01),
                              ADDP( 0.0000000000000000000000000000000000e+00),
                              ADDP(-3.1415926535897932384626433832795043e-01),
                              ADDP(-6.2831853071795864769252867665590048e-01),
                              ADDP(-9.4247779607693797153879301498385092e-01),
                              ADDP(-1.2566370614359172953850573533118014e+00)};


    REAL dhg1_ref_lons[10] = {
                             ADDP(0.0000000000000000000000000000000000e+00),
                             ADDP(6.2831853071795864769252867665590058e-01),
                             ADDP(1.2566370614359172953850573533118012e+00),
                             ADDP(1.8849555921538759430775860299677018e+00),
                             ADDP(2.5132741228718345907701147066236023e+00),
                             ADDP(3.1415926535897932384626433832795028e+00),
                             ADDP(3.7699111843077518861551720599354037e+00),
                             ADDP(4.3982297150257105338477007365913038e+00),
                             ADDP(5.0265482457436691815402294132472046e+00),
                             ADDP(5.6548667764616278292327580899031055e+00)};


    REAL dhg1_ref_r[10] = {
                           ADDP(1.0),
                           ADDP(1.0),
                           ADDP(1.0),
                           ADDP(1.0),
                           ADDP(1.0),
                           ADDP(1.0),
                           ADDP(1.0),
                           ADDP(1.0),
                           ADDP(1.0),
                           ADDP(1.0)};


    REAL dhg1_ref_weights[10] = {
                              ADDP(0.0000000000000000000000000000000000e+00),
                              ADDP(1.1478107508572176317529287273082451e-01),
                              ADDP(1.6543319422222756326579876396872944e-01),
                              ADDP(2.7379035348570680825327855584060420e-01),
                              ADDP(2.7901125022221688117864568047571498e-01),
                              ADDP(3.3396825396825396825396825396825402e-01),
                              ADDP(2.7901125022221688117864568047571493e-01),
                              ADDP(2.7379035348570680825327855584060415e-01),
                              ADDP(1.6543319422222756326579876396872952e-01),
                              ADDP(1.1478107508572176317529287273082438e-01)};
    /* --------------------------------------------------------------------- */






    /* Reference values for the DH1 grid */
    /* --------------------------------------------------------------------- */
    REAL dhg2_ref_lons[20] = {
                             ADDP(0.0000000000000000000000000000000000e+00),
                             ADDP(3.1415926535897932384626433832795029e-01),
                             ADDP(6.2831853071795864769252867665590058e-01),
                             ADDP(9.4247779607693797153879301498385092e-01),
                             ADDP(1.2566370614359172953850573533118012e+00),
                             ADDP(1.5707963267948966192313216916397514e+00),
                             ADDP(1.8849555921538759430775860299677018e+00),
                             ADDP(2.1991148575128552669238503682956519e+00),
                             ADDP(2.5132741228718345907701147066236023e+00),
                             ADDP(2.8274333882308139146163790449515527e+00),
                             ADDP(3.1415926535897932384626433832795028e+00),
                             ADDP(3.4557519189487725623089077216074532e+00),
                             ADDP(3.7699111843077518861551720599354037e+00),
                             ADDP(4.0840704496667312100014363982633541e+00),
                             ADDP(4.3982297150257105338477007365913038e+00),
                             ADDP(4.7123889803846898576939650749192542e+00),
                             ADDP(5.0265482457436691815402294132472046e+00),
                             ADDP(5.3407075111026485053864937515751551e+00),
                             ADDP(5.6548667764616278292327580899031055e+00),
                             ADDP(5.9690260418206071530790224282310552e+00)};


    /* The rest is just the same as "dhg1_ref_*". */
    /* --------------------------------------------------------------------- */






    /* Initialize an error structure to be used throughout the function */
    /* --------------------------------------------------------------------- */
    CHARM(err) *err = CHARM(err_init)();
    if (err == NULL)
    {
        fprintf(stderr, "Failed to initialize an \"err\" structure.\n");
        exit(CHARM_FAILURE);
    }
    /* --------------------------------------------------------------------- */






    /* Gauss--Legendre */
    /* --------------------------------------------------------------------- */
    printf("    Initializing the Gauss--Legendre grid...\n");
    CHARM(crd) *glg = CHARM(crd_gl)(nmax, ADDP(1.0));
    if (glg == NULL)
    {
        fprintf(stderr, "Failed to initialize the Gauss--Legendre "
                        "grid.\n");
        exit(CHARM_FAILURE);
    }


    int errnum = 0;
    printf("    Accuracy test of the Gauss--Legendre grid...\n");
    errnum += grids(glg, glg_ref_lats, glg_ref_lons, glg_ref_r,
                    glg_ref_weights);
    /* --------------------------------------------------------------------- */






    /* Driscoll--Healy DH1 */
    /* --------------------------------------------------------------------- */
    printf("    Initializing the Driscoll--Healy grid (DH1)...\n");
    CHARM(crd) *dhg1 = CHARM(crd_dh1)(nmax, ADDP(1.0));
    if (dhg1 == NULL)
    {
        fprintf(stderr, "Failed to initialize the Driscoll--Healy "
                        "grid (DH1).\n");
        exit(CHARM_FAILURE);
    }


    printf("    Accuracy test of the Driscoll--Healy grid (DH1)...\n");
    errnum += grids(dhg1, dhg1_ref_lats, dhg1_ref_lons, dhg1_ref_r,
                         dhg1_ref_weights);
    /* --------------------------------------------------------------------- */






    /* Driscoll--Healy DH2 */
    /* --------------------------------------------------------------------- */
    printf("    Initializing the Driscoll--Healy grid (DH2)...\n");
    CHARM(crd) *dhg2 = CHARM(crd_dh2)(nmax, ADDP(1.0));
    if (dhg2 == NULL)
    {
        fprintf(stderr, "Failed to initialize the Driscoll--Healy "
                        "grid (DH2).\n");
        exit(CHARM_FAILURE);
    }


    printf("    Accuracy test of the Driscoll--Healy grid (DH2)...\n");
    errnum += grids(dhg2, dhg1_ref_lats, dhg2_ref_lons, dhg1_ref_r,
                    dhg1_ref_weights);
    /* --------------------------------------------------------------------- */






    /* --------------------------------------------------------------------- */
    CHARM(err_free)(err);
    printf("    Freeing \"crd\" structures...\n");
    CHARM(crd_free)(glg);
    CHARM(crd_free)(dhg1);
    CHARM(crd_free)(dhg2);


    return errnum;
    /* --------------------------------------------------------------------- */
}
/* ------------------------------------------------------------------------- */






/* ------------------------------------------------------------------------- */
static int grids(CHARM(crd) *grd, REAL *grd_ref_lats,
                 REAL *grd_ref_lons, REAL *grd_ref_r,
                 REAL *grd_ref_weights)
{
    int errnum = 0;


    errnum += cmp_arrays(grd->lat, grd_ref_lats, grd->nlat,
                         CHARM(glob_threshold));
    errnum += cmp_arrays(grd->lon, grd_ref_lons, grd->nlon,
                         CHARM(glob_threshold));
    errnum += cmp_arrays(grd->r, grd_ref_r, grd->nlat,
                         CHARM(glob_threshold));
    errnum += cmp_arrays(grd->w, grd_ref_weights, grd->nlat,
                         CHARM(glob_threshold));


    return errnum;
}
/* ------------------------------------------------------------------------- */

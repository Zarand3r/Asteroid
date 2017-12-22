/*  Header file for the ABC (Asteroid Brightness in CUDA) project
 */

#ifndef ASTEROID_H
#define ASTEROID_H
#include <stdio.h>

// Constants:
// Number of free parameters for chi^2 (excludes filters):
const int N_PARAMS = 7;
// Number of points for phi_a parameter (phase shift):
const int N_PHI_A = 360*4;



// Maximum number of chars in a file name:
const int MAX_FILE_NAME = 256;
// Maximum number of chars in one line of a data file:
const int MAX_LINE_LENGTH = 128;
// Maximum number of filters:
const int MAX_FILTERS = 100;

// Speed of light (au/day):
const double light_speed = 173.144632674;
const double Pi = acos(-1.0);
const double Rad = 180.0 / Pi;

#define PI 3.141592653589793238L
#define RAD 180.0L / PI

// Function declarations
int read_data(char *, int *, int *);
int chi2 (int, int, double *);
int quadratic_interpolation(double, double *,double *,double *, double *,double *,double *);





// Global variables
#ifdef MAIN
// If called from main(), global variables are defined:
#define EXTERN
#else
// Otherwise, global variables are declared with "extern"
#define EXTERN extern
#endif

EXTERN char all_filters[MAX_FILTERS];

// Observational data arrays:
struct obs_data {
double V;  // visual magnitude array, mag
double w;  // 1-sgm error bar squared for V array, mag
double E_x;  // asteroid->Earth vector in barycentric FoR array, au
double E_y;  // asteroid->Earth vector in barycentric FoR array, au
double E_z;  // asteroid->Earth vector in barycentric FoR array, au
double S_x;  // asteroid->Sun vector in barycentric FoR array, au
double S_y;  // asteroid->Sun vector in barycentric FoR array, au
double S_z;  // asteroid->Sun vector in barycentric FoR array, au
double MJD;  // asteroid time (without time delay)
int Filter;  // Filter code array

};

EXTERN struct obs_data *hData;

// CUDA version of the data:
EXTERN struct obs_data *dData;

// Arrays used for ephemerides interpolation:
EXTERN double E_x0[3],E_y0[3],E_z0[3], S_x0[3],S_y0[3],S_z0[3], MJD0[3];    
EXTERN double *MJD_obs;  // observational time (with light delay)
EXTERN double hMJD0;

#endif





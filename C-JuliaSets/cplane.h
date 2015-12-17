#include "complex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXITER 256

//define structure cplane --> CPLANE
typedef struct cplane
{
	long double xmin;
	long double xmax;
	long double ymin;
	long double ymax;
	unsigned long int xpoints;
	unsigned long int ypoints;

	COMPLEX **mat;

} CPLANE;

//function definitions
CPLANE cplane_setting(const long double xmin, const long double xmax, const long double ymin, const long double ymax, const unsigned long int xpoints, const unsigned long int ypoints);
int iterate(COMPLEX *z, COMPLEX *c);
void cplane_iterate(CPLANE *p, COMPLEX *c);



include "complex.h"
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
COMPLEX cplane_setting(const long double xmin, const long double xmax, const long double ymin, const long double ymax, const unsigned long int xpoints, const unsigned long int ypoints);
COMPLEX mult2(const COMPLEX *, const COMPLEX *);
COMPLEX square(const COMPLEX *);
COMPLEX add2(const COMPLEX *, const COMPLEX *);
COMPLEX juliamap(const COMPLEX *, const COMPLEX *);
char * complex_print(const COMPLEX z);
char * test(const COMPLEX *a, const COMPLEX *b);
int iterate(COMPLEX z, COMPLEX c);
void cplane_iterate(CPLANE cp, COMPLEX c);


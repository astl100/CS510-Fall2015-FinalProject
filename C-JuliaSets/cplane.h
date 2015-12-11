#include "complex.h"

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
COMPLEX mult2(const COMPLEX *, const COMPLEX *);
COMPLEX square(const COMPLEX *);
COMPLEX add2(const COMPLEX *, const COMPLEX *);
COMPLEX juliamap(const COMPLEX *, const COMPLEX *);
char * complex_print(const COMPLEX z);
char * test(const COMPLEX *a, const COMPLEX *b);

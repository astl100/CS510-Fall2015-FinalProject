
#include "complex.h"

//functions
COMPLEX complex_setting(const long double x, const long double y)
{
	COMPLEX a;
	a.x = x;
	a.y = y;
	return a;
}
    
COMPLEX mult2(const COMPLEX *a, const COMPLEX *b)
    {
        COMPLEX c;
        c.x = (*a).x*(*b).x - (*a).y*(*b).y;
      	c.y = (*a).x*(*b).x + (*a).x*(*b).y;
    	return (c);
    }
    
COMPLEX square(const COMPLEX *a)
    {
        COMPLEX b;
        b.x = (*a).x*(*a).x + (*a).y*(*a).y*(-1);
      	b.y = (*a).x*(*a).y;
    	return b;
    }

COMPLEX add2(const COMPLEX *a, const COMPLEX *b)
    {
        COMPLEX c;
    	c.x = (*a).x + (*b).x;
        c.y = (*a).y + (*b).y;
    	return c;
    }
	
COMPLEX juliamap(const COMPLEX *z, const COMPLEX *c)
    {
        COMPLEX b,m;
	    m = square(z);
    	b = add2(&m, c);
    	return b;
    }

char * complex_print(const COMPLEX z)
	{
    	printf ("z = %Lg + %Le i \n", z.x, z.y);
    	return 0;
	}

char * test(const COMPLEX *a, const COMPLEX *b)
{
	printf("Initial Complex 1: ");
	complex_print(*a);
	printf("\nInitial Complex 2: ");
        complex_print(*b);


	COMPLEX c;
	c = mult2(a, b);
	printf("\nMultiply: ");
	complex_print(c);

	COMPLEX d;
	d = square(a);
	printf ("\nSquare: ");
	complex_print(d);

	COMPLEX f;
	f = add2(a, b);
	printf ("\nAddition: ");
	complex_print(f);

	COMPLEX e;
	e = juliamap(a, b);
	printf ("\nJuliamap: ");
	complex_print(e);

}

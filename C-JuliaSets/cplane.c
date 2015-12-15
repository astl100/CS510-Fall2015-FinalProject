#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cplane.h"

//constructor
CPLANE cplane_setting(const long double xmin, const long double xmax, const long double ymin, const long double ymax, const unsigned long int xpoints, const unsigned long int ypoints)
{
	CPLANE a;
	a.xmin = xmin;
	a.xmax = xmax;
	a.ymin = ymin;
	a.ymax = ymax;

	a.xpoints = xpoints;
	a.ypoints = ypoints;

	int i,j;
	long double dx, dy;
	if (xmax <= xmin) 
        {fprintf(stderr, "Failure with xmax inreference to xmin\n");}
	if (ymax <= ymin) 
        {fprintf(stderr, "Failure with ymax inreference to ymin\n");}

	if (xpoints == 0) 
        {fprintf(stderr, "No X steps\n");}
	if (ypoints == 0) 
        {fprintf(stderr, "No Y steps\n");}
	dx = (xmax-xmin)/xpoints;
	dy = (ymax-ymin)/ypoints;

	long double x_comp, y_comp;
	COMPLEX **m;

	for(i=0;i<(xpoints); i++)
	{
		for(j=0;j<(ypoints);j++)
		{
			x_comp = xmin + i*dx;
			y_comp = ymin + j*dy;
			m[i][j] = complex_setting(x_comp, y_comp);
		}
	}
	a.mat = &m;
	if (a.mat == NULL) 
	{
	fprintf(stderr, "Failed to allocate new_matrix\n");
	}
	return a;
}

//cplane.h should have #define MAXITER 256 at the top

int iterate(COMPLEX *z, COMPLEX *c)
{
	COMPLEX y;      
	unsigned int out;

	for (out = 0; out < MAXITER; out++)
	{
		y = juliamap(z, c);

		if (sqrt(y.x*y.x + y.y*y.y) > 2)                      			{return out;}
	}                                                       

	return 0;                                        
}

void cplane_iterate(CPLANE cp, COMPLEX *c)
{
        int i,j;
	int amount_it;
	COMPLEX z;

        for(i=0;i<cp.xpoints; i++)
	{
		for(j=0;j<cp.ypoints; j++)
		{
			z = cp[i][j];
                	amount_it = iterate(&z, c);
		}
        }

        printf("%Lg, %Lg, %o\n",z.x, z.y, amount_it);
}


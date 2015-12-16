#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cplane.h"

//constructor initializing cplane in a sensible way
CPLANE cplane_setting(const long double xmin, const long double xmax, const long double ymin, const long double ymax, const unsigned long int xpoints, const unsigned long int ypoints)
{
	CPLANE a;
	a.xmin = xmin;
	a.xmax = xmax;
	a.ymin = ymin;
	a.ymax = ymax;
	//printf("%Lg %Lg\n", ymin, ymax);

	a.xpoints = xpoints;
	a.ypoints = ypoints;	
	
	//checks to see if valid parameters
	if (xmax <= xmin) 
        	{fprintf(stderr, "Failure with xmax inreference to xmin\n");}
	if (ymax <= ymin) 
        	{fprintf(stderr, "Failure with ymax inreference to ymin\n");}
	if (xpoints == 0) 
        	{fprintf(stderr, "No X steps\n");}
	if (ypoints == 0) 
        	{fprintf(stderr, "No Y steps\n");}
	
	//define variables and calculate each step(dx, dy)
	int i,j;
        long double dx, dy;	

	dx = (xmax-xmin)/xpoints;
	dy = (ymax-ymin)/ypoints;

	long double x_comp, y_comp;
	//COMPLEX m[xpoints][ypoints];

	//set a complex number at each coordinate of the complex plane
	COMPLEX **m = (COMPLEX **)calloc(xpoints, sizeof(COMPLEX *));
	for(i=0;i<(xpoints); i++)
	{
		m[i] = (COMPLEX *)calloc(ypoints, sizeof(COMPLEX));
		for(j=0;j<(ypoints);j++)
		{
			x_comp = xmin + i*dx;
			y_comp = ymin + j*dy;
			m[i][j] = complex_setting(x_comp, y_comp);
		}
	}
	a.mat = m;
	if (a.mat == NULL) 
	{
	fprintf(stderr, "Failed to allocate new_matrix\n");
	}
	return a;
}

/*calculates z^2 + c for every (z,c) given
  *	loops until the max number of iterations is reaches
  *	OR the magnitude is greater than 2*/
int iterate(COMPLEX *z, COMPLEX *c)
{
	COMPLEX y = *z;      
	unsigned int out;
	long double norm;
	
	for (out = 1; out < MAXITER; out++)
	{
		norm = sqrtl(y.x*y.x + y.y*y.y);
		if (norm > 2)                      			{return out;}
		y = juliamap(&y, c);
	}                                                       

	return 0;                                        
}

/*iterates through every complex number in the complex plane
 * applies iterate function above to every coordinate*/
void cplane_iterate(CPLANE *cp, COMPLEX *c)
{
        int i,j;
	int amount_it;
	COMPLEX z;

        for(i=0;i<(*cp).xpoints; i++)
	{
		for(j=0;j<(*cp).ypoints; j++)
		{
			z = (*cp).mat[i][j];
                	amount_it = iterate(&z, c);
			printf("%Lg, %Lg, %o\n", z.x, z.y, amount_it);
		}
        }

}


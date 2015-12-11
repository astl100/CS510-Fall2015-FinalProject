#include <stdio.h>
#include <stdlib.h>
#include "cplane.h"

//constructor
CPLANE setting(const long double xmin, const long double xmax, const long double ymin, const long double ymax, const unsigned long int xpoints, const unsigned long int ypoints)
{
	CPLANE a;
	a.xmin = xmin;
	a.xmax = xmax;
	a.ymin = ymin;
	a.ymax = ymax;

	a.xpoints = xpoints;
	a.ypoints = ypoints;

	COMPLEX m[xpoints][ypoints];
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
	dx = (xmax-min)/xpoints;
	dy = (ymax-ymin)/ypoins;
	for(i=0;i[xpoints]; i++)
	{
		for(j=0;j[ypoints];j++)
		{
			m[i][j] = complex_setting(xmin+i*dx,ymin+j*dy);
		}
	}
	c.mat=&m;
	if (c.mat == NULL) 
	{
	fprintf(stderr, "Failed to allocate new_matrix\n");
	}
	return a;
}



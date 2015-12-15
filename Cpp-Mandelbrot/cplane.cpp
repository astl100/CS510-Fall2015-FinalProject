#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cplane.h"
#include <boost/numeric/ublas/cplane.hpp>
#include <boost/numeric/ublas/io.hpp>

//constructor initializing cplane in a sensible way
cplane::cplane(const long double xmin, const long double xmax, const long double ymin, const long double ymax, const unsigned long int xpoints, const unsigned long int ypoints)
{
        complex_plane.xmin = xmin;
        complex_plane.xmax = xmax;
        complex_plane.ymin = ymin;
        complex_plane.ymax = ymax;

        complex_plane.xpoints = xpoints;
        complex_plane.ypoints = ypoints;

     	//checks if some given parameters are valid
        if (xmax <= xmin)
        	{fprintf(stderr, "Failure with xmax inreference to xmin\n");}
        if (ymax <= ymin)
        	{fprintf(stderr, "Failure with ymax inreference to ymin\n");}
        if (xpoints == 0)
        	{fprintf(stderr, "No X steps\n");}
        if (ypoints == 0)
        	{fprintf(stderr, "No Y steps\n");}
	
	//defines variables and calculates each step(dx, dy)
	int i,j;
        long double dx, dy;
        dx = (xmax-xmin)/xpoints;
        dy = (ymax-ymin)/ypoints;

        long double x_comp, y_comp;

	/*set a complex number at each coordinate of the complex plane*/
        for(i=0;i<(xpoints); i++)
        {
                for(j=0;j<(ypoints);j++)
                {
                        x_comp = xmin + i*dx;
                        y_comp = ymin + j*dy;
                        m[i][j] = std::complex<long double>(x_comp, y_comp);
                }
        }
        complex_plane.mat = &m;
        if (complex_plane.mat == NULL)
        	{fprintf(stderr, "Failed to allocate new_matrix\n");}
}

/*calculates z^2 + c for every (z,c) given
 *   loops until the max number of iterations is reaches
 *     OR the magnitude is greater than 2*/
int cplane::iterate(std::complex<long double> z, std::complex<long double> c)
{
        std::complex<long double> y;
        unsigned int out;

        for (out = 0; out < MAXITER; out++)
        {
                y = juliamap(z, c);

                if (sqrt(y.x*y.x + y.y*y.y) > 2)                                        {return out;}
        }

        return 0;
}

/*iterates through every complex number in the complex plane
 *  * applies iterate function above to every coordinate*/
void cplane::iterate(std::complex<long double> c)
{
        int i,j;
        int amount_it;

        for(i=0;i<complex_plane.xpoints; i++)
        {
                for(j=0;j<complex_plane.ypoints; j++)
                {
                        std::complex<long double> z;
                        z = complex_plane[i][j];
                        amount_it = iterate(z, c);
                }
        }

        printf("%Lg, %Lg, %o\n",z.x, z.y, amount_it);
}


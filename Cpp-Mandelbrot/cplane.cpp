#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cplane.h"
#include <boost/numeric/ublas/cplane.hpp>
#include <boost/numeric/ublas/io.hpp>

//constructoe
cplane::cplane(const long double xmin, const long double xmax, const long double ymin, const long double ymax, const unsigned long int xpoints, const unsigned long int ypoints)
{
        complex_plane.xmin = xmin;
        complex_plane.xmax = xmax;
        complex_plane.ymin = ymin;
        complex_plane.ymax = ymax;

        complex_plane.xpoints = xpoints;
        complex_plane.ypoints = ypoints;

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
        {
        fprintf(stderr, "Failed to allocate new_matrix\n");
        }
}

//cplane.h should have #define MAXITER 256 at the top

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


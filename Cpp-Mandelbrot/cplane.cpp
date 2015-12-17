
#include "cplane.h"

//constructor initializing cplane in a sensible way
cplane::cplane(const long double _xmin, const long double _xmax, const long double _ymin, const long double _ymax, const unsigned long int _xpoints, const unsigned long int _ypoints)
{
        //initialize variables, left side of =
        xmin = _xmin;
        xmax = _xmax;
        ymin = _ymin;
        ymax = _ymax;

        xpoints = _xpoints;
        ypoints = _ypoints;

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
	boost::numeric::ublas::matrix<std::complex<long double> > m(xpoints, ypoints);
    //2D array notation in C++ uses (x, y) to access

	/*set a complex number at each coordinate of the complex plane*/
        for(i=0;i<(xpoints); i++)
        {
                for(j=0;j<(ypoints);j++)
                {
                        x_comp = xmin + i*dx;
                        y_comp = ymin + j*dy;
                        m(i, j) = std::complex<long double>(x_comp, y_comp);
                }
        }
        complex_plane = m;

}

/*    method calculates z^2 + c for every (z,c) given
 *   loops until the max number of iterations is reaches
 *     OR the magnitude is greater than 2*/
int cplane::iterate(std::complex<long double> *z, std::complex<long double> *c)
{
        std::complex<long double> y = *z;
        unsigned int out;

        for (out = 1; out < MAXITER; out++)
        {

                if (std::abs(y) > 2)                                        
                   {return out;}
       		 
                y = juliamap(&y, c);
	}

        return 0;
}

/*iterates through every complex number in the complex plane
 *  * applies iterate function above to every coordinate*/
void cplane::create_mandelbrot()
{
        int i,j;
        int amount_it;
        std::complex<long double> zero = (0,0);
    
        for(i=0;i<complex_plane.size1(); i++)
        {
                for(j=0;j<complex_plane.size2(); j++)
                {
                        std::complex<long double> c;
                        c = complex_plane(i,j);
                        amount_it = this->iterate(&zero, &c);
                	printf("%Lg, %Lg, %o\n",c.real(), c.imag(), amount_it);
		        }
        }

}


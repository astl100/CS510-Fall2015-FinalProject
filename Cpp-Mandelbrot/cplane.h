#include "julia.h"
#include <cstdio>
#define MAXITER 256
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

//creating cplane class with pulic var.
class cplane
{
public:
	boost::numeric::ublas::matrix<std::complex<long double> > complex_plane;

        long double xmin;
        long double xmax;
        long double ymin;
        long double ymax;
        unsigned long int xpoints;
        unsigned long int ypoints;

	//function definitions
	cplane(const long double xmin, const long double xmax, const long double ymin, const long double ymax, const unsigned long int xpoints, const unsigned long int ypoints);
	int iterate(std::complex<long double> *z, std::complex<long double> *c);
	void create_mandelbrot();

};

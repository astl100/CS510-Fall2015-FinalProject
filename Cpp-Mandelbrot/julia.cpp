#include "julia.h"
#include "cplane.hpp"
#include <math.h>

//juliamap function calculating z^2 +c for two complex numbers(z,c)
Julia::Julia() {}

std::complex<long double> juliamap(const std::complex<long double> *c, const std::complex<long double> *z)
    {
        std::complex<long double> b;        
	b = pow(z, 2) + c;
        return b;
    }


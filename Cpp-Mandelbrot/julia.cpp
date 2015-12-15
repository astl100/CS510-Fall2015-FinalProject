#include "julia.h"
#include "cplane.hpp"
#include <math.h>

Julia::Julia() {}

std::complex<long double> juliamap(const std::complex<long double> *c, const std::complex<long double> *z)
    {
        std::complex<long double> b;        
	b = pow(z, 2) + c;
        return b;
    }


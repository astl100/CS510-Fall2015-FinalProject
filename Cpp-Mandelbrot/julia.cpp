#include "julia.h"

//juliamap function calculating z^2 +c for two complex numbers(z,c)

std::complex<long double> juliamap(const std::complex<long double> *z, const std::complex<long double> *c)
    {
    std::complex<long double> b;
    
    b = (*z)*(*z) + (*c);
    return b;
    }


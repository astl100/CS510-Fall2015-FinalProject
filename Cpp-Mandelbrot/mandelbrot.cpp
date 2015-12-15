#include "cplane.hpp"

int main(int argc, char **argv)
{
        //error message in case not 8 inputs
        if (argc !=9)
        	{printf("Incorrect amount of inputs");}
       
        //PARSE INPUTS TO BE LONG DOUBLES;
 	long double xmin, xmax, ymin, ymax, xpoints, ypoints;
        sscanf(argv[0], "%Lg", &xmin);
        sscanf(argv[1], "%Lg", &xmax);
        sscanf(argv[2], "%Lg", &ymin);
        sscanf(argv[3], "%Lg", &ymax);
        sscanf(argv[4], "%Lg", &xpoints);
        sscanf(argv[5], "%Lg", &ypoints);

        long double creal, cimag;
        sscanf(argv[7], "%Lg", &creal);
        sscanf(argv[8], "%Lg", &cimag);

        std::complex<long double> *c = new std::complex<long double>(creal, cimag);
        
	cplane * p = new cplane(xmin, xmax, ymin, ymax, xpoints, ypoints);

        //p->iterate(c);
	p->iterate(0,c);

	delete c;
	delete p;
	return 0;
}


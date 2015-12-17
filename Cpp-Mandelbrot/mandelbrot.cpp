#include "cplane.h"
#include <iostream>
#include <cstdio>

int main(int argc, char **argv)
{
        //error message in case not 6 inputs
        if (argc !=7)
        {std::cout << "Incorrect amount of inputs\n";
	return 1;}
       
        //PARSE INPUTS TO BE LONG DOUBLES;
 	long double xmin, xmax, ymin, ymax, xpoints, ypoints;
        sscanf(argv[1], "%Lg", &xmin);
        sscanf(argv[2], "%Lg", &xmax);
        sscanf(argv[3], "%Lg", &ymin);
        sscanf(argv[4], "%Lg", &ymax);
        sscanf(argv[5], "%Lg", &xpoints);
        sscanf(argv[6], "%Lg", &ypoints);

        /*long double creal, cimag;
        sscanf(argv[7], "%Lg", &creal);
        sscanf(argv[8], "%Lg", &cimag);
        */

	/*create a complex number 
 	*       one command line argument is the real portion
 	*       another command line argumant is the imaginary portionn
 	* create a complex plane
 	*       use first 6 command line aruments as parameters for the creation of the plane*/
       // std::complex<long double> *c = new std::complex<long double>(creal, cimag);
        
	cplane * p = new cplane(xmin, xmax, ymin, ymax, xpoints, ypoints);

	/*outputs the amount of iterations take to:
 	*       reach a magnitude greater than 2
 	*       OR reach the max amount of iterations
 	*this is done for every coordinate on the complex plane*/
        //p->iterate(c);
    
	p->create_mandelbrot();

	//destroy pointer
	delete p;
    
	return 0;
}


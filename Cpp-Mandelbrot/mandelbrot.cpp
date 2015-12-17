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

       

	//create a complex plane, using first 6 command line aruments as parameters for the creation of the plane

	cplane * p = new cplane(xmin, xmax, ymin, ymax, xpoints, ypoints);

	/*create mandelbrot for complex plane p, defined above*/
    
	p->create_mandelbrot();

	//destroy pointer
	delete p;
    
	return 0;
}


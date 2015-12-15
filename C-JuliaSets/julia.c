#include "cplane.h"

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

	/*create a complex number 
 	* 	one command line argument is the real portion
 	* 	another command line argumant is the imaginary portion
 	* create a complex plane
 	* 	use first 6 command line aruments as parameters for the creation of the plane*/	
	COMPLEX c = complex_setting(creal, cimag);
	CPLANE cp = cplane_setting(xmin, xmax, ymin, ymax, xpoints, ypoints);

	/*outputs the amount of iterations take to:
 	*	reach a magnitude greater than 2
 	*	OR reach the max amount of iterations
 	*this is done for every coordinate on the complex plane*/	 	cplane_iterate(cp,c);
}
   

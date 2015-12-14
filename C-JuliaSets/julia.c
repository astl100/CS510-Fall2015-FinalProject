#include "cplane.h"

int main(int argc, char **argv)
{
	//error message in case not 8 inputs
	if (argc !=9)
	{printf(...) ;}

	//PARSE INPUTS TO BE LONG DOUBLES;
	//give meaningfo argv inputs
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

	COMPLEX c = complex_setting(creal, cimag);
	CPLANE cp = cplane_setting(xmin, xmax, ymin, ymax, xpoints, ypoints);

	cplane_iterate(cp,c);
}
   

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
	std::complex<long double> mult2(const std::complex<long double> *s, const std::complex<long double> *t);
	std::complex<long double> square(const std::complex<long double> *f);
	std::complex<long double> add2(const std::complex<long double> *u, const std::complex<long double> *v);
	std::complex<long double> juliamap(const std::complex<long double> *g, const std::complex<long double> *r);
	char * complex_print(const std::complex<long double> z);
	char * test(const std::complex<long double> *a, const std::complex<long double> *b);
	int iterate(std::complex<long double> *z, std::complex<long double> *c);
	void iterate(std::complex<long double> *c);

};

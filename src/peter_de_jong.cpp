#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
DataFrame deJong(double a, double b, double c, double d,
		   int iterations = 1e7, double x0 = 0, double y0 = 0) {
	// create the columns
	NumericVector x(iterations);
	NumericVector y(iterations);
	x[0]=x0;
	y[0]=y0;
	for(int i = 1; i < iterations; ++i) {
		x[i] = sin(a*y[i-1])-cos(b*x[i-1]);
		y[i] = sin(c*x[i-1])-cos(d*y[i-1]);
	}
	// return a new data frame
	return DataFrame::create(_["x"]= x, _["y"]= y);
}

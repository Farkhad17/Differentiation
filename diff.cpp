#include <iostream>
#include <math.h>
#include <vector>


double diffx(double k2, double k1, double k0, double x);
double inter_diff(double k2, double k1, double k0, double x, double h);
double f(double k2, double k1, double k0, double x);

int main(int argc, char* argv[]){
	
	double k2, k1, k0, h, x;
	
	try{
		k2 = std::stod(argv[1]);
		k1 = std::stod(argv[2]);
		k0 = std::stod(argv[3]);
		x = std::stod(argv[4]);
		h = std::stod(argv[5]);
	}
	catch(...){
		std::cout << "Not able to parse arguments" << std::endl;
	}
	
	std::cout << " df(x) = " << diffx(k2, k1, k0, x) << " inter df(x) = " << inter_diff(k2, k1, k0, x, h) << " abs = "<< fabs(diffx(k2, k1, k0, x) - inter_diff(k2, k1, k0, x, h)) << std::endl;	
	
	
	return 0;
}

double diffx(double k2, double k1, double k0, double x){
	return 2*k2*x + k1;
}

double inter_diff(double k2, double k1, double k0, double x, double h){
	return (1.0/(2*h))*(-3.0*f(k2, k1, k0, x) + 4.0*f(k2, k1, k0, x + h) - f(k2, k1, k0, x + 2*h));
}

double f(double k2, double k1, double k0, double x){
	return k2*x*x + k1*x + k0;
}

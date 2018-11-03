//

// load libraries
#include <math.h>;
#include <iostream>;
using namespace std;

// define global variables
const double leng1 = 10;
const double leng2 = 7;
const double pi = 3.1415926535897;

// user - defined function
double distance(double x, double y) {
	return sqrt(pow(x, 2) + pow(y, 2));
} // end of distance function

double lawOfCos(double a, double b, double c) {
	return acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a*b));
}

double angles(double x, double y) {
	double a1;
	double a2;

	double dist = distance(x, y);
	double D1 = atan2(x,y);
	double D2 = lawOfCos(dist, leng1, leng2);
	a1 = D1 + D2;
	a2 = lawOfCos(leng1, leng2, dist);
	
	return a1;
	return a2;
}

double rad2deg(double rad) {
	return rad * 180 / pi;
}

int main() {
	double coordinate[2];
	for (int i = 0; i < 2; i++) {
		std::cin >> coordinate[i];
	}
	double a;
	double b = 0;
	a= angles(coordinate[0], coordinate[1]);
	std::cout << a <<" "<< b<< endl;
	return 0;
}
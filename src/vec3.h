#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
  public:
	double a[3];
	
	#init vector
	vec3() : e(0, 0, 0) {}
	vec3(double a0, double a1, double a2) : a(a0, a1, a2) {}

	double r() const {return a[0];}
	double g() const {return a[1];}
	double b() const {return a[2];}
}

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
public:
	double a[3];
	vec3() : a{0,0,0} {}
	vec3(double e0, double e1, double e2) : a{e0, e1, e2} {}

	void print_vec() {
		std::cout << '(' << this->a[0] << ',' << this->a[1] << ',' << this->a[2] << ')' << std::endl;
	}
	double dot_vec(vec3 v) {
                double val = 0;
                val += v.a[0] * this->a[0];
                val += v.a[1] * this->a[1];
                val += v.a[2] * this->a[2];
                return val;
        }

 	vec3 div_vec(double t) {
                vec3 new_vec;
                new_vec.a[0] = this->a[0] /= t;
                new_vec.a[1] = this->a[1] /= t;
                new_vec.a[2] = this->a[2] /= t;
                return new_vec;
        }


	vec3 mul_vec(double t) {
		vec3 new_vec;
		new_vec.a[0] = t * this->a[0];
 		new_vec.a[1] = t * this->a[1]; 
		new_vec.a[2] = t * this->a[2];
		return new_vec;
	}	
	vec3 plus_vec(vec3 v) {
		vec3 new_vec;
		new_vec.a[0] = v.a[0] + this->a[0];	
		new_vec.a[1] = v.a[1] + this->a[1];
		new_vec.a[2] = v.a[2] + this->a[2];
		return new_vec;
	}
	vec3 minus_vec(vec3 v) {
                vec3 new_vec;
                new_vec.a[0] = this->a[0] - v.a[0];
                new_vec.a[1] = this->a[1] - v.a[1];
                new_vec.a[2] = this->a[2] - v.a[2];
                return new_vec;
        }


};


#endif

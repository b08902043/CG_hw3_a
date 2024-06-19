#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
public:
	vec3 origin;
	vec3 dir;
	ray(const vec3& orig, const vec3& direction) : origin(orig), dir(direction) {}

};
#endif

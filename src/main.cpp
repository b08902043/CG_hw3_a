#include <iostream>
#include "vec3.h"
#include "ray.h"
using namespace std;

bool hit_sphere(vec3 center, double radius, ray &r) {
	vec3 oc = center.minus_vec(r.origin);
	auto a = r.dir.dot_vec(r.dir);
	auto b = -2.0 * r.dir.dot_vec(oc);
	auto c = oc.dot_vec(oc) - radius * radius;
	auto discriminant = b*b - 4*a*c;
	return (discriminant >= 0);
}

int main() {
	//int image_width = 256;
	//int image_height = 256;
	
	double ratio = 16.0/9.0;
	int image_width = 500;

	int image_height = int(image_width / ratio);

	double focal_length = 1.0;
	double viewport_height = 2.0;
	double viewport_width = viewport_height * ratio;
	vec3 camera_center = vec3(0, 0, 0);

	auto viewport_u = vec3(viewport_width, 0, 0);
	auto viewport_v = vec3(0, -viewport_height, 0);
	
	auto pixel_delta_u = viewport_u.div_vec(double(image_width));
	auto pixel_delta_v = viewport_v.div_vec(double(image_height));

	auto viewport_upper_left = camera_center.minus_vec(vec3(0, 0, focal_length).minus_vec(viewport_u.div_vec(2.0).plus_vec(viewport_v.div_vec(2.0))));
	auto pixel00_loc = viewport_upper_left.plus_vec((pixel_delta_u.plus_vec(pixel_delta_v).mul_vec(0.5)));

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0;j < image_height; j++) {
		for(int i = 0;i < image_width;i ++) {
			//auto r = double(255);
			//auto g = double(255);
			//auto b = double(255);
			//auto pixel_center = vec3(i, j, 60);
			vec3 pixel_color(255, 0, 0);
			auto pixel_center = pixel00_loc.plus_vec((pixel_delta_u.mul_vec(double(i))).plus_vec((pixel_delta_v.mul_vec(j))));
			//std::cout << pixel_center.a[0] << " " << pixel_center.a[1] << " " << pixel_center.a[2] << endl;
			auto ray_direction = pixel_center.minus_vec(camera_center);
			ray r(camera_center, ray_direction);
			if(hit_sphere(vec3(0, 0, -1), 0.5, r)) {
				std::cout << pixel_color.a[0] << ' ' << pixel_color.a[1] << ' ' << pixel_color.a[2] << '\n';
				//pixel_color();
			}
			else {
				std::cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
			}
		}
	}	

}

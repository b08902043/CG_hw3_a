#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
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

string getFile( string filename )
{
   string buffer;
   char c;

   ifstream in( filename );   if ( !in ) { cout << filename << " not found";   exit( 1 ); }
   while ( in.get( c ) ) buffer += c;
   in.close();

   return buffer;
}

string getData(string text, string tag )
{
   	string s = "";
   	size_t pos = 0;
   	size_t start = 0;
	start = text.find( "<" + tag, start );
	if ( start == !std::string::npos ){
		start += tag.length()+1;
  		pos = text.find( "/>" , start );
		s = text.substr( start, pos - start );
	}
   	return s;
}
vector<string> split_string(const string &text) {
	vector<string> collection;
  	size_t pos = 0;
   	size_t start = 0;
	while(pos < text.length()) {
		start = text.find(">", pos);
		//std::cout << start << "\n";
		collection.push_back( text.substr(pos ,  start - pos+1));
		pos = text.find("<", start);
	}
	return collection;
	
}

vector<double> process_string(string &text) {
	vector<string> strings;
	size_t pos = 1;
        size_t start = 0;
	vector<double> nums;
	while(start != std::string::npos) {
        	start = text.find( " ", pos );
		if(start == std::string::npos) {
			break;
		}
		strings.push_back( text.substr(pos, start - pos));
		pos = start + 1;

	}
	strings.push_back(text.substr(pos, text.length()));
	pos = 0;
	start = 0;
	for (int i = 0;i < strings.size();i ++){
		start = strings[i].find( "\"", pos);
		pos = strings[i].find("\"", start+1);
		//std::cout << start << " " << pos << "\n";
		string tmp = strings[i].substr(start+1, pos-start-1);
		pos = 0 ;
		start = 0;
		nums.push_back(std::stod(tmp));
		//std::cout << nums.back() << "\n";
	}	
	return nums;

}
int main(int argc, char *argv[]) {
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

	auto viewport_upper_left = camera_center.minus_vec(vec3(0, 0, focal_length).plus_vec(viewport_u.div_vec(2.0).plus_vec(viewport_v.div_vec(2.0))));
	auto pixel00_loc = viewport_upper_left.plus_vec((pixel_delta_u.plus_vec(pixel_delta_v).mul_vec(0.5)));

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	
	string filename = "";
	if(std::string(argv[1]) == "task3") {
		filename = "./src/scenes/example1.xml";
	}
	vec3 background_color;
	if(filename != "") {
		string text = getFile( filename);
		string background_tag ="background_color";
		vector<string> strings = split_string(text);
		for(int i = 0;i < strings.size();i ++) {
			string background_color_str  = getData(strings[i], background_tag);
			if(background_color_str != "") {
				vector<double> colors = process_string(background_color_str);
				background_color.a[0] = colors[0];
				background_color.a[1] = colors[1];
				background_color.a[2] = colors[2];
						
			}
		}
		//for (string &s :all) {
		//	std::cout << s << std::endl;
	//	}

	}
	for (int j = 0;j < image_height; j++) {
		for(int i = 0;i < image_width;i ++) {
			if(std::string(argv[1]) == "task1") {
			       	std::cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
			}
			if(std::string(argv[1]) == "task2") {
				vec3 pixel_color(255, 0, 0);
				auto pixel_center = pixel00_loc.plus_vec((pixel_delta_u.mul_vec(double(i))).plus_vec((pixel_delta_v.mul_vec(j))));
				auto ray_direction = pixel_center.minus_vec(camera_center);
				ray r(camera_center, ray_direction);
				if(hit_sphere(vec3(0, 0, -1), 0.5, r)) {
					std::cout << pixel_color.a[0] << ' ' << pixel_color.a[1] << ' ' << pixel_color.a[2] << '\n';
				}
				else {
					std::cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
				}
			}
			if(std::string(argv[1]) == "task3") {
				std::cout << background_color.a[0] << ' ' << background_color.a[1] << ' ' << background_color.a[2] << '\n';
			}

		}
	}	

}

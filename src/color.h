#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

void pixel_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.r();
    auto g = pixel_color.g();
    auto b = pixel_color.b();

    out << r << ' ' << g << ' ' << b << ' ' << '\n';
}

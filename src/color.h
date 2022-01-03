#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

// writes out the color of a single pixel using the vec3 class where x, y and z are R, G and B respectively
void write_color(std::ostream &out, color pixel_color)
{
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif // COLOR_H
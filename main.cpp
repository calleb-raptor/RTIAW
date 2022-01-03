#include <iostream>
#include "src/vec3.h"
#include "src/color.h"
#include "src/ray.h"
// int main()
// {
//     // image dimensions
//     const int image_width = 256;
//     const int image_height = 256;

//     // render
//     std::cout << "P3\n"
//               << image_width << ' ' << image_height << "\n255\n";

//     // we want to write pixels in each row left to right
//     // rows are written top to bottom

//     for (int j = image_height - 1; j >= 0; --j)
//     {
//         std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
//         for (int i = 0; i < image_width; ++i)
//         {
//             // auto r = double(i) / (image_width - 1);
//             // auto g = double(j) / (image_height - 1);
//             // auto b = 0.25;

//             // int ir = static_cast<int>(255.999 * r);
//             // int ig = static_cast<int>(255.999 * g);
//             // int ib = static_cast<int>(255.999 * b);

//             // std::cout << ir << " " << ig << " " << ib << '\n';
//             color pixel_color(float(i) / (image_width - 1), float(j) / (image_height - 1), 0.25);
//             write_color(std::cout, pixel_color);
//         }
//     }
//     std::cerr << "\nDone.\n";
// }

color ray_color(const ray &r)
{
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main()
{

    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

    // Render

    std::cout << "P3\n"
              << image_width << " " << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i)
        {
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}

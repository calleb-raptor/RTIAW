#include <iostream>

int main()
{
    // image dimensions
    const int image_width = 256;
    const int image_height = 256;

    // render
    std::cout << "Image width: " << image_width << ' ' << image_height << "\n255\n";

    // we want to write pixels in each row left to right
    // rows are written top to bottom

    for (int j = image_height - 1; j >= 0; --j)
    {
        for (int i = 0; i < image_width; ++i)
        {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << " " << ig << " " << ib << '\n';
        }
    }
}
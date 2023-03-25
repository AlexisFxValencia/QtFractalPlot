#ifndef IMAGE_GENERATOR_H
#define IMAGE_GENERATOR_H
#include <iostream>
#include <vector>
#include "Fractal.hpp"
#include "Point.hpp"
using namespace std;

class ImageGenerator{
    public:
        Point center;
        float width;
        int N_pixels;
        int max_iteration; 
        
        Fractal frctl;
        string fractal_type;

        ImageGenerator();
        int compute_one_pixel(int x, int y);

};

#endif

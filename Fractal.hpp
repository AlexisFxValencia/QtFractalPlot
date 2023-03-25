#ifndef FRACTAL_H
#define FRACTAL_H

#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

class Fractal{
    public:
        Fractal();
        int Newton_finite(float x_0, float y_0, int max_iteration);
        int Mandelbrot_finite(float x_0, float y_0, int max_iteration);
        vector<int> compute_color(float x_color);      
        
};

#endif
#include "ImageGenerator.hpp"


ImageGenerator::ImageGenerator(){
    max_iteration = 100;
    center = Point(-1.0, 0.0);
    width = 2.0;
    N_pixels = 512;
    fractal_type = "Mandelbrot";

}

int ImageGenerator::compute_one_pixel(int x, int y){
  float x_normalized = ((float)x/(float)N_pixels)*width + center.x - width/2;
  float y_normalized = ((float)(N_pixels-y)/(float)N_pixels)*width + center.y - width/2;
  int nb_iterations;
  if (fractal_type=="Mandelbrot"){
    nb_iterations = frctl.Mandelbrot_finite(x_normalized, y_normalized, max_iteration);
  }else if (fractal_type=="Newton"){
    nb_iterations = frctl.Newton_finite(x_normalized, y_normalized, max_iteration);
  }
  return nb_iterations;  
}





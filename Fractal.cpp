#include "Fractal.hpp"

Fractal::Fractal(){
}

complex<double> polynom( complex<double> a){
    return pow(a,3) - 1.0;
} 

complex<double> polynom_d( complex<double> a){
  return 3.0*pow(a,2);
}

int Fractal::Newton_finite(float x_0, float y_0, int max_iteration){
  
  std::complex<double> z(x_0,y_0);
  vector<complex<double>> roots;
  complex<double> r1(1,1);
  complex<double> r2 = -0.5 + 0.5*sqrt(3)*1i;
  complex<double> r3 = -0.5 - 0.5*sqrt(3)*1i;
  roots.push_back(r1);
  roots.push_back(r2);
  roots.push_back(r3);
  int nb_iterations;
  double tolerance = 0.0001;

  for (nb_iterations = 0; nb_iterations < max_iteration; nb_iterations++){
    z -=(polynom(z)/polynom_d(z));
    for (int i = 0; i < roots.size(); i++){
      complex<double> difference = z - roots[i];       
      if (abs(real(difference)) < tolerance && abs(imag(difference)) < tolerance){
        return nb_iterations;
      }
    }
  }
  return max_iteration;
}

int Fractal::Mandelbrot_finite(float x_c, float y_c, int max_iteration){
  complex<double> z(0.0, 0.0);
  complex<double> z_c(x_c, y_c);
  int nb_iterations = 0;
  while (norm(z) <= 4.0 && nb_iterations < max_iteration){
    z = z*z + z_c;
    nb_iterations++;
   }
  return nb_iterations;
}


vector<int> Fractal::compute_color(float x_color){
  // cf. https://stackoverflow.com/questions/20792445/calculate-rgb-value-for-a-range-of-values-to-create-heat-map  
  
  int blue_neg = (int)(255 * (1 - 2 * x_color));
  int blue =  max(blue_neg, 0);
  int green;
  if (x_color <=0.5){          
    green = (int)(2*x_color*255);
  } else{
    green = (int)(-2*(x_color - 1)*255);
  }
  int red_neg = (int)(255 * (2 * x_color - 1));
  int red = max(red_neg, 0);
  vector<int> colors;
  colors.push_back(red);
  colors.push_back(green);
  colors.push_back(blue);
  return colors;
}

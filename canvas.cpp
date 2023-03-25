#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget{parent}
{
    first_paint = true;
    init();
}

void Canvas::init(){
    color.setRgb(209, 99, 71, 255);
    max_iteration = 100;
    center = Point(-1.0, 0.0);
    img_width = 2.0;
    N_pixels = 512;
    fractal_type = "Mandelbrot";
}

int Canvas::compute_one_pixel(int x, int y){
  float x_normalized = ((float)x/(float)N_pixels)*img_width + center.x - img_width/2;
  float y_normalized = ((float)(N_pixels-y)/(float)N_pixels)*img_width + center.y - img_width/2;
  int nb_iterations;
  if (fractal_type=="Mandelbrot"){
    nb_iterations = frctl.Mandelbrot_finite(x_normalized, y_normalized, max_iteration);
  }else if (fractal_type=="Newton"){
    nb_iterations = frctl.Newton_finite(x_normalized, y_normalized, max_iteration);
  }
  return nb_iterations;
}


void Canvas::paintEvent(QPaintEvent*) {
    N_pixels = height();
    qDebug()<< "width : " << width();
    qDebug()<< "height : " << height();

    QPainter painter(this);
    painter.setPen(color);

    if (first_paint ==true){
        for (int x=0; x < width(); x++){
            for (int y=0; y < height(); y++){
                painter.drawPoint(x, y);
            }
        }
        first_paint = false;
    } else{
        for (int y = 0; y < height(); ++y) {
          for (int x = 0; x < width(); ++x) {
              int nb_iterations = compute_one_pixel(x, y);
              if (nb_iterations >= max_iteration){
                color.setRgb(0, 0, 0);
              } else{
                  float x_color = (float)nb_iterations/(float)max_iteration;
                  vector<int> colors = frctl.compute_color(x_color);
                  color.setRgb(colors[0], colors[1], colors[2], 255);
              }
            painter.setPen(color);
            painter.drawPoint(x, y);
          }
        }
    }
}


void Canvas::mousePressEvent(QMouseEvent *event){
    qDebug()<< "click on Canvas !";
    QPoint lastPoint = event->pos();
    qDebug() << "x clicked = " << lastPoint.x();
    qDebug() << "y clicked = " << lastPoint.y();
    double x_normalized = (double)lastPoint.x()/(double)width();
    double y_normalized = (double)lastPoint.y()/(double)height();
    center = Point(x_normalized, y_normalized);
}

void Canvas::painting(){

    //color.setRgb(25, 12, 71, 255);

    update();
    //qDebug()<< width();
    //qDebug() << height();
}

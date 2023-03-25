#include "Point.hpp"

Point::Point(){

}

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

double Point::distanceTo(const Point& o){
    double dx = (x - o.x);
    double dy = (y - o.y);
    return sqrt(dx * dx + dy * dy);
};
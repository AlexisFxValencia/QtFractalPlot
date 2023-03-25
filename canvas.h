#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <ImageGenerator.hpp>
#include <vector>

#include "Fractal.hpp"
#include "Point.hpp"

#include <Qpoint>
#include <QMouseEvent>
using namespace std;

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);    
    QColor color;
    bool first_paint;
    Point center;
    double img_width;
    int N_pixels;
    int max_iteration;
    Fractal frctl;
    string fractal_type;

    void init();
    int compute_one_pixel(int x, int y);
signals:

public slots:
    void painting();


protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;






};

#endif // CANVAS_H

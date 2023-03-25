#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_gui_parameters();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_gui_parameters(){
    ui->x_lineEdit->setText(QString::number(ui->widget->center.x));
    ui->y_lineEdit->setText(QString::number(ui->widget->center.y));
    ui->max_iterations_lineEdit->setText(QString::number(ui->widget->max_iteration));
    ui->width_lineEdit->setText(QString::number(ui->widget->img_width));
}


void MainWindow::on_plot_button_clicked()
{
    //ui->plot_button->setText("Toto");
    ui->widget->center.x = ui->x_lineEdit->text().toDouble();
    ui->widget->center.y = ui->y_lineEdit->text().toDouble();
    ui->widget->max_iteration = ui->max_iterations_lineEdit->text().toInt();
    ui->widget->img_width = ui->width_lineEdit->text().toDouble();
    ui->widget->painting();
}


void MainWindow::on_reset_button_clicked()
{
    ui->widget->init();
    set_gui_parameters();
}


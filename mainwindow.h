#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_gui_parameters();

private slots:

    void on_plot_button_clicked();

    void on_reset_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "Flock.h"
#include <QTime>

namespace Ui {
class MainWindow;
}

QT_BEGIN_NAMESPACE
class QSlider;
class QPushButton;
QT_END_NAMESPACE

class Flock;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool sep;
    bool align;
    bool coh;
    bool random;

private slots:
    void on_AddBoid_released();

    void on_sep_stateChanged(int arg1);

    void on_align_stateChanged(int arg1);

    void on_coh_stateChanged(int arg1);

    void on_reset_timer_clicked();

    //void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_pushButton_clicked();

    void on_horizontalSlider_actionTriggered(int action);

    void on_horizontalSlider_2_actionTriggered(int action);

    void on_horizontalSlider_3_actionTriggered(int action);

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_checkBox_4_stateChanged(int arg1);

protected:
    int timerId;
    int counter = 0;
    int boids = 0;
    int counter_boids = 0;
private:
    Ui::MainWindow *ui;
    Flock *flock;
    void timerEvent(QTimerEvent *event);
    QTime n;
    int elapsed;
    int ms;
    int sec;
    int min;
};

#endif // MAINWINDOW_H

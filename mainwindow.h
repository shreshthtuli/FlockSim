#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "Flock.h"

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

private slots:
    void on_AddBoid_released();
protected:
    int timerId;
private:
    Ui::MainWindow *ui;
    Flock *flock;
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H

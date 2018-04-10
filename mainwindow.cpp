#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Flock.h"
#include <QMessageBox>
#include <QDebug>
#include <QSlider>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QScreen>
#include <QDesktopWidget>
#include <QKeyEvent>
#include<algorithm>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)    
{
    ui->setupUi(this);
    timerId=startTimer(10);
    //flock = new Flock();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddBoid_released()
{
    ui->glwidget->addBoid(ui->xloc->value(), ui->yloc->value(), ui->zloc->value(), ui->strength->value()/100.0, ui->adventorous->value(), ui->sightedness->value(), ui->fova->value(), ui->fovb->value());

}
void MainWindow::timerEvent(QTimerEvent *event){
    ui->glwidget->flocking();
    ui->glwidget->updateGL();
    ui->progressBar->setValue((ui->progressBar->value()+1)%100);
    ui->label->setText(QString::fromStdString(ui->glwidget->get_params()));
}

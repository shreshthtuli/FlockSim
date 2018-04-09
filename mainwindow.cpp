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
    //flock = new Flock();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddBoid_released()
{
    ui->glwidget->addBoid(ui->xloc->value(), ui->yloc->value(), ui->zloc->value(), ui->strength->value(), ui->adventorous->value(), ui->sightedness->value(), ui->fova->value(), ui->fovb->value());

}

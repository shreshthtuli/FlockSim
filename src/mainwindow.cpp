#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Flock.h"
#include <QKeyEvent>
#include<algorithm>
#include <QTime>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)    
{
    ui->setupUi(this);
    MainWindow::showMaximized();
    timerId=startTimer(20);
    //flock = new Flock();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddBoid_released()
{
    ui->glwidget->addBoid(ui->xloc->value(), ui->yloc->value(), ui->zloc->value(), ui->strength->value()/100.0, ui->adventorous->value(), ui->sightedness->value(), ui->fova->value(), ui->fovb->value());
    if(ui->glwidget->getSize()==1)
        n.start();
}
void MainWindow::timerEvent(QTimerEvent *event){
    ui->glwidget->flocking(sep, align, coh, random);
    ui->glwidget->updateGL();
    ui->progressBar->setValue((ui->progressBar->value()+1)%100);
    elapsed = n.elapsed();
    min = elapsed/60000;
    sec = elapsed/1000 - (min * 60);
    ms = elapsed - (sec * 1000) - (min * 60000);
    ui->label->setText(QString("Timestamp: ").append(QString::number(min).append(" min ").append(QString::number(sec)).append(" s ").append(QString::number(ms))).append(QString(" ms\nTotal of ")).append(QString::number(ui->glwidget->getSize())).append(" starlings with "));
    if(counter>=25){
        ui->glwidget->set_params();
        ui->avgspeed->setText(ui->glwidget->get_params(0));
        ui->maxspeed->setText(ui->glwidget->get_params(1));
        ui->avgacc->setText(ui->glwidget->get_params(2));
        ui->maxacc->setText(ui->glwidget->get_params(3));
        ui->avgpow->setText(ui->glwidget->get_params(4));
        ui->maxpow->setText(ui->glwidget->get_params(5));
        ui->totenergy->setText(ui->glwidget->get_params(6));
        ui->maxenergy->setText(ui->glwidget->get_params(7));
        ui->avgmass->setText(ui->glwidget->get_params(8));
        ui->maxmass->setText(ui->glwidget->get_params(9));

        if(boids>0){
            ui->glwidget->addBoid(ui->xloc->value(), ui->yloc->value(), ui->zloc->value(), ui->strength->value()/100.0, ui->adventorous->value(), ui->sightedness->value(), ui->fova->value(), ui->fovb->value());
            if(ui->glwidget->getSize()==1)
                n.start();
            boids--;
        }
        counter = 0;
    }
    counter++;

}

void MainWindow::on_sep_stateChanged(int arg1)
{
    if(arg1 == 0)
        sep = false;
    else
        sep = true;
}

void MainWindow::on_align_stateChanged(int arg1)
{
    if(arg1 == 0)
        align = false;
    else
        align = true;
}

void MainWindow::on_coh_stateChanged(int arg1)
{
    if(arg1 == 0)
        coh = false;
    else
        coh = true;
}

void MainWindow::on_reset_timer_clicked()
{
    n.start();
    ui->glwidget->reset_energy();
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == 0)
        random = false;
    else
        random = true;
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1 == 0)
        ui->glwidget->colour = false;
    else
        ui->glwidget->colour = true;
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1 == 0)
        ui->glwidget->random_loc = false;
    else
        ui->glwidget->random_loc = true;
}

void MainWindow::on_pushButton_clicked()
{
    boids = ui->spinBox->value();
}

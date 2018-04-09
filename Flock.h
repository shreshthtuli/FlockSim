#include <iostream>
#include <vector>
#include "Boid.h"
#include <QGLWidget>

#ifndef FLOCK_H_
#define FLOCK_H_

// Brief description of Flock Class:
// This file contains the class needed to create a flock of boids. It utilizes
// the boids class and initializes boid flocks with parameters that can be
// specified. This class will be utilized in main.

class Flock : public QGLWidget
{
    Q_OBJECT
public:
    vector<Boid*> flock;
    //Constructors
    Flock(QWidget *parent): QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
    {
        xRot = 0;
        yRot = 0;
        zRot = 0;
        zoomfactor = 1.00;
    }

    // Accessor functions
    int getSize();
    Boid getBoid(int i);
    // Mutator Functions
    void flocking();

public slots:
    void addBoid(float x, float y, float z, float strength, float adv, float sightedness, int fova, int fovb);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void draw();
    QPoint lastPos;
    int xRot,yRot,zRot;
    float zoomfactor;
};

#endif

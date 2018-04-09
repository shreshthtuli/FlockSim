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
    explicit Flock(QWidget *parent = 0);
    ~Flock();
    vector<Boid*> flock;
    // Accessor functions
    int getSize();
    Boid getBoid(int i);
    // Mutator Functions
    void flocking();
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setzoom(int zoomval);

public slots:
    void addBoid(float x, float y, float z, float strength, float adv, float sightedness, int fova, int fovb);

signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

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

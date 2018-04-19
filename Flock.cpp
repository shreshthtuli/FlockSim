#include "Boid.h"
#include "Flock.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QCoreApplication>



#ifndef QT_NO_CONCURRENT
#define tth_side 0.1

using namespace QtConcurrent;

// =============================================== //
// ======== Flock Functions from Flock.h ========= //
// =============================================== //


Flock::Flock(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
    zoomfactor = 1.00;
}

Flock::~Flock()
{
}


int Flock::getSize()
{
    return flock.size();
}

Boid Flock::getBoid(int i)
{
    return *flock[i];
}

void Flock::addBoid(float x, float y, float z, float strength, float adv, float sightedness, int fova, int fovb)
{
    auto b = new Boid(x, y, z, strength, adv, sightedness, fova, fovb);
    flock.push_back(b);
}

void flocking0(Flock* f){
    for (int i = 0; i < f->flock.size(); i+=4)
        f->flock[i]->run(f->flock, i, f->sep, f->align, f->coh);
}
void flocking1(Flock* f){
    for (int i = 1; i < f->flock.size(); i+=4)
        f->flock[i]->run(f->flock, i, f->sep, f->align, f->coh);
}
void flocking2(Flock* f){
    for (int i = 2; i < f->flock.size(); i+=4)
        f->flock[i]->run(f->flock, i, f->sep, f->align, f->coh);
}
void flocking3(Flock* f){
    for (int i = 3; i < f->flock.size(); i+=4)
        f->flock[i]->run(f->flock, i, f->sep, f->align, f->coh);
}

// Runs the run function for every boid in the flock checking against the flock
// itself. Which in turn applies all the rules to the flock.
void Flock::flocking(bool Isep, bool Ialign, bool Icoh)
{
    sep = Isep;
    align = Ialign;
    coh = Icoh;
    QFuture<void> t1 = QtConcurrent::run(flocking0, this);
    QFuture<void> t2 = QtConcurrent::run(flocking1, this);
    QFuture<void> t3 = QtConcurrent::run(flocking2, this);
    QFuture<void> t4 = QtConcurrent::run(flocking3, this);

    t1.waitForFinished();
    t2.waitForFinished();
    t3.waitForFinished();
    t4.waitForFinished();
}



QSize Flock::minimumSizeHint() const
{
    return QSize(200, 50);
}

QSize Flock::sizeHint() const
{
    return QSize(800, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void Flock::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void Flock::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void Flock::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void Flock::setzoom(int zoomval)
{
    zoomfactor = zoomval/100.0f;
    updateGL();
}

void Flock::initializeGL()
{
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_PROGRAM_POINT_SIZE);
    //glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
    glEnable ( GL_COLOR_MATERIAL );
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    static GLfloat lightPosition[4] = { 1, 1, 1, 1 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightPosition);

}

void Flock::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glRotatef(zRot, 0.0, 0.0, 1.0);
    if (zoomfactor>0.00) {
        glScalef(zoomfactor, zoomfactor, zoomfactor);
    }
    draw();
}

void Flock::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void Flock::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void Flock::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation((xRot + dy)%360);
        setYRotation((yRot + dx)%360);
    }
    else if (event->buttons() & Qt::RightButton) {
        setXRotation((xRot + dy)%360);
        setZRotation((zRot + dx)%360);
    }

    lastPos = event->pos();
}

QVector3D Flock::perp(const QVector3D &v) {
    qreal min = fabs(v.x());
    QVector3D cardinalAxis(1, 0, 0);

    if (fabs(v.y()) < min) {
        min = fabs(v.y());
        cardinalAxis = QVector3D(0, 1, 0);
    }

    if (fabs(v.z()) < min) {
        cardinalAxis = QVector3D(0, 0, 1);
    }

    return QVector3D::crossProduct(v, cardinalAxis);
}

void Flock::drawCone(const QVector3D &d, const QVector3D &a,
              const qreal h, const qreal rd, const int n) {
    QVector3D c = a + (-d * h);
    QVector3D e0 = perp(d);
    QVector3D e1 = QVector3D::crossProduct(e0, d);
    qreal angInc = (2 * 3.14159) / n  ;

    // calculate points around directrix
    QVector<QVector3D> pts;
    for (int i = 0; i < n; ++i) {
        qreal rad = angInc * i;
        QVector3D p = c + (((e0 * cos(rad)) + (e1 * sin(rad))) * rd);
        pts.push_back(p);
    }

    // draw cone top
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(a.x(), a.y(), a.z());
    for (int i = 0; i < n; ++i) {
        glVertex3f(pts[i].x(), pts[i].y(), pts[i].z());
    }
    glEnd();

    // draw cone bottom
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(c.x(), c.y(), c.z());
    for (int i = n-1; i >= 0; --i) {
        glVertex3f(pts[i].x(), pts[i].y(), pts[i].z());
    }
    glEnd();
}

void Flock::draw()
{
    //glClear();
    //Axes

    glLineWidth(1);

    glBegin(GL_LINES);
        glColor3f( 1.0f, 0.0f, 0.0f );
        glVertex3f(-0.25, 0.0, 0.0);
        glVertex3f(0.25, 0.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
        glColor3f( 0.0f, 1.0f, 0.0f );
        glVertex3f(0.0, -0.25, 0.0);
        glVertex3f(0.0, 0.25, 0.0);
    glEnd();

    glBegin(GL_LINES);
        glColor3f( 0.0f, 0.0f, 1.0f );
        glVertex3f(0.0, 0.0, -0.25);
        glVertex3f(0.0, 0.0, 0.25);
    glEnd();

    //Flock
    //Flock::flocking();

    //3D object
    glColor3f( 0.8f, 0.8f, 0.8f );
    int i=0;
    Pvector dir_temp;
    while(i<flock.size()){

        //qInfo(QString("%1").arg(flock[i]->velocity.abs()).toLatin1());

        colourcode = flock[i]->velocity.abs()/4;

        if(colourcode < 0.5)
            glColor3b(0, 0, 0);
        else if(colourcode < 1)
            glColor3ub(148, 0, 211);
        else if(colourcode > 1 && colourcode < 3)
            glColor3ub(75, 0, 130);
        else if(colourcode > 3 && colourcode < 4.5)
            glColor3ub(0, 0, 255);
        else if(colourcode > 4.5 && colourcode < 6)
            glColor3ub(0, 255, 0);
        else if(colourcode > 6 && colourcode < 7.5)
            glColor3ub(255, 255, 0);
        else if(colourcode > 7.5 && colourcode < 9)
            glColor3ub(255, 127, 0);
        else
            glColor3ub(255, 0, 0);


        dir_temp = flock[i]->velocity;
        dir_temp.normalize();

        QVector3D dir;
        dir.setX(dir_temp.x);
        dir.setY(dir_temp.y);
        dir.setZ(dir_temp.z);

        QVector3D loc;
        loc.setX(flock[i]->location.x/1000);
        loc.setY(flock[i]->location.y/1000);
        loc.setZ(flock[i]->location.z/1000);

        Flock::drawCone(dir, loc, 0.05, 0.02, 3);
        i++;
    }

}

void Flock::set_params(){
    max_speed=0;
    total_speed=0;
    maxacc=0;
    total_acc=0;
    max_power=0;
    total_power=0;
    max_energy=0;
    total_energy=0;
    for(Boid* i:flock){
        tempv = i->real_velocity;
        total_speed+=tempv;
        if(tempv>max_speed)max_speed=tempv;
        tempa = i->real_acceleration;
        total_acc+=tempa;
        if(tempa>maxacc)maxacc=tempa;
        total_power+=i->power;
        if(i->power>max_power)max_power=i->power;
        total_energy+=i->energy;
        if(i->energy>max_energy)max_energy=i->energy;
    }
}

void Flock::reset_energy(){
    for(Boid* i:flock){
        i->energy = 0.0;
    }
}

QString Flock::get_params(int n){
    if (n==0)
        return QString::number(total_speed/flock.size());
    else if (n==1)
        return QString::number(max_speed);
    else if (n==2)
        return QString::number(total_acc/flock.size());
    else if (n==3)
        return QString::number(maxacc);
    else if (n==4)
        return QString::number(total_power/flock.size());
    else if (n==5)
        return QString::number(max_power);
    else if (n==6)
        return QString::number(total_energy);
    else if (n==7)
        return QString::number(max_energy);
    else if (n==8)
        return QString::number(total_energy/(15.7168*flock.size()));  ///376 Cal per 100g cereal and 4.18 J per 1 Cal
    else if (n==9)
        return QString::number(max_energy/(15.7168));
}

 #endif

#include "Boid.h"
#include "Flock.h"
#include <QtWidgets>
#include <QtOpenGL>

#define tth_side 0.1
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

// Runs the run function for every boid in the flock checking against the flock
// itself. Which in turn applies all the rules to the flock.
void Flock::flocking() 
{
    for (int i = 0; i < flock.size(); i++)
        flock[i]->run(flock,i);
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

    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

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

void Flock::draw()
{
    //glClear();
    //Axes

    glLineWidth(4);

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
    Pvector dir;
    while(i<flock.size()){
//        dir=flock[i].velocity;
//        dir.normalize();
//        dir*=0.61237243569*tth_side;

//        glBegin(GL_POLYGON); //
//        glNormal3f(norm.x,norm.y,norm.z);
//        glVertex3f(flock[i].location.x, flock[i].location.y, flock[i].location.z)
//        glVertex3f(flock[i].location.x - flock[i].velocity.x/?? + ??, flock[i].location.y - flock[i].velocity.y/?? + ??, flock[i].location.z - flock[i].velocity.z/?? + ??)
//        glVertex3f(flock[i].location.x - flock[i].velocity.x/?? + ??, flock[i].location.y - flock[i].velocity.y/?? + ??, flock[i].location.z - flock[i].velocity.z/?? + ??)
//        glEnd();
//        glBegin(GL_POLYGON);
//        glNormal3f(norm.x,norm.y,norm.z);
//        glVertex3f(flock[i].location.x, flock[i].location.y, flock[i].location.z)
//        glVertex3f(flock[i].location.x - flock[i].velocity.x/?? + ??, flock[i].location.y - flock[i].velocity.y/?? + ??, flock[i].location.z - flock[i].velocity.z/?? + ??)
//        glVertex3f(flock[i].location.x - flock[i].velocity.x/?? + ??, flock[i].location.y - flock[i].velocity.y/?? + ??, flock[i].location.z - flock[i].velocity.z/?? + ??)
//        glEnd();
//        glBegin(GL_POLYGON);
//        glNormal3f(norm.x,norm.y,norm.z);
//        glVertex3f(flock[i].location.x, flock[i].location.y, flock[i].location.z)
//        glVertex3f(flock[i].location.x - flock[i].velocity.x/?? + ??, flock[i].location.y - flock[i].velocity.y/?? + ??, flock[i].location.z - flock[i].velocity.z/?? + ??)
//        glVertex3f(flock[i].location.x - flock[i].velocity.x/?? + ??, flock[i].location.y - flock[i].velocity.y/?? + ??, flock[i].location.z - flock[i].velocity.z/?? + ??)
//        glEnd();
//        glBegin(GL_POLYGON);
//        glNormal3f(norm.x,norm.y,norm.z);
//        glVertex3f(flock[i].location.x - flock[i].velocity.x/?? + ??, flock[i].location.y - flock[i].velocity.y/?? + ??, flock[i].location.z - flock[i].velocity.z/?? + ??)
//        glVertex3f(flock[i].location.x - flock[i].velocity.x/?? + ??, flock[i].location.y - flock[i].velocity.y/?? + ??, flock[i].location.z - flock[i].velocity.z/?? + ??)
//        glVertex3f(flock[i].location.x - flock[i].velocity.x/?? + ??, flock[i].location.y - flock[i].velocity.y/?? + ??, flock[i].location.z - flock[i].velocity.z/?? + ??)
//        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glLineWidth(2.0);
        glBegin(GL_LINES);
        glVertex3f(flock[i]->location.x/1000+0.05f, flock[i]->location.y/1000, flock[i]->location.z/1000);
        glVertex3f(flock[i]->location.x/1000-0.05f, flock[i]->location.y/1000, flock[i]->location.z/1000);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(flock[i]->location.x/1000, flock[i]->location.y/1000+0.05f, flock[i]->location.z/1000);
        glVertex3f(flock[i]->location.x/1000, flock[i]->location.y/1000-0.05f, flock[i]->location.z/1000);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(flock[i]->location.x/1000, flock[i]->location.y/1000, flock[i]->location.z/1000+0.05f);
        glVertex3f(flock[i]->location.x/1000, flock[i]->location.y/1000, flock[i]->location.z/1000-0.05f);
        glEnd();
        i++;
    }

}
string Flock::get_params(){
    string s("");
    s.append("Total of ");
    s.append(to_string(flock.size()));
    s.append(" starlings spending an average power of \n");
    float max_power=0;
    float total_power=0;
    for(Boid* i:flock){
        total_power+=i->power;
        if(i->power>max_power)max_power=i->power;
    }
    s.append(to_string(total_power/flock.size()));
    s.append("\n(Maximum ");
    s.append(to_string(max_power));
    s.append(")");
    return s;
}


#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

#ifndef PVECTOR_H_
#define PVECTOR_H_

// The Pvector class implements Euclidian vectors -- that is, each vector has
// both a magnitude and a direction. We use Pvectors for implementing movement
// and the three Boid rules -- cohesion, separation, and matching velocity
// through the use of acceleration, force, and velocity vectors.

class Pvector {

public:
    float x;
    float y;
    float z;

    //Constructors
    Pvector() {}

    Pvector(float xComp, float yComp, float zComp)
    {
        x = xComp;
        y = yComp;
        z = zComp;
    }


    //Mutator Functions

    //Scalar functions scale a vector by a float
    Pvector operator +(Pvector v){
        return Pvector(x+v.x,y+v.y,z+v.z);
    }
    static Pvector Rnd_Vector(float size){
        //srand(time(NULL));
        Pvector rndvec(rand()*1.0-RAND_MAX/2,rand()*1.0-RAND_MAX/2,rand()*1.0-RAND_MAX/2);
        rndvec.normalize();
        return rndvec*size;
    }
    Pvector operator +(float f){
        return Pvector(x+f,y+f,z+f);
    }

    Pvector operator -(Pvector v){
        return Pvector(x-v.x,y-v.y,z-v.z);
    }
    //Pvector subTwoVector(Pvector v, Pvector v2);
    //void subScalar(float x)

    float operator *(Pvector v){
        return x*v.x+y*v.y+z*v.z;
    }
    Pvector operator *(float f){
        return Pvector(x*f,y*f,z*f);
    }
    //void divVector(Pvector v);
    Pvector operator /(float f){
        return Pvector(x/f,y/f,z/f);
    }
    float abs(){
        float p=x*x+y*y+z*z;
        p=sqrt(p);
        return p;
    }
    void normalize(){
        x/=abs();
        y/=abs();
        z/=abs();
    }
    void logistic_limit(float max){
        float net=(tanh(abs()/(max*1.732))*max*1.732)/abs();
        x*=net;
        y*=net;
        z*=net;
    }
    //Calculating Functions
    static float distance(Pvector v1, Pvector v2){
        return (v1-v2).abs();
    }

    static float angle(Pvector v1, Pvector v2){
        return acos((v1*v2)/(v1.abs()*v2.abs()));
    }
};

#endif

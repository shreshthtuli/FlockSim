#include "Pvector.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <QtGlobal>
#include <QString>


#define sep_fact -1000000.0
#define att_fact 1.0
#define coh_fact 0.01
#define soft_max_pos 200.0
#define pos_push -1000.0
#define density_of_air 1.225
#define drag_coeff 0.8
#define lift_coeff 1.5
#define max_acc 10.0
#define noise 10.0

#ifndef BOID_H_
#define BOID_H_

// The Boid Class
//
// Attributes
///
/// \brief The Boid class
///

class Boid {
public:
    ///
    /// \brief mass of boid
    ///
    float mass;
    float density;
    ///
    /// \brief Cross Sectional Area of bird
    ///
    float csa;
    ///
    /// \brief strength
    /// \details A quantitative measure of how much strong the bird is. A weaker bird is likely to spend lesser energy. preferable around 1.
    ///
    float strength;
    ///
    /// \brief sightedness
    /// \details How far the bird can see. A higher value indicates short-sightedness. This would be exponentiated in order to calculate the weight of another bird in determining how this bird flies
    float sightedness;
    ///
    /// \brief adventurous
    /// \details How adventurous the bird is. More adventurous birds will be less attracted to other birds, and are likely to move away from the flock. If set to 1000, the bird is not attracted to other birds at all. Lesser values adjust linearly.
    int adventurous;
    ///
    /// \brief fov
    /// \details Maximum angle to which the bird can see. Maximum value is pi,but hugely unrealistic.
    float fov;
    float wing_area;
    float power,energy;
    Pvector location;
    Pvector velocity;
    Pvector acceleration;
    Boid() {}
    Boid(float x, float y, float z, float Istrength, float adv, float sightedness, int fova, int fovb){
        location=Pvector::Rnd_Vector(1000);
        power=0.0;
        energy=0.0;
        strength=Istrength;
        adventurous=adv*10;
        sightedness=sightedness;
        csa=0.08;
        mass=0.075;
        fov=fova*M_PI/fovb;
        density=730.0;
        srand(time(NULL));
        velocity=Pvector(rand()*1.0/RAND_MAX,rand()*1.0/RAND_MAX,rand()*1.0/RAND_MAX)*200;
        acceleration=Pvector(rand()*1.0/RAND_MAX,rand()*1.0/RAND_MAX,rand()*1.0/RAND_MAX);
    }
    //void applyForce(Pvector force);
    ///Internal forces felt by the birds. These are combined into one function to avoid having to loop over all the birds multiple times.
    Pvector Internal(vector<Boid*> Boids, int self, bool sep, bool align, bool coh){
        int i=0;
        Boid *b;
        float distance, view_factor;
        float net_weight=0.0;
        Pvector net_sep(0,0,0);
        Pvector net_att(0,0,0);
        Pvector net_coh(0,0,0);
        while(i<Boids.size()){
            if(i!=self && Pvector::angle(velocity,(Boids[i]->location)-location)){
                b=Boids[i];
                distance=Pvector::distance(b->location, location);
                view_factor=exp(-sightedness*distance*distance);
                net_weight+=view_factor;
                //separation
                //qInfo(QString("%1").arg(distance).toLatin1());
                if(distance < 100 && sep){
                    net_sep= net_sep-(location-b->location)*view_factor*sep_fact*100000/(distance*distance*distance*distance);
                }

                //alignment
                if(align){
                    net_att= net_att+b->velocity*att_fact*view_factor*1000;
                }
                else{
                    net_att= net_att+Pvector::Rnd_Vector(500)*att_fact*view_factor*500;
                }

                //cohesion
                //this force acts opposite to separation. therefore, it is important to make it rise slower, so that separation dominates at lesser distances while cohesion dominates at higher distances
                if(distance > 2 && coh){
                    net_coh= net_coh-(location-b->location)*view_factor*coh_fact*view_factor/(distance*distance)*100000;
                }
            }
            i++;
        }
        if(coh)
            net_coh=(net_coh*(1000-adventurous)+Pvector::Rnd_Vector(adventurous/20))/1000.0;
        if(align)
            net_att=(net_att*(1000-adventurous)+Pvector::Rnd_Vector(adventurous/20))/1000.0;
        //the forces need to be normalised and added. In this case, we choose not to normalise separation. Also, we add a random noise
        return ((net_weight>0)?net_sep+(net_coh+net_att)/net_weight:Pvector(0,0,0));
    }
    ///Positional forces felt by the bird. While it is realistic that the birds would not want to touch the ground, we need hypotheticl boundaries on all sides. This is mostly a computational restriction. This is modelled as a maximally flat filter
    Pvector Positional(){
        float f=location.abs()/soft_max_pos;
        return (f>5)?(location*(sqrt(f)-sqrt(5)))*pos_push:Pvector(0,0,0);
    }

    //Pvector seek(Pvector v);
    void run(vector <Boid*> v, int self, bool sep, bool align, bool coh){
        //Model the external forces

        //Pvector gravity(0,-9.81,0);
        //gravity= gravity*(density-density_of_air)/density;      //correct for buoyancy
        //Pvector drag=(velocity/velocity.abs())*((velocity*velocity)*(-0.5)*density_of_air*drag_coeff*csa/mass);
        //Pvector Lift(0,(velocity.x*velocity.x+velocity.y*velocity.y)*density_of_air*0.5*wing_area*lift_coeff,0);
        //Pvector acc_net=gravity+drag+Lift;
        Pvector new_vel=velocity+acceleration;
        Pvector desired_vel=Internal(v,self, sep, align, coh)+Positional();
        Pvector difference=desired_vel-new_vel;
        difference.logistic_limit(max_acc*strength);
        //Pvector pos=Positional();
        //pos.logistic_limit(2*max_acc);
        new_vel=new_vel+difference;
        acceleration=new_vel-velocity;
        velocity=velocity+acceleration;

        auto new_loc=location+(velocity*0.04);
        new_loc.logistic_limit(20*soft_max_pos);
        velocity=(new_loc-location);
        power=velocity*(difference)*mass;
        energy+=power/10;
        location=new_loc;
    }
};

#endif

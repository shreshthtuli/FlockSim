#include "Pvector.h"
#include <vector>
#include <stdlib.h>
#include <iostream>

#define sep_fact 1.0
#define att_fact 1.0
#define coh_fact 0.001
#define soft_max_pos 100.0
#define pos_push 1.0
#define density_of_air 1.225
#define drag_coeff 0.8
#define lift_coeff 1.5
#define max_acc 1.0

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
    Boid(float x, float y, float z, float strength, float adv, float sightedness, int fova, int fovb){
        location=Pvector(x,y,z);
        power=0.0;
        energy=0.0;
        strength=strength;
        adventurous=adv;
        sightedness=sightedness;
        csa=0.08;
        mass=0.075;
        fov=fova*M_PI/fovb;
        density=730.0;

    }
    //void applyForce(Pvector force);
    ///Internal forces felt by the birds. These are combined into one function to avoid having to loop over all the birds multiple times.
    Pvector Internal(vector<Boid*> Boids, int self){
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
                view_factor=exp(-sightedness*distance);
                net_weight+=view_factor;
                //separation
                net_sep= net_sep+(location-b->location)*view_factor*sep_fact/(distance*distance*distance);

                //alignment
                net_att= net_sep+b->velocity*att_fact*view_factor;

                //cohesion
                //this force acts opposite to separation. therefore, it is important to make it rise slower, so that separation dominates at lesser distances while cohesion dominates at higher distances
                net_coh= net_coh+(location-b->location)*view_factor*coh_fact*view_factor/(distance*distance);
            }
            i++;
        }

        //the forces need to be normalised and added. In this case, we choose not to normalise separation
        return net_sep+(net_att+net_coh)/net_weight;
    }
    ///Positional forces felt by the bird. While it is realistic that the birds would not want to touch the ground, we need hypotheticl boundaries on all sides. This is mostly a computational restriction. This is modelled as a maximally flat filter
    Pvector Positional(){
        return (location/pow(1.5*location.abs()/soft_max_pos,21))*pos_push;
    }

    //Functions involving SFML and visualisation linking
    //Pvector seek(Pvector v);
    void run(vector <Boid*> v, int self){
        //Model the external forces
        Pvector gravity(0,-9.81,0);
        gravity= gravity*(density-density_of_air)/density;      //correct for buoyancy
        Pvector drag=(velocity/velocity.abs())*((velocity*velocity)*(-0.5)*density_of_air*drag_coeff*csa/mass);
        Pvector Lift(0,(velocity.x*velocity.x+velocity.y*velocity.y)*density_of_air*0.5*wing_area*lift_coeff,0);
        Pvector acc_net=gravity+drag+Lift;
        Pvector new_vel=velocity+acceleration;
        Pvector desired_vel=Internal(v,self)+Positional();
        Pvector difference=desired_vel-new_vel;
        difference.logistic_limit(max_acc*strength);
        new_vel=new_vel+difference;
        acceleration=new_vel-velocity;
        velocity=velocity+acceleration;
        power=velocity*difference*mass;
        energy+=power;
        location=location+velocity;
    }
};

#endif

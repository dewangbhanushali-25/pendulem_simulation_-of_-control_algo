#include<cmath>
#include<iostream>
#include"dynamics.hpp"

// physical constants

double g = 9.81;// gravity
double M = 1.0;// cart mass;

double m = 0.5;//pole mass all in kg
double l = 0.5;//pole  half-length (m)

double dt = 0.01;//time step(s)

void compute_acceleration( const State& s, double force, double& x_ddot, double& theta_ddot)
{
    double sin_theta = std::sin(s.theta);
    double cos_theta= std::cos(s.theta);
    double total_mass = M + m;
    /// standard cart-pole equations of motion
    double temp = (force + m * l * s.theta_dot * s.theta_dot * sin_theta) / total_mass;


    theta_ddot = (g*sin_theta - cos_theta*temp) / (l*(4.0/3.0 - m*cos_theta*cos_theta/total_mass));
    x_ddot = temp - m*l*theta_ddot*cos_theta/total_mass;

}

void integrate(State& s , double x_ddot , double theta_ddot)
{
    //update velocities first
    s.x_dot += x_ddot * dt;
    s.theta_dot+= theta_ddot * dt;
    //update the positons
    s.x+= s.x_dot *dt;
    s.theta+= s.theta_dot*dt;

}

void step (State& s , double force)
{
    double x_ddot = 0.0;
     double theta_ddot=0.0;

     compute_acceleration(s,force,x_ddot , theta_ddot);
     integrate(s,  x_ddot , theta_ddot);
}

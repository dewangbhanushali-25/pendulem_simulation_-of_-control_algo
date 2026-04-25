#include<cmath>
#include<iostream>
#include"dynamics.hpp"

// physical constants

double g = 9.81;// gravity
double M = 1.0;// cart mass;

double m = 0.5;//pole mass all in kg
double l = 0.5;//pole  half-length (m)

const double dt = 0.005;//time step(s)



State compute_derivatives(const State& s, double force)
{
    double sin_theta  = std::sin(s.theta);
    double cos_theta  = std::cos(s.theta);
    double total_mass = M + m;

    // CORRECT
    double temp = (force + m * l * s.theta_dot * s.theta_dot * sin_theta) / total_mass;

    double theta_ddot = (g * sin_theta - cos_theta * temp) /
                        (l * (4.0/3.0 - (m * cos_theta * cos_theta) / total_mass));

    double x_ddot = temp - (m * l * theta_ddot * cos_theta) / total_mass;

    State ds;
    ds.x         = s.x_dot;
    ds.x_dot     = x_ddot;
    ds.theta     = s.theta_dot;
    ds.theta_dot = theta_ddot;
    return ds;   // ✓ returns State

}





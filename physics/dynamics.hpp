#pragma once
struct State  {
    double x;         // Cart position
    double x_dot;     // Cart velocity
    double theta;     // Pole angle (radians)
    double theta_dot; // Pole angular velocity
};

void step(State& s , double force);

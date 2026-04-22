#pragma once

struct State {
    double x, x_dot;
    double theta, theta_dot;
};

void step(State& s, double force);
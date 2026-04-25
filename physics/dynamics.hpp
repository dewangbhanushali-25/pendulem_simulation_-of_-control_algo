#pragma once
extern const double dt;
struct State  {
    double x;         // Cart position
    double x_dot;     // Cart velocity
    double theta;     // Pole angle (radians)
    double theta_dot; // Pole angular velocity
};
// integrator types
enum class IntegratorType {
    EULER,
    RK4
};
State compute_derivatives(const State& s , double force);
State state_add(const State& s, const State& ds, double h);
void step(State& s , double force, IntegratorType method = IntegratorType::RK4);

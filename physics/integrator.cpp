// iimplemenation of integrator , will using runga_kutta 4
//
//
#include <cmath>
#include "dynamics.hpp"

//extern const double dt; // taking the exterrnal constant which is defined in dynamics.cpp
//euler euler euler
static void step_euler(State& s, double force)
{
    State ds = compute_derivatives(s, force);

    s.x         += ds.x         * dt;
    s.x_dot     += ds.x_dot     * dt;
    s.theta     += ds.theta     * dt;
    s.theta_dot += ds.theta_dot * dt;
}








State state_add(const State&s , const State& ds,double h){
    State result;
    result.x = s.x + ds.x*h;
    result.x_dot = s.x_dot +ds.x_dot *h;
    result.theta = s.theta +ds.theta *h;
    result.theta_dot = s.theta_dot + ds.theta_dot *h;
    return result;

}

static void step_rk4(State& s,double force){
    State K1 = compute_derivatives(s,  force);
    State K2 = compute_derivatives(state_add(s, K1,dt/2.0), force);
    State K3 = compute_derivatives(state_add(s, K2,dt/2.0),  force);
    State K4 = compute_derivatives(state_add(s, K3,dt),  force);





    s.x         += (dt/6.0) * (K1.x         + 2*K2.x         + 2*K3.x         +  K4.x);
    s.x_dot     += (dt/6.0) * ( K1.x_dot     + 2*K2.x_dot     + 2*K3.x_dot     + K4.x_dot);
    s.theta     += (dt/6.0) * (K1.theta     + 2*K2.theta     + 2*K3.theta     + K4.theta);
    s.theta_dot += (dt/6.0) * (K1.theta_dot + 2*K2.theta_dot + 2*K3.theta_dot + K4.theta_dot);
    //s.theta = std::atan2(std::sin(s.theta), std::cos(s.theta));

}
// ── dispatcher ─────────────────────────────────────
void step(State& s, double force, IntegratorType method)
{
    switch (method) {
        case IntegratorType::EULER: step_euler(s, force); break;
        case IntegratorType::RK4:   step_rk4(s, force);  break;
    }
}
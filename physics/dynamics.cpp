#include <cmath>
#include <iostream>
#include <thread>
#include <chrono>

struct State  {
    double x;         // Cart position
    double x_dot;     // Cart velocity
    double theta;     // Pole angle (radians)
    double theta_dot; // Pole angular velocity
};

const double g = 9.81;//gravity
const double M = 1.0;//Mass of the cart
const double m = 0.5;//mass of the pole
const double l = 0.5;//half lenght of the pole
const double dt = 0.01;// time step



void compute_acceleration(const State& s, double force, double& x_ddot, double& theta_ddot )
{
    double sin_theta = std::sin(s.theta);
    double cos_theta = std::cos(s.theta);
    double total_mass = M + m;

    double temp = (force + m *l*s.theta_dot*sin_theta)/total_mass;

    theta_ddot =
        (g * sin_theta-cos_theta*temp)/
            (l*(4.0/3.0-(m * theta_ddot*cos_theta)/total_mass));
    x_ddot = temp -(m*l*theta_ddot*cos_theta)/total_mass;
}

void integrate(State& s,double x_ddot , double theta_ddot) {
    s.x_dot  +=x_ddot*dt;
    s.theta += theta_ddot*dt;

    s.x += s.x_dot*dt;
    s.theta += s.theta_dot*dt;
}

void step(State& s, double & force) {
    double x_ddot = 0.0 , theta_ddot = 0.0;
    compute_acceleration(s, force, x_ddot, theta_ddot);
    integrate(s, x_ddot, theta_ddot);
}


int main_() {
    State s{};
    s.x = 0.0;
    s.x_dot = 0.0;
    s.theta = 0.1;//small initial single
    s.theta_dot = 0.1;

    while (true) {


        double force = 0.0;
        step(s, force);
        std::cout << "theta: " << s.theta << '\n';
        std::this_thread::sleep_for(std::chrono::duration<double>(dt));

    }
    return 0;
}

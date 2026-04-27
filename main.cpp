


#include <iostream>
#include <fstream>
#include <cmath>
#include "physics/dynamics.hpp"
#include "controllers/controller.hpp"
// remove the dynamics.cpp include

using namespace std;

int main() {
    State s;

    s.x         = 0.0;
    s.x_dot     = 0.0;
    s.theta     = 0.05;
    s.theta_dot = 0.0;

    // ← change ONE line to switch integrator
    IntegratorType integrator = IntegratorType::RK4;
    // IntegratorType integrator = IntegratorType::EULER;


    // ← change ONE line to switch controller
    ControllerType controller = ControllerType::PD;
    // ControllerType controller = ControllerType::NONE;
    // ControllerType controller = ControllerType::P;
    // ControllerType controller = ControllerType::PID;




    std::ofstream file("log.csv");
    file << "time,x,theta\n";

    double t  = 0.0;
    double dt = 0.005;


    for (int i = 0; i < 5000; i++) {
        double force = (kp*s.theta) + (kd*s.theta_dot)-(kv*s.x_dot);

        step(s, force,method);

        // print every 100 steps
        if (i % 100 == 0) {
            std::cout << "t=" << t
                      << " x="         << s.x
                      << " theta="     << s.theta
                      << " theta_dot=" << s.theta_dot
                      << "\n";
        }

        file << t << "," << s.x << "," << s.theta << "\n";
        t += dt;
    }
}
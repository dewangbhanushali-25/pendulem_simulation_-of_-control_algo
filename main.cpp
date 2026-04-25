


#include <iostream>
#include <fstream>
#include <cmath>
#include "physics/dynamics.hpp"   // ✓ only include the header
// remove the dynamics.cpp include

using namespace std;

int main() {
    State s;

    s.x         = 0.0;
    s.x_dot     = 0.0;
    s.theta     = 0.05;
    s.theta_dot = 0.0;
    IntegratorType method = IntegratorType::RK4;

    std::ofstream file("log.csv");
    file << "time,x,theta\n";

    double t  = 0.0;
    double dt = 0.005;

    double kp = 5.0;
    double kd = 10.0;
    double kv = 2.0;
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
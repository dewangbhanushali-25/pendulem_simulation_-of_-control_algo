


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
    s.theta     = 0.1;
    s.theta_dot = 0.0;

    std::ofstream file("log.csv");
    file << "time,x,theta\n";

    double t  = 0.0;
    double dt = 0.01;

    for (int i = 0; i < 2000; i++) {
        double force = 0.0;

        step(s, force);

        // wrap theta to [-pi, pi] so it doesn't spin past 6 rad
        while (s.theta >  M_PI) s.theta -= 2 * M_PI;
        while (s.theta < -M_PI) s.theta += 2 * M_PI;

        file << t << "," << s.x << "," << s.theta << "\n";
        t += dt;
    }

    file.close();
    std::cout << "Simulation done. Data saved.\n";
}
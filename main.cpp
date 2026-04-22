#include <iostream>
#include <fstream>
#include <cmath>
#include "dynamics.hpp"

// include your state + step()

int main() {
    State s;

    // Initial condition (IMPORTANT)
    s.x = 0.0;
    s.x_dot = 0.0;
    s.theta = 0.1;     // small tilt (~5.7°)
    s.theta_dot = 0.0;

    std::ofstream file("log.csv");
    file << "time,x,theta\n";

    double t = 0.0;
    double dt = 0.01;

    for (int i = 0; i < 2000; i++) {
        double force = 0.0;  // NO CONTROL

        step(s, force);

        file << t << "," << s.x << "," << s.theta << "\n";

        t += dt;
    }

    file.close();
    std::cout << "Simulation done. Data saved.\n";
}
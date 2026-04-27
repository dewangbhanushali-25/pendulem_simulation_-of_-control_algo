#pragma once

enum class ControllerType {
    None,
    P,
    PD,
    PID,
    LQR
};
struct ControllerGains {
    double kp = 0.0;
    double kd = 0.0;
    double ki = 0.0;
    //  ADD LQR GAINS ADDEDE LATER
    //
};
double compute_control(double theta, double theta_dot,
                        double integral_error,
                     const ControllerGains& gains,
                     ControllerType type);
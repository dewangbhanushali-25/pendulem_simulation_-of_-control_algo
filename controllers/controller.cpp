#include "controller.hpp"

#include <compare>

// ------ no -control --------------------------

static double control_none() {
    return 0.0;
}

//-p -------------------------------------------------
static double control_p(double theta , const ControllerGains& g) {
    return -(g.kp * theta);
}
// -------PD------------------------------------------------------

static double control_pd(double theta, double theta_dot,
    const ControllerGains& g) {
    return -(g.kd * theta + g.kd * theta_dot);
}
//-----------PID---------------------------------------------
static double control_pid(double theta , double theta_dot,
                            double integral_error,
                            const ControllerGains& g) {
    return -(g.kp * theta +g.kd * theta_dot + g.ki*integral_error);

}
//________________ dispatcher -------------------
double compute_control(double theta, double theta_dot,
    double integral_error, const ControllerGains& gains,
    ControllerType type)


{
switch (type ) {
    case ControllerType::None: return control_none();
    case ControllerType::P: return control_p(theta,gains);
    case ControllerType::PD: return control_pd(theta,theta_dot,gains);
    case ControllerType::PID: return control_pid(theta,theta_dot,integral_error,gains);
    default: return 0.0;
}
}
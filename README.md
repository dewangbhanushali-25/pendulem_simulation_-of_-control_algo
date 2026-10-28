# Pendulum Simulation & Control Algorithms

A C++ simulation framework for studying classical control, numerical integration, and reinforcement learning on a nonlinear pendulum system.

The goal of this project is to understand how different control strategies behave under identical physical conditions, evaluate their stability and performance, and investigate how reinforcement learning compares with model-based control.

## Overview

This project explores the intersection of control theory, numerical methods, and intelligent control.

The simulator models pendulum dynamics and provides a foundation for implementing and comparing feedback controllers. The long-term objective is to build a reproducible experimentation framework for classical and learning-based control algorithms.

### Project Goals

- Model nonlinear pendulum dynamics in C++.
- Study numerical integration methods, including Euler and Runge–Kutta 4 (RK4).
- Implement and validate classical feedback controllers.
- Compare controllers using quantitative performance metrics.
- Investigate swing-up, disturbance rejection, and robustness to model uncertainty.
- Extend the simulator with reinforcement learning using Python and PyTorch.

## Current Features

The repository contains the following components; individual implementations should be verified against the current source before considering them complete.

| Component | Description |
|---|---|
| Physics model | State representation and pendulum dynamics |
| Numerical integration | Euler and RK4 integration options |
| Controller framework | Controller selection and control-law implementations |
| Data logging | CSV-based simulation output |
| Visualization | Python scripts for plotting simulation results |
| Build system | CMake-based C++ project |

## Architecture

The intended architecture separates physical dynamics, numerical integration, control algorithms, and experiment analysis.

```text
pendulum-simulation/
├── controllers/
│   ├── controller.hpp
│   └── controller.cpp
├── physics/
│   ├── dynamics.hpp
│   └── dynamics.cpp
├── graphs/
├── utils/
├── main.cpp
├── simulation.py
├── plot.py
├── CMakeLists.txt
└── README.md
```

This tree illustrates the intended organization. Adapt the paths to match the actual files in the repository.

### Simulation Pipeline

1. Initialize the physical system and its state.
2. Select a numerical integration method.
3. Calculate a control action from the current state.
4. Integrate the equations of motion.
5. Log the resulting state and control action.
6. Analyze the trajectory and performance metrics.

## Mathematical Foundation

For a nonlinear pendulum or cart-pole system, the state can be represented as

\[
\mathbf{x} =
\begin{bmatrix}
x & \dot{x} & \theta & \dot{\theta}
\end{bmatrix}^{T}
\]

where:

- \(x\): cart position, if a cart-pole model is used
- \(\dot{x}\): cart velocity
- \(\theta\): pendulum angle
- \(\dot{\theta}\): angular velocity

The system can be expressed in state-space form as

\[
\dot{\mathbf{x}} = f(\mathbf{x},u)
\]

where \(f\) represents the nonlinear dynamics and \(u\) is the applied control input.

**Important:** the four-state representation applies to a cart-pole system. If the current simulator models a simple pendulum instead, update the equations and state definition accordingly.

### Numerical Integration

The simulator explores two standard integration methods.

**Forward Euler**

\[
\mathbf{x}_{k+1}
=
\mathbf{x}_k+\Delta t\,f(\mathbf{x}_k,u_k)
\]

Euler integration is simple to implement, but its accuracy depends strongly on the timestep.

**Fourth-order Runge–Kutta (RK4)**

RK4 evaluates the derivative at multiple intermediate states to obtain a higher-order numerical approximation. It provides a useful comparison against Euler integration for the same physical model and timestep.

## Control Algorithms

### Classical Control

The project aims to compare feedback controllers under consistent initial conditions, physical parameters, and simulation settings.

- **PID:** Proportional, integral, and derivative feedback.
- **LQR:** Linear-quadratic regulator designed from a linearized state-space model and quadratic cost function.

These controllers should be independently validated before using their results as a benchmark.

### Planned Extensions

#### Swing-Up and Stabilization

Implement an energy-based swing-up controller and switch to LQR near the upright equilibrium. This combines nonlinear control with local linear stabilization.

#### Reinforcement Learning

Integrate a Python training environment and investigate Proximal Policy Optimization (PPO) for continuous control.

The learned policy will be evaluated against classical controllers using the same physics model and test scenarios.

#### Robustness Evaluation

Investigate the effects of:

- Changes in mass and friction
- Initial-state variations
- Measurement noise
- External disturbances
- Unseen physical parameter combinations

#### Safety-Constrained Control

As an advanced extension, investigate action filtering to reduce constraint violations and improve the reliability of learned policies.

## Performance Evaluation

The project will use reproducible experiments rather than relying only on visual inspection.

| Metric | Purpose |
|---|---|
| Settling time | Measures how quickly the system stabilizes |
| Integrated squared error | Measures accumulated tracking error |
| Control effort | Measures the magnitude of applied control |
| Maximum cart displacement | Measures travel-limit compliance, where applicable |
| Success rate | Measures the fraction of successful trials |
| Disturbance recovery time | Measures recovery after an external perturbation |
| Runtime per simulation step | Measures computational cost |

For comparisons, use identical scenarios and repeat experiments across multiple random seeds where applicable. Report measured values only after running the experiments.

## Build and Run

### Requirements

- A C++ compiler supporting the language standard configured in CMake
- CMake
- Python 3, if using the plotting scripts
- Python plotting dependencies required by the scripts

### Build

From the repository root:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
```

These commands assume the current CMake configuration is complete and all declared source files compile successfully.

### Run

The executable name and available command-line arguments depend on the current build configuration.

After building, run the generated executable and use the controller and integrator options supported by your implementation.

### Visualize Results

If the simulation generates the CSV format expected by the plotting scripts, run:

```bash
python3 plot.py
```

Update the script's input path and expected column names if necessary.

## Experimental Methodology

For meaningful controller comparisons:

1. Use the same initial conditions and physical parameters.
2. Keep the integration timestep consistent.
3. Apply equivalent control and state constraints.
4. Separate controller computation from simulation integration.
5. Record the configuration and random seed for each run.
6. Repeat experiments and report summary statistics.
7. Verify numerical stability and controller behavior before interpreting results.

## Development Roadmap

- [ ] Verify a clean CMake build.
- [ ] Validate the nonlinear dynamics and integration methods.
- [ ] Verify controller dispatch and correct feedback equations.
- [ ] Validate PID and LQR independently.
- [ ] Add automated unit tests.
- [ ] Standardize CSV logging and visualization.
- [ ] Build a reproducible benchmarking framework.
- [ ] Implement energy-based swing-up and LQR stabilization.
- [ ] Add randomized dynamics and disturbance testing.
- [ ] Integrate a PPO reinforcement-learning policy.
- [ ] Compare classical control and RL on held-out scenarios.
- [ ] Investigate safe control and constraint handling.

## Engineering Focus

The central objective is not simply to implement more controllers. It is to develop an experimental framework that makes control algorithms comparable, their assumptions explicit, and their performance measurable.

The project emphasizes mathematical understanding, software modularity, numerical validation, reproducibility, and honest evaluation.

## Author

**Dewang Bhanushali**

Electronics and Telecommunication Engineering  
Interested in control systems, robotics, simulation, C++, and reinforcement learning.

## License

Add the project's chosen license here. If portions of the implementation are based on external tutorials or reference implementations, preserve their required attribution and licensing terms.

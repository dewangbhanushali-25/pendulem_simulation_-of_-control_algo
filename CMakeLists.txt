cmake_minimum_required(VERSION 4.2)
project(cartpole)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(controllers)
include_directories(physics)
include_directories(utils)

add_executable(cartpole
        controllers/lqr.cpp
        controllers/pid.cpp
        controllers/ppo.cpp
        physics/dynamics.cpp
        physics/dynamics.hpp
        physics/integrator.cpp
        utils/matrix.cpp
        main.cpp)

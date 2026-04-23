cmake_minimum_required(VERSION 3.10)
project(cartpole)

set(CMAKE_CXX_STANDARD 14)

include_directories(physics)

add_executable(cartpole
        main.cpp
        physics/dynamics.cpp
)
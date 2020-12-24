cmake_minimum_required(VERSION 3.10)
project(FLIGHTSIMULATOR)

set(SOURCES main.cpp simulator.cpp plane.cpp tower.cpp airport.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
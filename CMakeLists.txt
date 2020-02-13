cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(Bus_reservation_system)

add_executable(Bus_reservation_system src/main.cpp src/Reservation_system.cpp src/Bus.cpp src/Route.cpp src/ui.cpp)

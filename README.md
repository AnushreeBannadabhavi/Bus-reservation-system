# CPPND: Capstone Project - Bus reservation system

This is a Bus reservation system program written as Capstone project for the C++ Nanodegree program on Udacity.

## Project overview
This project is a console application and mimics a simple Bus reservation system. It enables the user to book a bus seat.
* The user gets a list of places serviced by the bus company. 
* The user then enters the city codes of the source, destination. He is also required to enter his details(name and contact number).
* If the city codes entered are not serviced by the company, the user is prompted with an appropriate error message.
* If the city codes are serviceable, the user is provided with the bus details viz. Bus ID, arrival and departure times and seat layout of the bus.
* The user can choose the appropriate seat and the booking is confirmed.
* If the user chooses a seat that's not available, he is prompted with an error message.

### Future scope
The project can be further expanded to facilitate booking cancellation, having multiple stops for a particular route, multiple buses for a particular route.
Also, the booking data is destroyed once the session ends. This can be changed by storing the data in a database/file.

### File Structure
```
Bus_Reservation_System
|
+-- BusInfo
|   |
|   +-- (Bus information stored in different files)
|
+-- src
|   |
|   +-- Bus.cpp
|   |
|   +-- Bus.h
|   |
|   +-- Route.cpp
|   |
|   +-- Route.h
|   |
|   +-- Reservation_system.cpp
|   |
|   +-- Reservation_system.h
|   |
|   +-- ui.cpp
|   |
|   +-- ui.h
|   |
|   +-- main.cpp
|
+-- CMakeLists.txt
|
+-- README.md
```

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Navigate to the src directory `cd src`
3. Make a build directory in the `src` directory: `mkdir build && cd build`
4. Compile: `cmake .. && make`
5. Run it: `./Bus_reservation_system`.
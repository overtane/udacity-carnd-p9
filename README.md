# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## Code structure
* src/Timestamp.h: simple timestamp class. Timestamp is taken at object instantiation time. diff() method exists for comparing timestamps.
* PID.cpp, PID.h: PID controller code for calculating new steering wheel angle from the latest cross track error (CTE). Calculation takes into account the time difference of samples.
* main.cpp: reading drive status values (CTE, speed) from [the Udacity SDC simulator](https://github.com/udacity/self-driving-car-sim), and feeds back the calculated steering wheel angle and throttle values. In this version, throttle is always constant 0.6.

## Running the Program

The program can take four arguments:
* -p <double>: proportional term coeffient 
* -d <double>: derivative term coefficient
* -i <double>: integral term coefficient
* -D: debug output, get more output from processing

After starting the pid-program, start the Udacity simulator and select autonomous mode. For each data sample, program outputs three values: cross track error, calculated steering wheel angle, and running average of the CTE. With -D argument one gets additional output.

## About the Controller

Control is achieved using proportional (P), derivative (D) and integral (I) terms. The P term counteracts the current and latest measured error value. This easily leads to overshooting the setpoint and a plain P-controller typically oscillates. To mitigate this behavior we use the derivate term, which predicts the future trend of the error and minimizes it over the time. The integral term sums up the past trends of the error, and can detect and correct possible constant drift in streering.   

The behavior of different controllers can be easily tested by zeroing program arguments. For example:

* PID-controller: `./pid -p 0.2 -d 0.1 -i 0.1`
* P-controller:   `./pid -p 0.2 -d 0 -i 0`
* PD-controller:  `./pid -p 0.2 -d 0.1 -i 0`
* PI-controller:  `./pid -p 0.2 -d 0 -i 0.1`

Default values for coefficients  are  p == 0.2, d == 0.1 and i == 0.1. *Car passes the test track when these values are used*. The values have been found by manual tuning with the SDC simulator. The car passes the track equally well without the integral factor, but the average CTE remains rather high. When using the I-term, the average CTE goes close to zero.

## Experimenting

One can use `PIDControl.ipynb` jupyter notebook for experimenting with the controller. The notebook also contains a twiddle algorithm for finding optimal values for coeffients. This image. generated with the notebook code, illustrates error values from different kind of controllers:

![PID](PID.png?raw=true "Output from different controllers") 


## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 3.81
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 4.2.1
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/aca605f8-8219-465d-9c5d-ca72c699561d/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 


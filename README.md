# Signal Simulator Project

The Signal Simulator Project is a C++ and Qt-based application designed for basic signal processing visualization using sinusoidal signals and FFT operations.

### Educational Goals

This project served as my introduction to GUI application development, and a transition from my previous experience with console-based programs. Developed under a tight timeline, with the primary goals to:
- Apply the object-oriented programming principles learned in C++ in combination with UI development.
- Learn and apply new skills with previously unfamiliar software tools and libraries, particularly Qt for UI development, CMake for build management, and Docker for creating containerized images.
- Build a basic GUI application from scratch to establish a solid understanding for future projects.

## Features

- **Generate Signals:** adjust the frequency and amplitude of a generated sinusoidal signal
- **FFT Operations:** apply forward and inverse FFT to signals
- **Visualization:** view the generated signal and its FFT transformation in real time

## Prerequisites

To successfully compile the Signal Simulator Project, install the following:

- **Qt:** Qt5 or Qt6, Qt development libraries
- **CMake:** used for building the application
- **A C++ compiler:** any compiler compatible with C++17 standard
- **KissFFT:** necessary for FFT operations

## Setup

**1. Clone the Repository**

```bash
  git clone https://github.com/yourusername/Signal-Simulator-Project.git
  cd Signal-Simulator-Project
```

**2. Build the Project**

In the project directory, run: 
```bash
  mkdir build && cd build
  cmake ..
  cmake --build .
```

**3. Run the Application**
```bash
./SignalSimulator
```

## Docker (extra)
This application has a graphical user interface, which Docker does not natively support for visual output. The Docker setup in this project is primarily for practicing Dockerfile creation and does not display the GUI when run. 

```bash
    docker build -t signal-simulator .
    docker run -it --rm signal-simulator
```

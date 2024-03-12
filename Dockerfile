# Use an image with C++ and Qt
FROM ubuntu:latest

# Install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    qtbase5-dev \
    libqt5widgets5 \
    libqt5charts5-dev \
    git \
    libpng-dev \
    pkg-config \
    libfftw3-dev

# Clone and install kissfft
RUN git clone https://github.com/mborgerding/kissfft.git \
    && cd kissfft \
    && cmake -DKISSFFT_STATIC=ON . \
    && make \
    && make install

# Copy the project files into the Docker container
COPY . /Signal-Simulator-Project
WORKDIR /Signal-Simulator-Project

# Build the project
RUN cmake . && make

# Run the application
CMD ["./SignalSimulator"]

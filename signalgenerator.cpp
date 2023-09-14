#include "signalgenerator.h"

SignalGenerator::SignalGenerator() : frequency(1.0), amplitude(1.0) {}

void SignalGenerator::setFrequency(double freq) {
    frequency = freq;
}

void SignalGenerator::setAmplitude(double amp) {
    amplitude = amp;
}

std::vector<double> SignalGenerator::generateSignal(int numSamples) {
    std::vector<double> signal;
    for (int i = 0; i < numSamples; ++i) {
        // Assuming a sample rate of 44100Hz for this example.
        double t = (double) i / 44100.0;
        signal.push_back(amplitude * sin(2 * M_PI * frequency * t));
    }
    return signal;
}

#include "signalgenerator.h"

// Initialize frequency and amplitude to the respective default values
SignalGenerator::SignalGenerator() : frequency(1.0), amplitude(1.0) {}

void SignalGenerator::setFrequency(double freq) { frequency = freq; }

void SignalGenerator::setAmplitude(double amp) { amplitude = amp; }

// Generate a sinusoidal signal with sample values
std::vector<double> SignalGenerator::generateSignal(int numSamples) {
  std::vector<double> signal;
  signal.reserve(numSamples); // Reserve space for efficient calculations
  double sampleRate = 44100.0;
  double tIncrement = 1.0 / sampleRate; // Calculate the time increment once
  double t = 0;                         // Initialize time

  for (int i = 0; i < numSamples; ++i) {
    signal.push_back(amplitude * sin(2 * M_PI * frequency * t));
    t += tIncrement; // Increment time
  }

  return signal;
}

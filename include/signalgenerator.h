#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <cmath>
#include <vector>

// Class to generate signals with adjustable frequency and amplitude
class SignalGenerator {
public:
  SignalGenerator(); // Initialize the signal generator
  void setFrequency(double freq);
  void setAmplitude(double amp);
  std::vector<double> generateSignal(int numSamples);

private:
  double frequency; // Current frequency of the generated signal
  double amplitude; // Current amplitude of the generated signal
};

#endif // SIGNALGENERATOR_H

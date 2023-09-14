#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <vector>
#include <cmath>

class SignalGenerator
{
public:
    SignalGenerator();
    void setFrequency(double freq);
    void setAmplitude(double amp);
    std::vector<double> generateSignal(int numSamples);

private:
    double frequency;
    double amplitude;
};

#endif // SIGNALGENERATOR_H

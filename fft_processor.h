#pragma once

#include <vector>
#include <kiss_fft.h>

class FFTProcessor {
public:
    FFTProcessor(int sampleSize);
    ~FFTProcessor();

    std::vector<double> applyFFT(const std::vector<double>& signal);
    std::vector<double> applyInverseFFT(const std::vector<kiss_fft_cpx>& freqData);
    void applyWindow(std::vector<double>& signal);
    std::vector<double> computeMagnitude(const std::vector<kiss_fft_cpx>& freqData);

private:
    int m_sampleSize;
    kiss_fft_cfg m_cfg;
};

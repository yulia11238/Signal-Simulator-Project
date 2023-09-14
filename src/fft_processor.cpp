#include "fft_processor.h"
#include <cmath> // For cos() and other math functions

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

FFTProcessor::FFTProcessor(int sampleSize) : m_sampleSize(sampleSize) {
    m_cfg = kiss_fft_alloc(m_sampleSize, 0, NULL, NULL);
}

FFTProcessor::~FFTProcessor() {
    free(m_cfg);
}

std::vector<double> FFTProcessor::applyFFT(const std::vector<double>& signal) {
    // Your FFT application code using Kiss FFT here.
    // Convert the time-domain signal into frequency components.
    // For now, just return the same signal. Replace this with actual FFT results.
    return signal;
}

void FFTProcessor::applyWindow(std::vector<double>& signal) {
    for (int i = 0; i < m_sampleSize; ++i) {
        signal[i] *= 0.54 - 0.46 * cos(2 * M_PI * i / (m_sampleSize - 1));
    }
}

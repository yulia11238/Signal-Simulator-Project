#include "fft_processor.h"
#include <cmath>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

// Constructor
FFTProcessor::FFTProcessor(int sampleSize) : m_sampleSize(sampleSize) {
  m_cfg = kiss_fft_alloc(m_sampleSize, 0, NULL, NULL);
}

// Destructor
FFTProcessor::~FFTProcessor() { free(m_cfg); }

// Apply the FFT on the input signal and return the magnitude spectrum
std::vector<double> FFTProcessor::applyFFT(const std::vector<double> &signal) {
  std::vector<kiss_fft_cpx> out(m_sampleSize);
  kiss_fft(m_cfg, reinterpret_cast<const kiss_fft_cpx *>(signal.data()),
           out.data());

  std::vector<double> magnitude = computeMagnitude(out);
  return magnitude;
}

// Perform the inverse FFT using frequency-domain data
std::vector<double>
FFTProcessor::applyInverseFFT(const std::vector<kiss_fft_cpx> &freqData) {
  std::vector<kiss_fft_cpx> timeData(m_sampleSize);
  kiss_fft(m_cfg, freqData.data(), timeData.data());

  std::vector<double> signal(m_sampleSize);
  for (int i = 0; i < m_sampleSize; ++i) {
    signal[i] = timeData[i].r; // consider only real part
  }
  return signal;
}

// Apply a Hamming window to reduce the spectral leakage
void FFTProcessor::applyWindow(std::vector<double> &signal) {
  for (int i = 0; i < m_sampleSize; ++i) {
    signal[i] *= 0.54 - 0.46 * cos(2 * M_PI * i / (m_sampleSize - 1));
  }
}

// Compute the magnitude spectrum from the frequency-domain data
std::vector<double>
FFTProcessor::computeMagnitude(const std::vector<kiss_fft_cpx> &freqData) {
  std::vector<double> magnitude(m_sampleSize);
  for (int i = 0; i < m_sampleSize; ++i) {
    magnitude[i] =
        sqrt(freqData[i].r * freqData[i].r + freqData[i].i * freqData[i].i);
  }
  return magnitude;
}

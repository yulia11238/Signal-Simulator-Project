#pragma once

#include <kiss_fft.h>
#include <vector>

// Class to handle FFT operations
class FFTProcessor {
public:
  FFTProcessor(int sampleSize); // Initialize the FFT processor
  ~FFTProcessor();              // Clean up the allocated resources

  // Convert a time-domain signal to its frequency-domain representation
  std::vector<double> applyFFT(const std::vector<double> &signal);

  // Convert a frequency-domain rep. back to the time-domain signal
  std::vector<double>
  applyInverseFFT(const std::vector<kiss_fft_cpx> &freqData);

  // Reduce spectral leakage
  void applyWindow(std::vector<double> &signal);

  // Calculates the magnitude of the frequency-domain data
  std::vector<double>
  computeMagnitude(const std::vector<kiss_fft_cpx> &freqData);

private:
  int m_sampleSize;   // number of samples used
  kiss_fft_cfg m_cfg; // FFT config object
};

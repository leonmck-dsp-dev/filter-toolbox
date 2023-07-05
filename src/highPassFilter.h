/*
  ==============================================================================
 
    Created: 15 May 2023 1:03:04am
    Author:  leon

  ==============================================================================
*/

#pragma once 
#include "baseFilter.h"

/**
 * @class HighPassFilter
 * @brief A class that implements a high-pass filter.
 * 
 * This class inherits from the BaseFilter class and provides methods to set the filter parameters and process input data.
 */
class HighPassFilter : public BaseFilter{
public:
    /**
     * @brief Sets the parameters of the high-pass filter.
     * 
     * This method calculates the coefficients of the filter based on the center frequency, Q factor, and gain.
     * 
     * @param centerFrequency The center frequency of the filter.
     * @param q The Q factor of the filter. Default value is 0.
     * @param gain The gain of the filter. Default value is 0.
     */
    void setParameters(float centerFrequency, float q = 0, float gain = 0) override {
        float w0 = twopi * centerFrequency / sampleRate;
        float alpha = sin(w0) / (2.0 * Q);

        b0 = (1.0 + cos(w0)) / 2.0;
        b1 = -(1.0 + cos(w0));
        b2 = (1.0 + cos(w0)) / 2.0;
        a0 = 1.0 + alpha;
        a1 = -2.0 * cos(w0);
        a2 = 1.0 - alpha;
    }

    /**
     * @brief Processes the input data using the high-pass filter.
     * 
     * This method applies the filter to the input data and returns the filtered output.
     * 
     * @param input The input data to be filtered.
     * @return The filtered output.
     */
    float process(float input) override{
        float output = b0 / a0 * input + b1 / a0 * x1 + b2 / a0 * x2 - a1 / a0 * y1 - a2 / a0 * y2;

        x2 = x1;
        x1 = input;
        y2 = y1;
        y1 = output;

        return output;
    }

private:
    float b0, b1, b2, a0, a1, a2; // Coefficients of the filter
    float x1, x2, y1, y2; // Delay line variables
    float sampleRate; // The sample rate of the audio signal
    float twopi = M_PI * 2; // Constant value for 2*pi
    static constexpr float Q = 0.6; // Default Q factor for the filter
};
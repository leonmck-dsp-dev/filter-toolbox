/*
  ==============================================================================
 
    Created: 15 May 2023 1:03:04am
    Author:  leon

  ==============================================================================
*/

#pragma once 
#include "baseFilter.h"
/**
 * @class PeakNotchFilter
 * @brief A class that implements a peak/notch filter.
 * 
 * This class inherits from the BaseFilter class and provides methods to set the filter parameters and process audio input.
 */
class PeakNotchFilter : public BaseFilter{
public:
    /**
     * @brief Sets the parameters of the peak/notch filter.
     * 
     * This method calculates the coefficients of the filter based on the given center frequency, Q factor, and gain.
     * 
     * @param centerFrequency The center frequency of the filter.
     * @param q The Q factor of the filter.
     * @param gain The gain of the filter in decibels.
     */
    void setParameters(float centerFrequency, float q, float gain) override{    
        // Calculate angular frequency and alpha
        float w0 = twopi * centerFrequency / sampleRate;
        float alpha = sin(w0) / (2.0 * q);

        // Calculate A
        float A = pow(10.0, gain / 40.0);

        // Calculate coefficients
        b0 = 1.0 + alpha * A;
        b1 = -2.0 * cos(w0);
        b2 = 1.0 - alpha * A; 
        a1 = -2.0 * cos(w0);
        a2 = 1.0 - alpha / A;

        // Adjust coefficients for positive gain
        if (gain >= 0.0)
        {
            b0 = (1.0 + alpha * A) / (1.0 + alpha);
            b1 = (-2.0 * cos(w0)) / (1.0 + alpha);
            b2 = (1.0 - alpha * A) / (1.0 + alpha);
            a0 = (1.0 + alpha / A) / (1.0 + alpha);
            a1 = (-2.0 * cos(w0)) / (1.0 + alpha);
            a2 = (1.0 - alpha / A) / (1.0 + alpha);
        }
    }

    /**
     * @brief Processes the input signal through the peak/notch filter.
     * 
     * This method applies the filter coefficients to the input signal and returns the filtered output.
     * 
     * @param input The input signal to be filtered.
     * @return The filtered output signal.
     */
    float process(float input) override{
        // Calculate the filtered output
        float output = b0 / a0 * input + b1 / a0 * x1 + b2 / a0 * x2 - a1 / a0 * y1 - a2 / a0 * y2;

        // Update state variables
        x2 = x1;
        x1 = input;
        y2 = y1;
        y1 = output;

        return output;
    }

private:
    float sampleRate; // The sample rate of the audio signal
    float twopi = M_PI * 2; // The value of 2 * pi
    float b0, b1, b2, a0, a1, a2; // The filter coefficients
    float x1, x2, y1, y2; // The state variables for the filter
};

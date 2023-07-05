/*
  ==============================================================================
 
    Created: 15 May 2023 1:03:04am
    Author:  leon

  ==============================================================================
*/
#include "baseFilter.h"

class PeakNotchFilter : public BaseFilter
{
public:
    void setParameters(float centerFrequency, float q, float gain) override
    {
        float w0 = twopi * centerFrequency / sampleRate;
        float alpha = sin(w0) / (2.0 * q);

        float A = pow(10.0, gain / 40.0);

//        float beta = sqrt(A) / q;/./

        b0 = 1.0 + alpha * A;
        b1 = -2.0 * cos(w0);
        b2 = 1.0 - alpha * A; 
        a1 = -2.0 * cos(w0);
        a2 = 1.0 - alpha / A;

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

    float process(float input) override
    {
        float output = b0 / a0 * input + b1 / a0 * x1 + b2 / a0 * x2 - a1 / a0 * y1 - a2 / a0 * y2;

        x2 = x1;
        x1 = input;
        y2 = y1;
        y1 = output;

        return output;
    }

private:
    float sampleRate;
    float twopi = M_PI * 2;
    float b0, b1, b2, a0, a1, a2;
    float x1, x2, y1, y2;
}; 
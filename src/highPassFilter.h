/*
  ==============================================================================
 
    Created: 15 May 2023 1:03:04am
    Author:  leon

  ==============================================================================
*/
#include "baseFilter.h"


class HighPassFilter : public BaseFilter
{
public:
     
    void setParameters(float centerFrequency, float q = 0, float gain = 0) override
    {
        float w0 = twopi * centerFrequency / sampleRate;
        float alpha = sin(w0) / (2.0 * Q);

        b0 = (1.0 + cos(w0)) / 2.0;
        b1 = -(1.0 + cos(w0));
        b2 = (1.0 + cos(w0)) / 2.0;
        a0 = 1.0 + alpha;
        a1 = -2.0 * cos(w0);
        a2 = 1.0 - alpha;
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
    float b0, b1, b2, a0, a1, a2;
    float x1, x2, y1, y2;
    float sampleRate;
    float twopi = M_PI * 2;
    static constexpr float Q = 0.6;
};
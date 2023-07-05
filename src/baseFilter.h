/*
  ==============================================================================

    filters.h
    Created: 15 May 2023 1:03:04am
    Author:  leon

  ==============================================================================
*/

#pragma once 
#define _USE_MATH_DEFINES
#include <cmath>
 
class BaseFilter {
public:
    virtual void setParameters(float centerFrequency, float q, float gain)= 0;
    virtual float process(float input) = 0;
 
protected:
    float sampleRate;
    float b0, b1, b2, a0, a1, a2;
    float x1, x2, y1, y2;
    static constexpr float Q = 0.6;
};


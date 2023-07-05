/*
  ==============================================================================
 
    Created: 15 May 2023 1:03:04am
    Author:  leon

  ==============================================================================
*/

#pragma once 
#include "baseFilter.h"

/**
 * @class DCBlockerFilter
 * @brief A class that implements a DC blocker filter.
 * 
 * The DCBlockerFilter class is a derived class of the BaseFilter class. It implements a DC blocker filter that removes the DC component from an input signal.
 */
class DCBlockerFilter : public BaseFilter {
public:
    /**
     * @brief Constructor for the DCBlockerFilter class.
     * @param alpha The alpha value used in the filter calculation.
     * 
     * This constructor initializes the DCBlockerFilter object with the given alpha value and sets the previous input and output values to 0.0.
     */
    DCBlockerFilter(double alpha) : alpha_(alpha), prev_output_(0.0) {}
    
    /**
     * @brief Process function for the DCBlockerFilter class.
     * @param input The input value to be processed by the filter.
     * @return The filtered output value.
     * 
     * This function calculates the filtered output value by subtracting the previous input value from the current input value, adding the alpha value multiplied by the previous output value, and updating the previous input and output values. The calculated output value is then returned.
     */
    float process(float input) override {
        float output = input - prev_input_ + alpha_ * prev_output_;
        prev_input_ = input;
        prev_output_ = output;
        return output;
    }

private:
    float alpha_; /**< The alpha value used in the filter calculation. */
    float prev_input_ = 0.0; /**< The previous input value. Initialized to 0.0. */
    float prev_output_ = 0.0; /**< The previous output value. Initialized to 0.0. */
};
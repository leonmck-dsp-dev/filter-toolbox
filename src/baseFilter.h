/*
  ==============================================================================

    filters.h
    Created: 15 May 2023 1:03:04am
    Author:  leon

  ==============================================================================
*/
/**
 * @file BaseFilter.h
 *
 * @brief This file contains the declaration of the BaseFilter class.
 */

#pragma once

/** 
 * @def _USE_MATH_DEFINES
 *
 * @brief This macro is used to enable the definition of mathematical constants, such as M_PI.
 */

#include <cmath>

/**
 * @class BaseFilter
 *
 * @brief This class represents a base filter.
 *
 * The BaseFilter class is an abstract class that provides a common interface for all filters.
 * It defines pure virtual functions for setting filter parameters and processing input data.
 * It also contains protected member variables for storing filter coefficients and previous input/output values.
 * The class also defines a static constexpr float Q constant with a default value of 0.6.
 */
class BaseFilter {
public:
    /**
     * @brief Sets the filter parameters.
     *
     * @param centerFrequency The center frequency of the filter.
     * @param q The Q factor of the filter.
     * @param gain The gain of the filter.
     */
    virtual void setParameters(float centerFrequency, float q, float gain) = 0;

    /**
     * @brief Processes the input data.
     *
     * @param input The input data to be processed.
     *
     * @return The processed output data.
     */
    virtual float process(float input) = 0;

protected:
    float sampleRate; /**< The sample rate of the audio signal. */
    float b0, b1, b2, a0, a1, a2; /**< The filter coefficients. */
    float x1, x2, y1, y2; /**< The previous input/output values. */
    static constexpr float Q = 0.6; /**< The default Q factor of the filter. */
};
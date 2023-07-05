/*
  ==============================================================================
 
    Created: 15 May 2023 1:03:04am
    Author:  leon

  ==============================================================================
*/
#include "baseFilter.h"


class DCBlockerFilter : public BaseFilter {
public:
    DCBlockerFilter(double alpha) : alpha_(alpha), prev_output_(0.0) {}
    
      
    float process(float input) override
    {
        float output = input - prev_input_ + alpha_ * prev_output_;
        prev_input_ = input;
        prev_output_ = output;
        return output;
    }

private:
    float alpha_;
    float prev_input_ = 0.0;
    float prev_output_ = 0.0;
};
 
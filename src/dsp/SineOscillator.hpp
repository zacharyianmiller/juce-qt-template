#pragma once

#include "Processor.hpp"

struct SineOscillator : public millerlabs::dsp::Processor<float>
{
public:
    SineOscillator();
    void process(const float* inbuf, float* outbuf) override;
private:
    void step();

    static const float freq;
    static const float amp;
    float currentStep;
};
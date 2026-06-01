#include "SineOscillator.hpp"
#include <juce_core/juce_core.h>

const float SineOscillator::freq = 125.f;
const float SineOscillator::amp = 0.75f;

SineOscillator::SineOscillator() :
currentStep(0.f)
{

}

void SineOscillator::process(const float* /*inbuf*/, float* outbuf)
{
    for (int n = 0; n < blockSize; ++n)
    {
        const float angle = juce::MathConstants<float>::twoPi * currentStep * freq;
        outbuf[n] = amp * std::sin(angle);

        step();
    }
}

void SineOscillator::step()
{
    // Increment sampling period accumulator
    const float ts = 1.f / static_cast<float>(sampleRate);
    currentStep += ts;

    // Wrap accumulator according to sampling rate
    if (currentStep >= 1.f) 
        currentStep -= 1.f;
}
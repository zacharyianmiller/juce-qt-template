#include "Processor.hpp"

namespace millerlabs::dsp
{

template<typename AudioFloatType>
void Processor<AudioFloatType>::prepare(double _sampleRate, int _blockSize)
{
    this->sampleRate = _sampleRate;
    this->blockSize = _blockSize;
}

template class Processor<float>;
template class Processor<double>;

}; // namespace millerlabs::dsp
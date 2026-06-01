namespace millerlabs::dsp
{

template<typename AudioFloatType>
class Processor
{
public:
    virtual ~Processor() = default;
    virtual void prepare(double sampleRate, int blockSize);
    virtual void process(const AudioFloatType* inbuf, AudioFloatType* outbuf) = 0;
protected:
    double sampleRate;
    int blockSize;
};

} // namespace millerlabs::dsp
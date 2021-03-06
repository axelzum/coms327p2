#ifndef SOUNDSAMPLES_H
#define SOUNDSAMPLES_H

class SoundSamples {
    public:
        SoundSamples();
        SoundSamples(float* samples, int length, float rate);
        SoundSamples(int length, float rate);
        SoundSamples(const SoundSamples& objToCopy);
        SoundSamples& operator=(const SoundSamples& objToCopy);
        float& operator[](const int& rhs);
        SoundSamples operator+(const SoundSamples& rhs);
        float* getSampleList() const;
        void setSampleList(float* newSampleList, int size);
        int getNumSamples() const;
        void setNumSamples(int newNumSamples);
        float getSampleRate() const;
        void setSampleRate(int newSampleRate);
        void reverb2(float delay, float attenuation);
        void adsr(float atime, float alevel, float dtime, float slevel, float rtime);
    private:
        float* sampleList;
        int numSamples;
        float sampleRate;
};

#endif

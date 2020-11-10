#ifndef WAVE_H
#define WAVE_H

#include "SoundSamples.h"

#include <string>
using namespace std;

class Wave {
    public:
        Wave(string name);
        SoundSamples* generateSamples(float frequency, float samplerate, float duration);
        virtual float generateFunction(float time) = 0;
        string getWaveName() const;
    private:
        string waveName;
};

class SineWave : public Wave {
    public:
        SineWave(string name);
        float generateFunction(float time);
};

class SquareWave : public Wave {
    public:
        SquareWave(string name);
        float generateFunction(float time);
};

class TriangleWave : public Wave {
    public:
        TriangleWave(string name);
        float generateFunction(float time);
};

class SawtoothWave : public Wave {
    public:
        SawtoothWave(string name);
        float generateFunction(float time);
};

#endif

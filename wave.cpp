#include "wave.h"
#include "SoundSamples.h"

#include <iostream>
#include <cmath>

Wave::Wave(string name) {
    waveName = name;
}

SoundSamples* Wave::generateSamples(float frequency, float sample_rate, float duration) {
    float outputSamples = sample_rate * duration;
    SoundSamples *output =  new SoundSamples((int)outputSamples, sample_rate);

    float* temp = new float[(int)outputSamples];

    float radians = 0.0;
    for(int i = 0; i < outputSamples; i++) {
        temp[i] = generateFunction(radians * frequency);
        radians += 1.0 / sample_rate;
    }

    output->setSampleList(temp, (int)outputSamples);
    delete[] temp;
    return output;
}

string Wave::getWaveName() const {
    return waveName;
}

SineWave::SineWave(string name) : Wave(name) {
}

float SineWave::generateFunction(float time) {
    return sin(time);
}

SquareWave::SquareWave(string name) : Wave(name) {
}

float SquareWave::generateFunction(float time) {
    float t = time - (int) time;
    if (t < 0.5) {
        return -1.0;
    }
    else {
        return 1.0;
    }
}

TriangleWave::TriangleWave(string name) : Wave(name) {
}

float TriangleWave::generateFunction(float time) {
    float t = time - (int) time;
    if (t < 0.5) {
        return 4 * t - 1;
    }
    else {
        return -4 * t + 3;
    }
}

SawtoothWave::SawtoothWave(string name) : Wave(name) {
}

float SawtoothWave::generateFunction(float time) {
    //todo
    return 0;
}

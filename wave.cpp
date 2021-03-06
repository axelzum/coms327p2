#include "wave.h"
#include "SoundSamples.h"

#include <iostream>
#include <cmath>

Wave::Wave(string name) {
    waveName = name;
}

/*
 *  Generates a wave of this objects type with specified frequency, rate, and duration
 */
SoundSamples* Wave::generateSamples(float frequency, float sample_rate, float duration) {
    float outputSamples = sample_rate * duration;
    SoundSamples *output =  new SoundSamples((int)outputSamples, sample_rate);

    float* temp = new float[(int)outputSamples];

    float time = 0.0;
    for(int i = 0; i < outputSamples; i++) {
        temp[i] = generateFunction(time * frequency);
        time += 1.0 / sample_rate;
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

/*
 *  Generates a sine wave
 */
float SineWave::generateFunction(float time) {
    return sin(2 * M_PI * time);
}

SquareWave::SquareWave(string name) : Wave(name) {
}

/*
 *  Generates a square wave
 */
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

/*
 *  Generates a triangle wave
 */
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

/*
 *  Generates a sawtooth wave
 */
float SawtoothWave::generateFunction(float time) {
    float t = time - (int) time;
    return 2 * t - 1;
}

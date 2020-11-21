#include "SoundSamples.h"

#include <iostream>
using namespace std;

SoundSamples::SoundSamples() : numSamples(0), sampleRate(8000) {
    sampleList = new float[0];
}

SoundSamples::SoundSamples(float* samples, int length, float rate) :
    numSamples(length),
    sampleRate(rate) {
        sampleList = new float[length];
        for (int i = 0; i < length; i++) {
            sampleList[i] = samples[i];
        }
}

SoundSamples::SoundSamples(int length, float rate) :
    sampleList(new float[length]),
    numSamples(length),
    sampleRate(rate) {
        for (int i = 0; i < length; i++) {
            sampleList[i] = 0;
        }
}

SoundSamples::SoundSamples(const SoundSamples& objToCopy) :
    sampleList(new float[objToCopy.numSamples]),
    numSamples(objToCopy.numSamples),
    sampleRate(objToCopy.sampleRate) {
        for (int i = 0; i < objToCopy.numSamples; i++) {
            sampleList[i] = objToCopy.sampleList[i];
        }
}

SoundSamples& SoundSamples::operator=(const SoundSamples& objToCopy) {
    if (this != &objToCopy) {
        delete[] sampleList;
        sampleRate = objToCopy.sampleRate;
        numSamples = objToCopy.numSamples;
        sampleList = new float[objToCopy.numSamples];
        for (int i = 0; i < objToCopy.numSamples; i++) {
            sampleList[i] = objToCopy.sampleList[i];
        }
    }
    return *this;
}

float& SoundSamples::operator[](const int& index) {
    if (index < 0 || index > numSamples-1) {
        throw out_of_range("Index is out of the bounds of the sampleList.");
    }

    return sampleList[index];
}

SoundSamples SoundSamples::operator+(const SoundSamples& rhs) {
    if (sampleRate != rhs.sampleRate) {
        throw runtime_error("SoundSamples addition operands do not have the same sample rate.");
    }

    SoundSamples combined = SoundSamples(numSamples+rhs.numSamples, sampleRate);

    int i;
    for (i = 0; i < numSamples; i++) {
        combined.sampleList[i] = sampleList[i];
    }
    for (i = 0; i < numSamples + rhs.numSamples; i++) {
        combined.sampleList[i + numSamples] = rhs.sampleList[i];
    }

    return combined;
}

float* SoundSamples::getSampleList() const {
    return sampleList;
}

void SoundSamples::setSampleList(float* newSampleList, int size) {
    delete[] sampleList;
    sampleList = new float[size];
    for (int i = 0; i < size; i++) {
        sampleList[i] = newSampleList[i];
    }
}

int SoundSamples::getNumSamples() const {
    return numSamples;
}

void SoundSamples::setNumSamples(int newNumSamples) {
    numSamples = newNumSamples;
}

float SoundSamples::getSampleRate() const{
    return sampleRate;
}

void SoundSamples::setSampleRate(int newSampleRate) {
    sampleRate = newSampleRate;
}

void SoundSamples::reverb2(float delay, float attenuation) {
    float* newSamples = new float[numSamples];
    for (int i = 0; i < numSamples; i++) {
        int sdelay = i - (delay * sampleRate);
        if (sdelay >= 0) {
            newSamples[i] = sampleList[i] + newSamples[sdelay] * attenuation;
        }
        else {
            newSamples[i] = sampleList[i];
        }
    }
    setSampleList(newSamples, numSamples);
    delete[] newSamples;
}

void SoundSamples::adsr(float atime, float alevel, float dtime, float slevel, float rtime) {
    if ((atime + dtime + rtime) > (sampleRate * numSamples)) {
        throw runtime_error("ADSR time values are greater than the length of the sound sample. Try smaller values.");
    }
    if (atime < 0 || dtime < 0 || rtime < 0) {
        throw runtime_error("One of the time values is less than zero.");
    }
    if (alevel < 0 || slevel < 0) {
        throw runtime_error("One of the level values is less than zero.");
    }

    float* newSamples = new float[numSamples];
    for (int i = 0; i < numSamples; i++) {
        newSamples[i] = sampleList[i];
    }

    int i;
    float level = 0;
    int asamples = atime * sampleRate;
    for (i = 0; i < asamples; i++) {
        newSamples[i] *= level;
        level += alevel / asamples;
    }
    int dsamples = dtime * sampleRate;
    for (i = i; i < asamples + dsamples; i++) {
        newSamples[i] *= level;
        level -= (alevel - slevel) / dsamples;
    }
    int rsamples = rtime * sampleRate;
    for (i = i; i < (numSamples - rsamples) - 1; i++) {
        newSamples[i] *= level;
    }
    for (i = i; i < numSamples; i++) {
        newSamples[i] *= level;
        level -= slevel / rsamples;
    }
    setSampleList(newSamples, numSamples);
    delete[] newSamples;
}

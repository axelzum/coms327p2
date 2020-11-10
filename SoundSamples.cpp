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

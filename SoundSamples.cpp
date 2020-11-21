#include "SoundSamples.h"

#include <iostream>
using namespace std;

/*
 *  Default SoundSamples constructor. No samples at a sample rate of 8000.
 */
SoundSamples::SoundSamples() : numSamples(0), sampleRate(8000) {
    sampleList = new float[0];
}

/*
 *  Constructs a SoundSamples object already filled with samples at a given rate.
 */
SoundSamples::SoundSamples(float* samples, int length, float rate) :
    numSamples(length),
    sampleRate(rate) {
        sampleList = new float[length];
        for (int i = 0; i < length; i++) {
            sampleList[i] = samples[i];
        }
}

/*
 *  Constructs a SoundSamples object of a given length and rate of silence (zeros)
 */
SoundSamples::SoundSamples(int length, float rate) :
    sampleList(new float[length]),
    numSamples(length),
    sampleRate(rate) {
        for (int i = 0; i < length; i++) {
            sampleList[i] = 0;
        }
}

/*
 *  SoundSamples copy constructor.
 */
SoundSamples::SoundSamples(const SoundSamples& objToCopy) :
    sampleList(new float[objToCopy.numSamples]),
    numSamples(objToCopy.numSamples),
    sampleRate(objToCopy.sampleRate) {
        for (int i = 0; i < objToCopy.numSamples; i++) {
            sampleList[i] = objToCopy.sampleList[i];
        }
}

/*
 *  SoundSamples = operator
 */
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

/*
 *  SoundSamples [] operator
 */
float& SoundSamples::operator[](const int& index) {
    if (index < 0 || index > numSamples-1) {
        throw out_of_range("Index is out of the bounds of the sampleList.");
    }

    return sampleList[index];
}

/*
 *  SoundSamples + operator creates a new SoundSamples of the first appended with the second SoundSamples.
 */
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

/*
 *  Resize the SoundSamples object and give a new list of samples.
 */
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

/*
 *  Adds a reverb effect to the sound samples in this object given a delay and attenuation.
 */
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

/*
 *  Adds an adsr effect to the SoundSamples object.
 */
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
    //Multiplier for attack
    int asamples = atime * sampleRate;
    for (i = 0; i < asamples; i++) {
        newSamples[i] *= level;
        level += alevel / asamples;
    }
    //Multiplier for decay
    int dsamples = dtime * sampleRate;
    for (i = i; i < asamples + dsamples; i++) {
        newSamples[i] *= level;
        level -= (alevel - slevel) / dsamples;
    }
    //Multiplier for sustain
    int rsamples = rtime * sampleRate;
    for (i = i; i < (numSamples - rsamples) - 1; i++) {
        newSamples[i] *= level;
    }
    //Multiplier for release
    for (i = i; i < numSamples; i++) {
        newSamples[i] *= level;
        level -= slevel / rsamples;
    }
    setSampleList(newSamples, numSamples);
    delete[] newSamples;
}

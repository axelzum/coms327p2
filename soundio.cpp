#include "SoundSamples.h"
#include "soundio.h"

#include <iostream>
#include <fstream>

void SoundIO::OutputSound(SoundSamples *samples, string filename) {
    ofstream file;
    file.open(filename);

    if (!file.is_open()) {
        throw runtime_error("Unable to open file.");
    }

    for (int i = 0; i < samples->getNumSamples(); i++) {
        file << samples->getSampleList()[i] << endl;
    }

    file.close();
}

void SoundIO::OutputSoundStream(SoundSamples *samples, string filename) {
    ofstream file;
    file.open(filename, ofstream::out | ofstream::app);

    if (!file.is_open()) {
        throw runtime_error("Unable to open file.");
    }

    for (int i = 0; i < samples->getNumSamples(); i++) {
        cout << samples->getSampleList()[i] << endl;
        file << samples->getSampleList()[i] << endl;
    }

    file.close();
}

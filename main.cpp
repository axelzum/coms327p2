#include "SoundSamples.h"
#include "wave.h"

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {
    cout << "Part2 Tests" << endl;


    Wave *w = new SineWave("MySineWave");
    SoundSamples *s = w->generateSamples(400, 8000, 2.5);

    cout << w->getWaveName() << endl;
    for (int i = 0; i < s->getNumSamples(); i++) {
        cout << s->getSampleList()[i] << endl;
    }



    /*
    cout << "Part1 Tests" << endl;

    float samps[5] = {1,2,3,4,5};
    SoundSamples sounds = SoundSamples(samps, 5, 8000);
    SoundSamples sounds2 = sounds;

    float samps2[6] = {0,1,2,3,4,5};
    sounds2.setNumSamples(6);
    sounds2.setSampleRate(5000);
    sounds2.setSampleList(samps2);

    cout << sounds.getNumSamples() << endl;
    cout << sounds.getSampleRate() << endl;
    cout << sounds2. getNumSamples() << endl;
    cout << sounds2.getSampleRate() << endl;

    for (int i = 0; i < sounds.getNumSamples(); i++) {
        cout << sounds.getSampleList()[i] << endl;
    }

    for (int i = 0; i < sounds2.getNumSamples(); i++) {
        cout << sounds2.getSampleList()[i] << endl;
    }

    cout << endl << endl;

    sounds2[0] = 6969;
    sounds2[5] = 420;

    for (int i = 0; i < sounds2.getNumSamples(); i++) {
        cout << sounds2[i] << endl;
    }

    cout << endl << endl;
    sounds.setSampleRate(5000);
    SoundSamples combined = sounds + sounds2;
    for (int i = 0; i < combined.getNumSamples(); i++) {
        cout << combined[i] << endl;
    }
    */

    return 0;
}

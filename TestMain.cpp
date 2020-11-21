#include "SoundSamples.h"
#include "wave.h"
#include "soundio.h"

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {

    /*
    cout << "Part1 Tests" << endl;

    float samps[16] = {.1,.2,.3,.2,.1,0,0,.1,.2,.2,.1,.2,.3,.3,.2,.1};
    SoundSamples sounds = SoundSamples(samps, 16, 2);

    for (int i = 0; i < sounds.getNumSamples(); i++) {
        cout << sounds.getSampleList()[i] << endl;
    }

    sounds.reverb2(2, 0.2);
    cout << endl << endl;

    for (int i = 0; i < sounds.getNumSamples(); i++) {
        cout << sounds.getSampleList()[i] << endl;
    }
    */

    /*
    cout << "Part2 Tests" << endl;

    float samps[17] = {.4,.3,.2,.2,.1,.2,.3,.2,.2,.1,.5,.1,.2,.3,.4,.4,.3};
    SoundSamples sounds = SoundSamples(samps, 17, 1);

    for (int i = 0; i < sounds.getNumSamples(); i++) {
        cout << sounds.getSampleList()[i] << endl;
    }

    sounds.adsr(4,0.5,4,0.25,4);
    cout << endl << endl;

    for (int i = 0; i < sounds.getNumSamples(); i++) {
        cout << sounds.getSampleList()[i] << endl;
    }
    */

    return 0;
}

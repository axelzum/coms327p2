#include "SoundSamples.h"
#include "wave.h"
#include "soundio.h"

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {

    int wave;
    float sample_rate, frequency, duration;
    string filename;

    cout << "Input wave type (1 ,2, 3, or 4):" << endl;
    cin >> wave;
    cout << "Input sample rate:" << endl;
    cin >> sample_rate;
    cout << "Input frequency:" << endl;
    cin >> frequency;
    cout << "Input duration:" << endl;
    cin >> duration;
    cout << "Input filename:" << endl;
    cin >> filename;

    if (wave == 1) {
        Wave *w = new SineWave("MySineWave");
        SoundSamples *s = w->generateSamples(frequency, sample_rate, duration);
        SoundIO::OutputSound(s, filename);
    }
    else if (wave == 2) {
        Wave *w = new SquareWave("MySquareWave");
        SoundSamples *s = w->generateSamples(frequency, sample_rate, duration);
        SoundIO::OutputSound(s, filename);
    }
    else if (wave == 3) {
        Wave *w = new TriangleWave("MyTriangleWave");
        SoundSamples *s = w->generateSamples(frequency, sample_rate, duration);
        SoundIO::OutputSound(s, filename);
    }
    else if (wave == 4) {
        Wave *w = new SawtoothWave("MySawWave");
        SoundSamples *s = w->generateSamples(frequency, sample_rate, duration);
        SoundIO::OutputSound(s, filename);
    }

    return 0;

    /*

    Wave *w = new TriangleWave("MySineWave");
    SoundSamples *s = w->generateSamples(5, 12, 1);

    cout << w->getWaveName() << endl;
    for (int i = 0; i < s->getNumSamples(); i++) {
        cout << s->getSampleList()[i] << endl;
    }

    SoundIO::OutputSound(s, "out.txt");
    */



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
}

#include "SoundSamples.h"
#include "wave.h"
#include "soundio.h"

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {

    int wave;
    float delay, attenuation, atime, alevel, dtime, slevel, rtime;
    string filename;

    cout << "Input wave type (1 (Sine), 2 (Square), 3 (Triangle), or 4(Saw)):" << endl;
    cin >> wave;
    while (wave < 1 || wave > 4) {
        cout << "Invalid wave type. Input a number 1-4." << endl;
        cin >> wave;
    }
    cout << "Input Delay:" << endl;
    cin >> delay;
    cout << "Input Attenuation:" << endl;
    cin >> attenuation;
    cout << "Input Attack Time:" << endl;
    cin >> atime;
    cout << "Input Attack Level:" << endl;
    cin >> alevel;
    cout << "Input Decay Time:" << endl;
    cin >> dtime;
    cout << "Input Sustain Level:" << endl;
    cin >> slevel;
    cout << "Input Release Time:" << endl;
    cin >> rtime;
    cout << "Input filename:" << endl;
    cin >> filename;

    Wave *w;
    if (wave == 1) {
        w = new SineWave("MySineWave");
    }
    else if (wave == 2) {
        w = new SquareWave("MySquareWave");
    }
    else if (wave == 3) {
        w = new TriangleWave("MyTriangleWave");
    }
    else if (wave == 4) {
        w = new SawtoothWave("MySawWave");
    }

    SoundSamples *output = new SoundSamples(0, 44100);
    SoundIO::OutputSound(output, filename);
    delete output;
    int keyNumber;
    cout << "Input a note number or a negative number to output notes to the file." << endl;
    cin >> keyNumber;
    while (keyNumber >= 0) {
        float frequency = pow(2,(keyNumber-49)/12) * 440;
        SoundSamples *note = w->generateSamples(frequency, 44100, 1);
        note->reverb2(delay, attenuation);
        note->adsr(atime, alevel, dtime, slevel, rtime);
        SoundIO::OutputSoundStream(note, filename);
        SoundSamples *silence = new SoundSamples(0.25 * 44100, 44100);
        SoundIO::OutputSoundStream(silence, filename);
        delete silence;
        cout << "Input a note number or a negative number to output notes to the file." << endl;
        cin >> keyNumber;
    }

    return 0;
}

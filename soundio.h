#ifndef SOUNDIO_H
#define SOUNDIO_H

#include <string>
using namespace std;

class SoundIO {
    public:
        static void OutputSound(SoundSamples *samples, string filename);
        static void OutputSoundStream(SoundSamples *samples, string filename);
};

#endif

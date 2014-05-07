#include "Som.h"

Som::Som(string end)
{
    if(!som.openFromFile(end)) {
        cout << "O arquivo " << end << " não existe!" << endl;
    }

    som.setVolume(20);
}

void Som::play() {
    if(som.getStatus() != som.Playing)
        som.play();
}

void Som::pause() {
    if(som.getStatus() != som.Paused)
        som.pause();
}

void Som::stop() {
    if(som.getStatus() != som.Stopped)
        som.stop();
}

void Som::setVolume(float volume) {
    som.setVolume(volume);
}

int Som::getVolume() {
    return som.getVolume();
}

void Som::setLoop(bool loop) {
    som.setLoop(loop);
}

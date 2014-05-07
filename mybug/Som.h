#ifndef SOM_H
#define SOM_H

#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class Som
{
private:
    Music som;

public:
    Som(string);
    void play();
    void pause();
    void stop();
    void setVolume(float);
    int getVolume();
    void setLoop(bool);
};

#endif // SOM_H

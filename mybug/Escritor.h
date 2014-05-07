#ifndef ESCRITOR_H
#define ESCRITOR_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Janela.h"

using namespace std;
using namespace sf;

class Escritor
{
private:
    float size;
    sf::Font f;
    Color color;

public:
    Escritor();
    void setSize(int size);
    void setFont(string font);
    void setColor(Color c);
    void write(int x, int y, string texto);
};

#endif // ESCRITOR_H

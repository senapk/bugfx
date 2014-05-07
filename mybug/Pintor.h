#ifndef PINTOR_H
#define PINTOR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Janela.h"
#include "math.h"

using namespace std;
using namespace sf;

class Pintor
{
private:
    Color color;
    Color fillColor;
    int thickness;

public:
    Pintor();

    void setThickness(int t);
    void setColor(Color c);
    void setFillColor(Color c);

    void drawCircle(int x, int y, int radius);
    void drawRect(int x, int y, int width, int height);
    void drawLine(float x1, float y1, float x2, float y2);
    void drawPoint(int x, int y);
};

#endif // PINTOR_H

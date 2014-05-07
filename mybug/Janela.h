#ifndef JANELA_H
#define JANELA_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Constantes.h"
#include "Util.h"

using namespace sf;
using namespace std;

class Imagem;

class Janela
{
private:
    Color backGroundColor;
    Timer timer;

public:
    static RenderWindow janela;

    Janela(int, int, string);
    void setBackgroundColor(Color c);
    void clear();
    void update();
    void setIcon(Imagem *i);
    bool keyPressed(Keyboard::Key);
    bool keyDown(Keyboard::Key);
    char getKeyChar();
    void getMousePosition(int&, int&);
    void getMousePosition(int&, int&, Janela);
    int getMouseX();
    int getMouseY();
    int getMouseX(Janela);
    int getMouseY(Janela);
    void setMousePosition(int x, int y);
    void setMousePosition(int x, int y, Janela);
    void setMouseX(int x);
    void setMouseY(int y);
    void setMouseX(int x, Janela);
    void setMouseY(int y, Janela);
    bool mousePressed(Mouse::Button);
    bool mouseWeelMovedUp();
    bool mouseWeelMovedDown();

    bool isOpen();
    long alive();
};

#endif // JANELA_H

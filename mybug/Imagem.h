#ifndef IMAGEM_H
#define IMAGEM_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Janela.h"

using namespace std;
using namespace sf;

class Imagem
{
public:
    Image imagem;
    Texture textura;
    Sprite sprite;

    Imagem();
    Imagem(string path, int largura = 0, int altura = 0);
    void load(string path, int largura = 0, int altura = 0);
    void draw(int, int);
    void rotate(int);
    void flipLeft();
    void flipRight();
    void setSize(int x, int y);
    void zoom(float h, float v);
    bool intersects(Imagem im);
    FloatRect getRect();
    Image getImage();

    int getWidth();
    int getHeight();
};

#endif // IMAGEM_H

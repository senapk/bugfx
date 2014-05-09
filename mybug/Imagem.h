#ifndef IMAGEM_H
#define IMAGEM_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Janela.h"

using namespace std;
using namespace sf;

class Desenhavel{
    public:
    virtual void draw(int, int) = 0;
    virtual void setSize(int x, int y) = 0;
    virtual void rotate(int angle) = 0;
};


class Imagem : public Desenhavel{
public:
    Image imagem;
    Texture textura;
    Sprite sprite;
    string path;

    Imagem();
    Imagem(const Imagem &im);
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

    int getWidth() const;
    int getHeight() const;
};

#endif // IMAGEM_H

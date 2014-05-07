#include "Pintor.h"

Pintor::Pintor()
{
    color = Color(0, 0, 0);
    fillColor = Color(0, 0, 0);
    thickness = 1;
}

void Pintor::setThickness(int t) {
    thickness = t;
}

void Pintor::setColor(Color c) {
    color = c;
}

void Pintor::setFillColor(Color c) {
    fillColor = c;
}

void Pintor::drawCircle(int x, int y, int radius) {
    CircleShape c;
    c.setRadius(radius);
    c.setFillColor(fillColor);
    c.setOutlineColor(color);
    c.setOutlineThickness(thickness);
    c.setPosition(x, y);
    Janela::janela.draw(c);
}

void Pintor::drawRect(int x, int y, int largura, int altura) {
    RectangleShape r;
    r.setSize(Vector2f(largura, altura));
    r.setFillColor(fillColor);
    r.setOutlineColor(color);
    r.setOutlineThickness(thickness);
    r.setPosition(x, y);
    Janela::janela.draw(r);
}

void Pintor::drawLine(float x1, float y1, float x2, float y2) {
    float angulo;
    float largura = sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2) );

    if((x1 - x2) < 0.1 && (x1 - x2) > -0.1) {

        angulo = 90;

    } else {

        float tg = (y1 - y2)/(x1 - x2);
        angulo = atan(tg);
        angulo = angulo*180/3.141592;

    }

    RectangleShape r;
    r.setSize(Vector2f(largura, thickness));
    r.setFillColor(color);
    r.setOutlineThickness(0);
    r.setOrigin(largura/2, thickness/2);
    r.setPosition((x1 + x2)/2, (y1+y2)/2);
    r.setRotation(angulo);
    Janela::janela.draw(r);
}

void Pintor::drawPoint(int x1, int y1) {

    Vertex line[] = {Vertex(Vector2f(x1, y1), color)};

    Janela::janela.draw(line, thickness, Lines);
}

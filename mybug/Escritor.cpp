#include "Escritor.h"

Escritor::Escritor()
{
    f.loadFromFile("/usr/local/share/fonts/UbuntuMono-R.ttf");
    size = 10;
    color = Color::White;
}

void Escritor::setSize(int size) {
    this->size = size;
}

void Escritor::setFont(string font) {
    f.loadFromFile(font);
}

void Escritor::setColor(Color c) {
    color = c;
}

void Escritor::write(int x, int y, string texto) {
    sf::Text t;
    t.setString(texto);
    t.setFont(f);
    t.setColor(color);
    t.setScale((size/10)*t.getScale().x, (size/10)*t.getScale().y);
    t.setPosition(x, y);
    Janela::janela.draw(t);
}

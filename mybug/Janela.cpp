#include "Janela.h"
#include "Imagem.h"
#include "Util.h"
RenderWindow Janela::janela;

Janela::Janela(int largura, int altura, string nome)
{
    janela.create(VideoMode(largura, altura), nome);
    janela.setFramerateLimit(FRAMERATE);
    backGroundColor = Color(0, 0, 0);
    timer.update();
    Util::srand();
}

long Janela::alive(){
    return timer.howLong();
}

void Janela::setBackgroundColor(Color c) {
    backGroundColor = c;
}

void Janela::clear() {
    janela.clear(backGroundColor);
}

void Janela::update() {
    janela.display();

    Event event;
    if(janela.pollEvent(event)) {
        if(event.type == Event::Closed) {
            janela.close();
        }
    }
}

bool Janela::isOpen() {
    return janela.isOpen();
}

void Janela::setIcon(Imagem *i) {
    janela.setIcon(128, 128, i->getImage().getPixelsPtr());
}

bool Janela::keyPressed(Keyboard::Key k) {
    Event event;
    if(janela.pollEvent(event))
        if(event.type == event.KeyPressed)
            return k == event.key.code;
    return false;
}

bool Janela::keyDown(Keyboard::Key k) {
    return Keyboard::isKeyPressed(k);
}

char Janela::getKeyChar() {
    Event e;
    if(janela.pollEvent(e)) {
        if(e.type == Event::TextEntered)
            return e.text.unicode;
    }

    return '\0';
}

void Janela::getMousePosition(int &x, int &y) {
    x = getMouseX();
    y = getMouseY();
}

void Janela::getMousePosition(int &x, int &y, Janela j) {
    x = getMouseX(j);
    y = getMouseY(j);
}

int Janela::getMouseX() {
    return Mouse::getPosition().x;
}

int Janela::getMouseY() {
    return Mouse::getPosition().y;
}

int Janela::getMouseX(Janela) {
    return Mouse::getPosition(janela).x;
}

int Janela::getMouseY(Janela) {
    return Mouse::getPosition(janela).y;
}

void Janela::setMousePosition(int x, int y) {
    Mouse::setPosition(Vector2i(x, y));
}

void Janela::setMousePosition(int x, int y, Janela) {
    Mouse::setPosition(Vector2i(x, y), janela);
}

void Janela::setMouseX(int x) {
    Mouse::setPosition(Vector2i(x, getMouseY()));
}

void Janela::setMouseY(int y) {
    Mouse::setPosition(Vector2i(getMouseX(), y));
}

void Janela::setMouseX(int x, Janela j) {
    Mouse::setPosition(Vector2i(x, getMouseY(j)));
}

void Janela::setMouseY(int y, Janela j) {
    Mouse::setPosition(Vector2i(getMouseX(j), y));
}

bool Janela::mousePressed(Mouse::Button b) {
    return Mouse::isButtonPressed(b);
}

bool Janela::mouseWeelMovedUp() {
    Event event;
    if(janela.pollEvent(event))
        if (event.type == sf::Event::MouseWheelMoved)
            return event.mouseWheel.delta > 0;
    return false;
}

bool Janela::mouseWeelMovedDown() {
    Event event;
    if(janela.pollEvent(event))
        if (event.type == sf::Event::MouseWheelMoved)
            return event.mouseWheel.delta < 0;
    return false;
}

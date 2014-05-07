#include "Imagem.h"

Imagem::Imagem()
{
}

Imagem::Imagem(string path, int largura, int altura)
{
    load(path, largura, altura);
}

void Imagem::load(string path, int largura, int altura)
{
    if(!imagem.loadFromFile(path)) {
        cout << "Imagem " << path << " mão encontrada!" << endl;
    }

    float width = imagem.getSize().x;
    float height = imagem.getSize().y;

    textura.loadFromImage(imagem);
    textura.setSmooth(true);
    sprite.setTexture(textura);

    if(largura == 0) largura = width;
    if(altura == 0)  altura = height;

    sprite.setTextureRect(IntRect(0, 0, width, height));
    sprite.setScale(largura/width, altura/height);

}

void Imagem::draw(int x, int y) {
    float l = imagem.getSize().x/2;
    float h = imagem.getSize().y/2;
    sprite.setOrigin(l, h);

    l *= sprite.getScale().x;
    h *= sprite.getScale().y;

    sprite.setPosition(Vector2f(x+l, y+h));
    Janela::janela.draw(sprite);
}

void Imagem::rotate(int angulo) {
    sprite.rotate(angulo);
}

void Imagem::setSize(int largura, int altura) {
    float width = imagem.getSize().x;
    float height = imagem.getSize().y;
    sprite.setScale((float)largura/width, (float)altura/height);
}

void Imagem::zoom(float h, float v) {
    int width = sprite.getTextureRect().width;
    int height = sprite.getTextureRect().height;

    sprite.setTextureRect(IntRect(0, 0, h*width, v*height));
    sprite.scale(h, v);
}

int Imagem::getWidth() {
    return sprite.getTextureRect().width;
}

int Imagem::getHeight() {
    return sprite.getTextureRect().height;
}

bool Imagem::intersects(Imagem im) {
    return sprite.getGlobalBounds().intersects(im.getRect());
}
FloatRect Imagem::getRect() {
    return sprite.getGlobalBounds();
}

Image Imagem::getImage() {
    return imagem;
}

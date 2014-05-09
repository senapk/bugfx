#include <BuggFX.h>
#include <string>
#include <cmath>

using namespace std;

struct Game{
    int largura;
    int altura;
};

struct Nave{
    float x, y, vx, vy, direcao, maxAcceleration, initHeading;

    Desenhavel *d;
    Nave(Desenhavel *d, float initHeading) {
		this->d = d;
        x = y = 100;
        vx = vy;
        direcao = initHeading;
        this->initHeading = initHeading;
        maxAcceleration = 1.0;
        d->setSize(100, 100);
    }

    void update(){
        x += vx;
        y += vy;
    }
    void show(){
        d->draw(x, y);
    }


    void input(Janela &janela){
        if(janela.keyDown(Keyboard::Left)){
            direcao -= 10;
            d->rotate(-10);
        }
        if(janela.keyDown(Keyboard::Right)){
            direcao += 10;
            d->rotate(10);
        }
        if(janela.keyDown(Keyboard::Up)){
            vx += maxAcceleration * Math::dcos(Math::sf2cart(direcao));
            vy -= maxAcceleration * Math::dsin(Math::sf2cart(direcao));
        }
    }
};

int main(){
    Game game;
    game.largura = 1000;
    game.altura = 700;
    Janela janela(game.largura, game.altura,"Voa Passarinho, Voa!!!!");
    Escritor e;
    Animacao anime(100);
    anime.addMany("imagens/bird-", ".png", 24);
    Nave nave(&anime, 100);
    char c;

    while(janela.isOpen() && c != 'q'){
        janela.clear();

        nave.input(janela);
        nave.update();
        nave.show();
        
        e.write(0, 0, "Digite q para sair");

        c = janela.getKeyChar();
        janela.update();
    }
    return 0;
}


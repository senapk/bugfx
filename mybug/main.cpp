#include "BuggFX.h"

struct Game{
    int largura;
    int altura;
};

struct Heroi{
    Imagem imagem;
    Imagem inverted;
    int flipped;
    void loadImagem(string path){
        imagem.load(path);
    }
    void loadInverted(string path){
        inverted.load(path);
    }
    Imagem getImage(){
        if (flipped)
            return inverted;
        return imagem;
    }
    void flipX(){
        flipped = ~flipped;
    }
};

int main(){
    Game game;
    game.largura = 1000;
    game.altura = 700;
    Janela janela(game.largura, game.altura,"Digite ou morra!");
    char c;
    Escritor e;
    Animacao david(7, "../mybug/imagens/dir", ".png");
    Imagem davi("../mybug/imagens/dir0.png");


    Timer t;
    int posx = 0;
    while(janela.isOpen() && c != 'q'){
        posx += 10;
        janela.clear();


        if(t.hasPassed(100)){
            t.update();
            david.setRotate(posx/10);
        }

        david.getImage().draw(posx,30);
        david.update(300);

        e.write(0, 0, "Digite q para sair");

        c = janela.getKeyChar();
        Util::sleep(50);
        janela.update();
    }
    return 0;
}

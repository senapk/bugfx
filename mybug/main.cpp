#include "BuggFX.h"

struct Game{
    int largura;
    int altura;
};

int main(int argc, char ** argv){
    Game game;
    game.largura = 1000;
    game.altura = 700;
    Janela janela(game.largura, game.altura,"Digite ou morra!");
    char c;
    Escritor e;
    cout << argv[0] << endl;
    Animacao dav(200);
    dav.addImage("../mybug/imagens/dir0.png");
    dav.addImage("../mybug/imagens/dir1.png");
    dav.addImage("../mybug/imagens/dir2.png");
    dav.addImage("../mybug/imagens/dir3.png");
    dav.addImage("../mybug/imagens/dir4.png");
    dav.setTimer(300);
    //Imagem dav("../mybug/imagens/dir0.png");


    Timer t;
    int posx = 0;
    while(janela.isOpen() && c != 'q'){
        posx += 10;
        janela.clear();

        dav.draw(posx,30);

        e.write(0, 0, "Digite q para sair");

        c = janela.getKeyChar();
        Util::sleep(50);
        janela.update();
    }
    return 0;
}

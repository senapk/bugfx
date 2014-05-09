#ifndef ANIMACAO_H
#define ANIMACAO_H

#include <vector>
#include "Imagem.h"
#include "Util.h"

class Animacao : public Desenhavel{

    public:
    vector<Imagem> imagens;
    //Imagem imagens[10];
    int imagemAtual;
    int numImagens;
    Timer timer;
    int updateTime;

    Animacao(int tempo){
        timer.update();
        imagemAtual = 0;
        updateTime = tempo;
    }

    Animacao(const Animacao &anim):imagens(anim.imagens){
        this->imagemAtual = anim.imagemAtual;
        this->numImagens = anim.numImagens;
        timer.update();
        updateTime = anim.updateTime;
    }

    void addImage(string path, int altura = 0, int largura = 0){
        imagens.push_back(Imagem(path, altura, largura));
    }

    void addMany(string path, string ext, int qtd){
        for(int i = 0; i < qtd; i++)
            addImage(path + Util::str("%d",i) + ext);
    }

    void next(){
        imagemAtual = (imagemAtual + 1) % imagens.size();
    }

    void update(){
        if(updateTime != 0){
            if(timer.hasPassed(updateTime)){
                timer.update();
                this->next();
            }
        }
    }

    void setTimer(int updateTimer){
        this->updateTime = updateTimer;
    }

    void draw(int x, int y){
        update();
        imagens[imagemAtual].draw(x, y);
    }

    void rotate(int angulo){
        for(Imagem &im : imagens)
            im.rotate(angulo);
    }

    void setSize(int x, int y){
        for(Imagem &im : imagens)
            im.setSize(x, y);
    }
};

#endif // ANIMACAO_H

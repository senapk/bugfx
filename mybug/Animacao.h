#ifndef ANIMACAO_H
#define ANIMACAO_H

#include <vector>
#include "Imagem.h"
#include "Util.h"

struct Animacao{
    vector<Imagem> imagens;
    int numDeImagens;
    int imagemAtual;
    Timer timer;

    Animacao(int qtd, string basePath, string extension)
             :imagens(qtd){
        imagemAtual = 0;
        numDeImagens = qtd;
        for(int i = 0; i < qtd; i++){
            imagens[i].load(basePath + Util::str("%d",i) + extension);
        }
    }

    void next(){
        imagemAtual = (imagemAtual + 1)%numDeImagens;
    }

    void update(int minTime){
        if(timer.hasPassed(minTime)){
            timer.update();
            this->next();
        }
    }

    Imagem & getImage(){
        return (imagens[imagemAtual]);
    }

    void setRotate(int angulo){
        for(Imagem &im : imagens)
            im.rotate(angulo);
    }
};

#endif // ANIMACAO_H

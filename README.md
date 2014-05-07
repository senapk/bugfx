bugfx
=====

bugfx

Para instalar as dependencias no ubuntu 14.04::

    sudo apt-get install g++ libsfml-dev libsfml-audio2 libsfml-doc libsfml-graphics2 libsfml-network2 libsfml-system2 libsfml-window2

Para instalar e testar (OBS: ele vai recriar a pasta bugfx no diretorio atual) ::
    
    rm -rf bugfx
    git clone https://github.com/senapk/bugfx
    cd bugfx/mybug
    make compile
    make install
    cd ../example
    gpp nave.cpp -o nave
    ./nave

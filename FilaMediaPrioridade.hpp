#ifndef FILA_MEDIA_PRIORIDADE_HPP
#define FILA_MEDIA_PRIORIDADE_HPP

#include <iostream>
#include "Processo.hpp"
#include "NoProcessos.hpp"  

using namespace std;

class FilaMediaPrioridade {
private:
    FilaMediaDupla fila;

public:
    FilaMediaPrioridade();

    void enfileirar(Processo processo);
    bool estaVazia();
    void exibir();
    Processo desenfileirar(); 
};

#endif

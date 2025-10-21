#ifndef PROCESSOS_HPP
#define PROCESSOS_HPP

#include <iostream>
#include <stdexcept>
#include "Processo.hpp"
using namespace std;

/*
* **  struct para criar a pilha de processos
*/
struct NoPilha {
    Processo processo;
    NoPilha* prox;
};

/*
* **  Criando o nó da fila de prioridade
*/
struct NoFilaAltaSimples {
    Processo processo;
    NoFilaAltaSimples* prox;
};

/*
* **  Nó da fila de media prioridade
*/
struct NoFilaDuplaMedia {
    Processo processo;
    NoFilaDuplaMedia* ant;
    NoFilaDuplaMedia* prox;
};

/*
* **  fila de media prioridade
*/
struct FilaMediaDupla {
    NoFilaDuplaMedia* head  = nullptr;
    NoFilaDuplaMedia* tail = nullptr;
};

/*
* **  No da fila de baixa prioridade
*/
struct NoFilaDuplaBaixa {
    Processo processo;
    NoFilaDuplaBaixa* ant;
    NoFilaDuplaBaixa* prox;
};

/*
* **  fila de baixa prioridade
*/
struct FilaDuplaBaixa {
    NoFilaDuplaBaixa* head  = nullptr;
    NoFilaDuplaBaixa* tail = nullptr;
};

#endif 
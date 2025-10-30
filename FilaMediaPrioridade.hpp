#ifndef FILA_MEDIA_PRIORIDADE_HPP
#define FILA_MEDIA_PRIORIDADE_HPP

#include <iostream>
#include <stdexcept>
#include "Processo.hpp"

using namespace std;

class FilaMediaPrioridade {
private:
    struct Node {
        Processo processo;
        Node* ant;
        Node* prox;
    };

    Node* head;
    Node* tail;
    int quantidade;

public:
    FilaMediaPrioridade();
    ~FilaMediaPrioridade();

    bool vazia() const;
    void enfileirar(const Processo& processo);
    Processo desenfileirar();
    void exibirProcessos() const;
    int getQuantidade() const;
};

#endif

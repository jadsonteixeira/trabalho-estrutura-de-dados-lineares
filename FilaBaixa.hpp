#ifndef _FILA_MEDIA_
#define _FILA_MEDIA_

#include "Processo.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

class FilaBaixa {
    private:
        struct Node {
            Processo processo;
            Node * ant;
            Node * prox;
        };
        
        Node * head;
        Node * tail;
        int quantidade_processos;

    public:
        FilaBaixa();
        ~FilaBaixa();

        bool vazia() const;
        void enfileirar(const Processo & processo);
        Processo desenfileirar();
        void exibirProcessos() const;
        int getQuantidadeProcessos() const;
};

#endif
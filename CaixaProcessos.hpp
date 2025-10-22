#ifndef _CAIXA_PROCESSO_
#define _CAIXA_PROCESSO_

#include "Processo.hpp"

#include <iostream>

using namespace std;

struct Node {
    Processo processo;
    Node * prox;
};

class CaixaProcessos {
    private:
        Node * topo;
        int quantidade_processos;

    public:
        CaixaProcessos();
        ~CaixaProcessos();

        bool vazia() const;
        void empilhar(const Processo & processo);
        Processo desempilhar();
        void exibirProcessos() const;
        
        int getQuantidade() const;

        void separarPorPrioridade(CaixaProcessos & caixa, CaixaProcessos & caixa_baixa, CaixaProcessos & caixa_media, CaixaProcessos & caixa_alta) const;

};

#endif
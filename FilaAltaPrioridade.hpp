#ifndef FILAALTA_PRIORIDADE_HPP
#define FILAALTA_PRIORIDADE_HPP

#include "Processo.hpp"
#include <iostream>

struct NoFilaSimplesAlta {
    Processo processo;
    NoFilaSimplesAlta* prox;
};

class FilaAltaPrioridade {
private:
    NoFilaSimplesAlta* head;
    NoFilaSimplesAlta* tail;
    int quantidade;

public:
    FilaAltaPrioridade();
    ~FilaAltaPrioridade();
    void enfileirar(const Processo &processo);
    Processo desenfileirar();
    bool estaVazia() const;
    void exibir() const;
    int getQuantidade() const;
};

#endif
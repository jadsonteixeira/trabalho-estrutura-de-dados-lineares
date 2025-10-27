#include "FilaMediaPrioridade.hpp"

FilaMediaPrioridade::FilaMediaPrioridade() {
    fila.head = nullptr;
    fila.tail = nullptr;
}

void FilaMediaPrioridade::enfileirar(Processo processo) {
    NoFilaDuplaMedia* novo = new NoFilaDuplaMedia{processo, nullptr, nullptr};
    if (!fila.head) {
        fila.head = fila.tail = novo;
    } else {
        novo->ant = fila.tail;
        fila.tail->prox = novo;
        fila.tail = novo;
    }
}

bool FilaMediaPrioridade::estaVazia() {
    return fila.head == nullptr;
}

void FilaMediaPrioridade::exibir() {
    NoFilaDuplaMedia* atual = fila.head;
    while (atual) {
        cout << "ID: " << atual->processo.getId() 
             << " - Assunto: " << atual->processo.getAssunto() << endl;
        atual = atual->prox;
    }
}

Processo FilaMediaPrioridade::desenfileirar() {
    if (estaVazia()) {
        throw runtime_error("Fila vazia!");
    }

    NoFilaDuplaMedia* temp = fila.head;
    Processo p = temp->processo;

    fila.head = fila.head->prox;
    if (fila.head) {
        fila.head->ant = nullptr;
    } else {
        fila.tail = nullptr; 
    }

    delete temp;
    return p;
}

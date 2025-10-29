#include "FilaAltaPrioridade.hpp"
#include <stdexcept>

FilaAltaPrioridade::FilaAltaPrioridade() {
    head = nullptr;
    tail = nullptr;
    quantidade = 0;
}

FilaAltaPrioridade::~FilaAltaPrioridade() {
    while (!estaVazia()) {
        desenfileirar();
    }
}

void FilaAltaPrioridade::enfileirar(const Processo &processo) {
    NoFilaSimplesAlta* novo = new NoFilaSimplesAlta{processo, nullptr};
    if (estaVazia()) {
        head = tail = novo;
    } else {
        tail->prox = novo;
        tail = novo;
    }
    quantidade++;
}

Processo FilaAltaPrioridade::desenfileirar() {
    if (estaVazia()) {
        throw std::runtime_error("Fila vazia!");
    }
    NoFilaSimplesAlta* temp = head;
    Processo p = temp->processo;
    head = head->prox;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    quantidade--;
    return p;
}

bool FilaAltaPrioridade::estaVazia()const {
    return head == nullptr;
}

void FilaAltaPrioridade::exibir() const {
    NoFilaSimplesAlta* atual = head;
    while (atual) {
        std::cout << "ID: " << atual->processo.getId()
                  << " - Assunto: " << atual->processo.getAssunto() << std::endl;
        atual = atual->prox;
    }
}

int FilaAltaPrioridade::getQuantidade() const {
    return quantidade;
}
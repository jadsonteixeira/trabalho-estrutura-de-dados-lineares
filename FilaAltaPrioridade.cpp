#include "FilaAltaPrioridade.hpp"
#include <stdexcept>

FilaAltaPrioridade::FilaAltaPrioridade() {
    head = nullptr;
    tail = nullptr;
    quantidade = 0;
}


FilaAltaPrioridade::~FilaAltaPrioridade() {
    while (head) {
        NoFilaSimplesAlta* temp = head;
        head = head->prox;
        delete temp;
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
    if (estaVazia()) {
        std::cout << "Fila vazia" << std::endl;
        return;
    }

    std::cout << "PROCESSOS ALTA PRIORIDADE" << std::endl;
    NoFilaSimplesAlta* atual = head;
    while (atual != nullptr) {
        atual->processo.exibirDados();
        std::cout << "\n------------------------------\n";
        atual = atual->prox;
    }
}

int FilaAltaPrioridade::getQuantidade() const {
    return quantidade;
}
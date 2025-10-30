#include "FilaMediaPrioridade.hpp"

FilaMediaPrioridade::FilaMediaPrioridade() {
    head = nullptr;
    tail = nullptr;
    quantidade = 0;
}

FilaMediaPrioridade::~FilaMediaPrioridade() {
    while (!vazia()) {
        desenfileirar();
    }
}

bool FilaMediaPrioridade::vazia() const {
    return head == nullptr;
}

void FilaMediaPrioridade::enfileirar(const Processo& processo) {
    Node* no = new Node;
    no->processo = processo;
    no->prox = nullptr;
    no->ant = tail;

    if (vazia()) {
        head = no;
    } else {
        tail->prox = no;
    }

    tail = no;
    quantidade++;

    cout << "Processo ID: " << processo.getId() 
         << " enfileirado na FILA MEDIA com sucesso" << endl;
}

Processo FilaMediaPrioridade::desenfileirar() {
    if (vazia()) {
        throw out_of_range("Fila vazia");
    }

    Node* temp = head;
    Processo processo = temp->processo;

    head = head->prox;

    if (head != nullptr) {
        head->ant = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
    quantidade--;

    cout << "Processo ID: " << processo.getId() 
         << " removido da FILA MEDIA com sucesso" << endl;

    return processo;
}

void FilaMediaPrioridade::exibirProcessos() const {
    if (vazia()) {
        cout << "Fila de MEDIA prioridade vazia" << endl;
        return;
    }

    cout << "=== PROCESSOS DE MEDIA PRIORIDADE ===" << endl;
    Node* atual = head;
    while (atual != nullptr) {
        atual->processo.exibirDados(); 
        cout << "\n------------------------------\n";
        atual = atual->prox;
    }
}

int FilaMediaPrioridade::getQuantidade() const {
    return quantidade;
}

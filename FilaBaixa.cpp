#include "FilaBaixa.hpp"

FilaBaixa::FilaBaixa() {
    head = nullptr;
    tail = nullptr;
    quantidade_processos = 0;
}

FilaBaixa::~FilaBaixa() {
    
}

bool FilaBaixa::vazia() const {
    return head == nullptr;
}

void FilaBaixa::enfileirar(const Processo & processo) {
    Node * no = new Node;
    no->processo = processo;
    no->prox = nullptr;
    no->ant = tail;

    if (vazia()) {
        head = no;
    } else {
        tail->prox = no;
    }

    tail = no;
    quantidade_processos++;

    cout << "Processo ID: " << processo.getId() << " enfileirado com sucesso" << endl;
}

Processo FilaBaixa::desenfileirar() {
    if (vazia()) {
        throw out_of_range("Fila vazia");
    }

    Node * temp = head;
    Processo processo = temp->processo;

    head = head->prox;

    if (head != nullptr) {
        head->ant = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
    quantidade_processos--;

    cout << "Processo ID: " << processo.getId() << " removido com sucesso" << endl;

    return processo;
}

void FilaBaixa::exibirProcessos() const {
    if (vazia()) {
        cout << "Fila vazia" << endl;
        return;
    }

    cout << "PROCESSOS MEDIA PRIORIDADE" << endl;
    Node * atual = head;
    while (atual != nullptr) {
        atual->processo.exibirDados();
        cout << "\n------------------------------\n";
        atual = atual->prox;
    }
}

int FilaBaixa::getQuantidadeProcessos() const {
    return quantidade_processos;
}
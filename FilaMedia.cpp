#include "FilaMedia.hpp"

FilaMedia::FilaMedia() {
    head = nullptr;
    tail = nullptr;
    quantidade_processos = 0;
}

FilaMedia::~FilaMedia() {

}

bool FilaMedia::vazia() const {
    return head == nullptr;
}

void FilaMedia::enfileirar(const Processo & processo) {
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

Processo FilaMedia::desenfileirar() {
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

void FilaMedia::exibirProcessos() const {
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

int FilaMedia::getQuantidadeProcessos() const {
    return quantidade_processos;
}
#include "CaixaProcessos.hpp"

CaixaProcessos::CaixaProcessos() {
    topo = nullptr;
    quantidade_processos = 0;
}

CaixaProcessos::~CaixaProcessos() {

}

bool CaixaProcessos::vazia() const {
    return topo == nullptr;
}

void CaixaProcessos::empilhar(const Processo & processo) {
    Node * novo = new Node; // cria um novo no
    novo->processo = processo; // copia o processo
    novo->prox = topo; // aponta para o antigo topo
    topo = novo; // atualiza o topo
    quantidade_processos++; 

    cout << "Processo ID: " << processo.getId() << " empilhado com sucesso" << endl;
}

Processo CaixaProcessos::desempilhar() {
    if (vazia()) {
        throw out_of_range("Nao tem nenhum processo aberto");
    }

    Node * temp = topo; // guarda a referência ao topo atual
    Processo processo = temp->processo; // copia o processo
    topo = topo->prox; // move o topo para o proximo
    
    delete temp;

    quantidade_processos--;

    cout << "Processo ID: " << processo.getId() << " removido" << endl;

    return processo;
}

void CaixaProcessos::exibirProcessos() const {
    if (vazia()) {
        cout << "Nao tem nenhum processo aberto" << endl;
        return;
    }

    Node * atual = topo;
    cout << "PROCESSOS ABERTOS\n" << endl;
    while (atual != nullptr) {
        atual->processo.exibirDados();
        cout << "\n------------------------------" << endl;
        atual = atual->prox;
    }
}

int CaixaProcessos::getQuantidade() const {
    return quantidade_processos;
}

void CaixaProcessos::separarPorPrioridade(CaixaProcessos & caixa, CaixaProcessos & caixa_baixa, CaixaProcessos & caixa_media, CaixaProcessos & caixa_alta) const {
    while (!caixa.vazia()) {
        Processo p = caixa.desempilhar();

        switch (p.getNivelPrioridade()) {
            case ALTA:
                caixa_alta.empilhar(p);
                break;
            case MEDIA:
                caixa_media.empilhar(p);
                break;
            case BAIXA:
                caixa_baixa.empilhar(p);
                break;
        }
    }
}
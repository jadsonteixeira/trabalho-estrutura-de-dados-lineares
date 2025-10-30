#include <iostream>
#include <cstdlib>

#include "Pessoa.hpp"
#include "Processo.hpp"
#include "CaixaProcessos.hpp"
#include "Estudante.hpp"
#include "Professor.hpp"
#include "FilaBaixa.hpp"

using namespace std;

int main() {
    system("cls");

    Pessoa p1("Leandro", 1001, "111-222-333-44");
    Estudante e1("Leandro", 20001, "999-999-999-00", "TADS");
    Processo pro1(1, e1, "Teste");
    Processo pro2(2, e1, "Teste");
    Processo pro3(3, e1, "Teste");
    Processo pro4(4, e1, "Teste");
    Processo pro5(5, e1, "Teste");

    CaixaProcessos caixa;
    caixa.empilhar(pro1);
    caixa.empilhar(pro2);
    caixa.empilhar(pro3);
    caixa.empilhar(pro4);
    caixa.empilhar(pro5);

    cout << "Processos abertos: " << caixa.getQuantidade() << endl;

    caixa.exibirProcessos();

    CaixaProcessos caixa_alta_prioridade;
    CaixaProcessos caixa_media_prioridade;
    CaixaProcessos caixa_baixa_prioridade;

    caixa.separarPorPrioridade(caixa, caixa_baixa_prioridade, caixa_media_prioridade, caixa_alta_prioridade);

    cout << "\nProcessos BAIXA prioridade: " << caixa_baixa_prioridade.getQuantidade();
    cout << "\nProcessos MEDIA prioridade: " << caixa_media_prioridade.getQuantidade();
    cout << "\nProcessos ALTA prioridade: " << caixa_alta_prioridade.getQuantidade();

    cout << "\n\nMEDIA PRIORIDADE\n\n";
    caixa_media_prioridade.exibirProcessos();

    FilaBaixa fila_baixa;

    while (!caixa_media_prioridade.vazia()) {
        Processo p = caixa_media_prioridade.desempilhar();
        fila_baixa.enfileirar(p);
    }

    cout << "Processos media prioridade: " << fila_baixa.getQuantidadeProcessos() << endl;

    return 0;
}
#include <iostream>
#include <cstdlib>

#include "Pessoa.hpp"
#include "Processo.hpp"
#include "CaixaProcessos.hpp"
#include "Estudante.hpp"
#include "Professor.hpp"
#include "FilaBaixa.hpp"
#include "FilaMediaPrioridade.hpp"
#include "FilaAltaPrioridade.hpp"

using namespace std;

int main() {
    system("cls");

    Estudante e1("Jadson", 10001, "111-111-111-11", "TADS");
    Estudante e2("Joelson", 10002, "222-222-222-22", "TADS");
    Estudante e3("Luana", 10003, "333-333-333-33", "TADS");
    Professor prof1("Leandro", "000-000-000-00", 20001);

    Processo pro1(1, e1, "Assunto");
    Processo pro2(2, e2, "Assunto");
    Processo pro3(3, e3, "Assunto");
    Processo pro4(4, prof1, "Assunto");
    Processo pro5(5, e1, "Assunto");
    Processo pro6(6, e2, "Assunto");
    Processo pro7(7, e3, "Assunto");
    Processo pro8(8, prof1, "Assunto");
    Processo pro9(9, prof1, "Assunto");
    Processo pro10(10, prof1, "Assunto");

    CaixaProcessos caixa;
    caixa.empilhar(pro1);
    caixa.empilhar(pro2);
    caixa.empilhar(pro3);
    caixa.empilhar(pro4);
    caixa.empilhar(pro5);
    caixa.empilhar(pro6);
    caixa.empilhar(pro7);
    caixa.empilhar(pro8);
    caixa.empilhar(pro9);
    caixa.empilhar(pro10);

    cout << "Processos Abertos: " << caixa.getQuantidade() << "\n\n";

    caixa.exibirProcessos();

    CaixaProcessos caixa_alta_prioridade;
    CaixaProcessos caixa_media_prioridade;
    CaixaProcessos caixa_baixa_prioridade;

    caixa.separarPorPrioridade(caixa, caixa_baixa_prioridade, caixa_media_prioridade, caixa_alta_prioridade);

    cout << "\nProcessos BAIXA prioridade: " << caixa_baixa_prioridade.getQuantidade();
    cout << "\nProcessos MEDIA prioridade: " << caixa_media_prioridade.getQuantidade();
    cout << "\nProcessos ALTA prioridade: " << caixa_alta_prioridade.getQuantidade();
    cout << "\n";

    FilaBaixa fila_baixa;
    FilaMediaPrioridade fila_media;
    FilaAltaPrioridade fila_alta;

    while (!caixa_baixa_prioridade.vazia()) {
        Processo p = caixa_baixa_prioridade.desempilhar();
        fila_baixa.enfileirar(p);
    }

    while (!caixa_media_prioridade.vazia()) {
        Processo p = caixa_media_prioridade.desempilhar();
        fila_media.enfileirar(p);
    }

    while (!caixa_alta_prioridade.vazia()) {
        Processo p = caixa_alta_prioridade.desempilhar();
        fila_alta.enfileirar(p);
    }

    cout << "\n";
    cout << "Fila de Processos Baixa Prioridade: " << fila_baixa.getQuantidadeProcessos() << endl;
    cout << "Fila de Processos Media Prioridade: " << endl;
    cout << "Fila de Processos Alta Prioridade: " << fila_alta.getQuantidade() << endl;

    cout << "\n";

    fila_baixa.desenfileirar();

    return 0;
}
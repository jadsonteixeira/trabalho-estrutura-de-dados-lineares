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

    Pessoa p1("Leandro", 1001, "111-222-333-44");
    Estudante e1("Matheus", 10001, "111-111-111-11", "TADS");
    Professor prof1("Leandro", "000-000-000-00", 20001);
    Processo pro1(1, prof1, "Teste");
    Processo pro2(2, e1, "Teste");
    Processo pro3(3, prof1, "Teste");
    Processo pro4(4, e1, "Teste");
    Processo pro5(5, prof1, "Teste");

    CaixaProcessos caixa;
    caixa.empilhar(pro1);
    caixa.empilhar(pro2);
    caixa.empilhar(pro3);
    caixa.empilhar(pro4);
    caixa.empilhar(pro5);

    cout << "Processos abertos: " << caixa.getQuantidade() << endl;

    CaixaProcessos caixa_alta_prioridade;
    CaixaProcessos caixa_media_prioridade;
    CaixaProcessos caixa_baixa_prioridade;

    caixa.separarPorPrioridade(caixa, caixa_baixa_prioridade, caixa_media_prioridade, caixa_alta_prioridade);

    cout << "\nProcessos BAIXA prioridade: " << caixa_baixa_prioridade.getQuantidade();
    cout << "\nProcessos MEDIA prioridade: " << caixa_media_prioridade.getQuantidade();
    cout << "\nProcessos ALTA prioridade: " << caixa_alta_prioridade.getQuantidade();
    cout << "\n\n";

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
    cout << "Fila Baixa: " << fila_baixa.getQuantidadeProcessos() << endl;
    cout << "Fila Media: " << endl;
    cout << "Fila Alta: " << fila_alta.getQuantidade() << endl;

    cout << "\nTESTE PARA EXIBIR AS FILAS SEPARADAS POR PRIORIDADE\n";
    cout << "\nFILA ALTA PRIORIDADE\n";
    fila_alta.exibir();

    cout << "\nFILA MEDIA PRIORIDADE\n";
    fila_media.exibir();

    cout << "\nFILA BAIXA PRIORIDADE\n";
    fila_baixa.exibirProcessos();

    return 0;
}
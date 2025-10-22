#include <iostream>
#include <cstdlib>

#include "Pessoa.hpp"
#include "Processo.hpp"
#include "CaixaProcessos.hpp"
#include "Estudante.hpp"
#include "Professor.hpp"

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
    Processo pro6(6, e1, "Teste");
    Processo pro7(7, e1, "Teste");
    Processo pro8(8, e1, "Teste");
    Processo pro9(9, e1, "Teste");
    Processo pro10(10, e1, "Teste");

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

    cout << "Processos abertos: " << caixa.getQuantidade() << endl;

    caixa.exibirProcessos();

    cout << "\nTeste desempilhando e organizando" << endl;

    CaixaProcessos caixa_alta_prioridade;
    CaixaProcessos caixa_media_prioridade;
    CaixaProcessos caixa_baixa_prioridade;

    caixa.separarPorPrioridade(caixa, caixa_baixa_prioridade, caixa_media_prioridade, caixa_alta_prioridade);

    cout << "\nProcessos BAIXA prioridade: " << caixa_baixa_prioridade.getQuantidade();
    cout << "\nProcessos MEDIA prioridade: " << caixa_media_prioridade.getQuantidade();
    cout << "\nProcessos ALTA prioridade: " << caixa_alta_prioridade.getQuantidade();

    cout << "\n\nALTA PRIORIDADE\n\n";
    caixa_alta_prioridade.exibirProcessos();
    cout << "\n\nMEDIA PRIORIDADE\n\n";
    caixa_media_prioridade.exibirProcessos();
    cout << "\n\nBAIXA PRIORIDADE\n\n";
    caixa_baixa_prioridade.exibirProcessos();

    return 0;
}
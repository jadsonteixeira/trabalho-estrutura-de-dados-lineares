#include <iostream>
#include <cstdlib>

#include "Processo.hpp"
#include "Pessoa.hpp"
#include "CaixaProcessos.hpp"

using namespace std;

int main() {
    system("cls");
    srand(time(0));

    Pessoa p1 = Pessoa("Jadson", 10001, "999-999-999-99");
    Processo pro1 = Processo(1, p1, "Teste");
    Processo pro2 = Processo(2, p1, "Teste");
    Processo pro3 = Processo(3, p1, "Teste");

    CaixaProcessos caixa;
    caixa.empilhar(pro1);
    caixa.empilhar(pro2);
    caixa.empilhar(pro3);

    cout << "\nQuantidade de processos: " << caixa.getQuantidade() << endl;

    cout << "\n";

    caixa.exibirProcessos();

    cout << "\nDesempilhando..." << endl;
    caixa.desempilhar();
    
    cout << "\nQuantidade de processos: " << caixa.getQuantidade() << endl;

    return 0;
}
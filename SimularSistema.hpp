#ifndef SIMULAR_SISTEMA_HPP
#define SIMULAR_SISTEMA_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CaixaProcessos.hpp"
#include "FilaAltaPrioridade.hpp"
#include "FilaMediaPrioridade.hpp"
#include "FilaBaixa.hpp"
#include "Processo.hpp"
#include "TramitarProcessos.hpp"

using namespace std;

class SimularSistema {
private:
    double pA, pM, pB;
    int namin, namax, ntmin, ntmax;
    int proximoId;

    CaixaProcessos caixaEntrada;
    FilaAltaPrioridade filaAlta;
    FilaMediaPrioridade filaMedia;
    FilaBaixa filaBaixa;

    void abrirProcessos(int dia);
    void organizarProcessos();
    void exibirPendentes(int dia);

public:
    SimularSistema(double pA, double pM, double pB, int namin, int namax, int ntmin, int ntmax);
    void simular(int dias);
};

#endif

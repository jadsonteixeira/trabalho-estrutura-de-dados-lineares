#ifndef TRAMITAR_PROCESSOS_HPP
#define TRAMITAR_PROCESSOS_HPP

#include "FilaAltaPrioridade.hpp"
#include "FilaMediaPrioridade.hpp"
#include "FilaBaixa.hpp"
#include <iostream>
using namespace std;

class TramitarProcessos {
private:
    FilaAltaPrioridade* filaAlta;
    FilaMediaPrioridade* filaMedia;
    FilaBaixa* filaBaixa;

public:
    TramitarProcessos(FilaAltaPrioridade* fAlta, FilaMediaPrioridade* fMedia, FilaBaixa* fBaixa);
    void tramitarProcessos(int npt);
};

#endif

#ifndef _PROCESSO_HPP_
#define _PROCESSO_HPP_

#include <iostream>
#include <string>

using namespace std;

enum class NivelPrioridade{
    BAIXA,
    MEDIA,
    ALTA
};

struct Processo{
    long numIdentificacao;
};

class Processo
{
    int numIdentificacao;
    NivelPrioridade NivelPrioridade;
    int matriculaSolicitante;
};


#endif
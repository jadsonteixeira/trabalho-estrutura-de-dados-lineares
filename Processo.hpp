#ifndef _PROCESSO_HPP_
#define _PROCESSO_HPP_

#include <iostream>
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;
using DataHora = std::chrono::system_clock::time_point;

enum class NivelPrioridade{
    BAIXA,
    MEDIA,
    ALTA
};

class Processo
{
    private:
        int id;
        string assunto;
        DataHora data_hora;
        NivelPrioridade NivelPrioridade;
        int matriculaSolicitante;
    public: 

};
#endif
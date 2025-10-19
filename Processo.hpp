#ifndef _PROCESSO_HPP_
#define _PROCESSO_HPP_

#include "NivelPrioridade.hpp"

#include <iostream>
#include <string>
#include <chrono>       // pegar data e hora
#include <iomanip>      // para formatar
#include <sstream>      // converter data e hora para string
#include <ctime>        // conversão de Localtime

using namespace std;

class Processo {
    private:
        int id_processo;
        NivelPrioridade nivel_prioridade;
        string assunto;
        string data_hora;

        string gerarDataHora() const; 

    public: 
        Processo();
        Processo(int id, string assunto);

        string getDataHora() const;
        int getId() const;
        NivelPrioridade getNivelPrioridade() const;
        string getAssunto() const;

        void exibirDados() const;

        int gerarNumPrioridade() const;
        NivelPrioridade gerarPrioridade();
};

#endif
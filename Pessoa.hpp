#ifndef _PESSOA_HPP_
#define _PESSOA_HPP_

//#include "Processo.hpp"

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    protected:
        string nome;
        int matricula;
        string cpf;

    public:
        Pessoa();
        Pessoa(string nome, int matricula, string cpf);
        ~Pessoa();

        string getNome() const;
        int getMatricula() const;
        string getCpf() const;

        void dadosPessoa() const;

        //Processo abrirProcesso();

};

#endif
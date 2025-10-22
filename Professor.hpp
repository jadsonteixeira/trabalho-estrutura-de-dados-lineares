#ifndef _PROFESSOR_HPP_
#define _PROFESSOR_HPP_
#include <iostream>
#include "Pessoa.hpp"
#include "AreaAtuacao.hpp"
#include <string>

using namespace std;

class Professor : public Pessoa{
    private:
        AreaAtuacao areaAtuacao;
    public:
        Professor(string nome, string cpf,int matricula);
        ~Professor();
        void dadosProfessor() const;
        int gerarNumPrioridade() const;
        AreaAtuacao gerarPrioridade();
        AreaAtuacao getAreaAtuacao() const;
        string areaToString() const;
};
#endif
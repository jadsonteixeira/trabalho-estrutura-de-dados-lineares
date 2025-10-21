#ifndef _PROFESSOR_HPP_
#define _PROFESSOR_HPP_
#include <iostream>
#include "Pessoa.hpp"


using namespace std;

enum class AreaAtuacao{
    INFORMATICA,
    ADMINISTRACAO,
    PROPEDEUTICA,
    QUIMICA
};

class Professor : public Pessoa{
    private:
        AreaAtuacao areaAtuacao;

        string areaToString() const; // Função para converter enum em string
    public:
        Professor(string nome, string cpf, AreaAtuacao areaAtuacao, int matricula);
        ~Professor();
        void dadosProfessor() const;
};
#endif
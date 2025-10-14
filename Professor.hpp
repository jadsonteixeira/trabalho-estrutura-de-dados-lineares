#ifndef _PROFESSOR_HPP_
#define _PROFESSOR_HPP_
#include <iostream>
#include <string>

using namespace std;

enum class AreaAtuacao{
    INFORMATICA,
    ADMINISTRACAO,
    QUIMICA
};

class Professor{
private:
    string nome;
    string matricula;
    string cpf;
    AreaAtuacao AreaAtuacao;
public:
    Professor();
    ~Professor();
};
#endif
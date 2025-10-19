#ifndef _ESTUDANTE_HPP_
#define _ESTUDANTE_HPP_

#include "processo.hpp"
#include "Pessoa.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Estudante : public Pessoa{
    private: 
        string curso;
    public:
        Estudante();
        Estudante(string nome, int matricula,  string cpf, string curso);
        ~Estudante();

        string getCurso() const;
};
#endif
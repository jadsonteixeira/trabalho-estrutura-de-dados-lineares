#include "Estudante.hpp"
#include <iostream>

Estudante::Estudante(){

}

Estudante::~Estudante(){

}

Estudante::Estudante(string nome, int matricula, string cpf, string curso) : Pessoa(nome, matricula, cpf), curso(curso) {}

string Estudante::getCurso() const{
    return this->curso;
}
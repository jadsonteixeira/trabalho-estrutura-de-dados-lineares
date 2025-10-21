#include "Professor.hpp"

Professor::Professor(string nome, string cpf, AreaAtuacao areaAtuacao, int matricula){
    this->nome = nome;
    this->cpf = cpf;
    this->areaAtuacao = areaAtuacao;
    this->matricula = matricula;
}

Professor::~Professor(){
    cout << "Destrutor";
}

string Professor::areaToString() const {
    switch(areaAtuacao) {
        case AreaAtuacao::INFORMATICA: return "Informatica";
        case AreaAtuacao::ADMINISTRACAO: return "Administracao";
        case AreaAtuacao::PROPEDEUTICA: return "Propedeutica";
        case AreaAtuacao::QUIMICA: return "Quimica";
    }
    return "Desconhecida";
}

// Exibe dados do professor
void Professor::dadosProfessor() const {
    cout << "Dados do Professor:\n";
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Area de atuacao: " << areaToString() << endl;
}
#include "Professor.hpp"
#include "AreaAtuacao.hpp"

Professor::Professor(string nome, string cpf, int matricula) : Pessoa( nome, matricula, cpf){
    this->areaAtuacao = gerarPrioridade();
}

Professor::~Professor(){

}

AreaAtuacao Professor::getAreaAtuacao() const{
    return this->areaAtuacao;
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
    cout << "Area Atuacao: " << areaToString() <<endl;
}

int Professor::gerarNumPrioridade() const {
    int num_prioridade = rand() % 100 + 1;
    return num_prioridade;
}

AreaAtuacao Professor::gerarPrioridade() {
    int num = gerarNumPrioridade();

    if (num <= 25) {
        return AreaAtuacao::INFORMATICA;
    } else if (num <= 50) {
        return AreaAtuacao::ADMINISTRACAO;
    } else if(num <= 75){
        return AreaAtuacao::PROPEDEUTICA;
    }else{
        return AreaAtuacao::QUIMICA;
    }
}
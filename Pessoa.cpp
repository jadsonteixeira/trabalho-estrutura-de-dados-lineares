#include "Pessoa.hpp"

Pessoa::Pessoa() {

}

Pessoa::Pessoa(string nome, int matricula, string cpf) {
    this->nome = nome;
    this->matricula = matricula;
    this->cpf = cpf;
}

Pessoa::~Pessoa() {
    
}

string Pessoa::getNome() const {
    return this->nome;
}

int Pessoa::getMatricula() const {
    return this->matricula;
}

string Pessoa::getCpf() const {
    return this->cpf;
}

void Pessoa::dadosPessoa() const {
    cout << "Dados da Pessoa" << endl;
    cout << "Nome: " << this->getNome() << endl;
    cout << "Matricula: " << this->getMatricula() << endl;
    cout << "CPF: " << this->getCpf() << endl;
}

// Processo Pessoa::abrirProcesso() {
    
// }
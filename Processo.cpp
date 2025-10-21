#include "Processo.hpp"
#include "NivelPrioridade.hpp"

Processo::Processo(int id_processo, const Pessoa &solicitante, string assunto) {
    this->id_processo = id_processo;
    this->nivel_prioridade = gerarPrioridade();
    this->assunto = assunto;
    this->data_hora = gerarDataHora();
    this->matricula_solictante = solicitante.getMatricula();
}

Processo::Processo() {
    id_processo = 0;
    assunto = "";
    data_hora = "";
    matricula_solictante = 0;
}

string Processo::getDataHora() const {
    return data_hora;
}

int Processo::getId() const {
    return this->id_processo;
}

NivelPrioridade Processo::getNivelPrioridade() const {
    return this->nivel_prioridade;
}

string Processo::getAssunto() const {
    return this->assunto;
}

int Processo::getMatriculaSolicitante() const {
    return this->matricula_solictante;
}

void Processo::exibirDados() const {
    cout << "ID: " << this->getId() << endl;
    cout << "Matricula Solicitante: " << this->getMatriculaSolicitante() << endl;
    cout << "Data e Hora: " << this->getDataHora() << endl;
    cout << "Assunto: " << this->getAssunto() << endl;
    cout << "Nivel de Prioridade: ";

    switch (nivel_prioridade) {
        case BAIXA:
            cout << "BAIXA";
            break;
        case MEDIA:
            cout << "MEDIA";
            break;
        case ALTA:
            cout << "ALTA";
            break;
    }
}

string Processo::gerarDataHora() const {
    auto agora = chrono::system_clock::now();

    time_t tempo = chrono::system_clock::to_time_t(agora);
    tm* tempoLocal = localtime(&tempo);

    ostringstream oss;
    oss << put_time(tempoLocal, "%d/%m/%Y %H:%M:%S");

    return oss.str();
}

int Processo::gerarNumPrioridade() const {
    int num_prioridade = rand() % 10 + 1;
    return num_prioridade;
}

NivelPrioridade Processo::gerarPrioridade() {
    int num = gerarNumPrioridade();

    if (num >= 5) {
        return BAIXA;
    } else if (num >= 2) {
        return MEDIA;
    } else {
        return ALTA;
    }
}
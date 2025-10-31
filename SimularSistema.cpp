#include "SimularSistema.hpp"

SimularSistema::SimularSistema(double pA, double pM, double pB, int namin, int namax, int ntmin, int ntmax)
    : pA(pA), pM(pM), pB(pB), namin(namin), namax(namax), ntmin(ntmin), ntmax(ntmax), proximoId(1) {
    srand(static_cast<unsigned>(time(nullptr)));
}

void SimularSistema::simular(int dias) {
    TramitarProcessos tramiter(&filaAlta, &filaMedia, &filaBaixa);

    for (int dia = 1; dia <= dias; dia++) {
        cout << "\n=========================================\n";
        cout << " INICIO DO DIA " << dia << endl;
        cout << "=========================================\n";

        abrirProcessos(dia);
        organizarProcessos();

        int npt = ntmin + rand() % (ntmax - ntmin + 1);
        tramiter.tramitarProcessos(npt);

        exibirPendentes(dia);
    }
}

void SimularSistema::abrirProcessos(int dia) {
    int npa = namin + rand() % (namax - namin + 1);
    cout << "\n  ABERTURA DE " << npa << " PROCESSOS\n";

    for (int i = 0; i < npa; i++) {
        double prob = static_cast<double>(rand()) / RAND_MAX;
        NivelPrioridade nivel;

        if (prob < pA) nivel = NivelPrioridade::ALTA;
        else if (prob < pA + pM) nivel = NivelPrioridade::MEDIA;
        else nivel = NivelPrioridade::BAIXA;

        Pessoa solicitante("Pessoa " + to_string(proximoId), 1000 + proximoId, "CPF-" + to_string(proximoId));
        string assunto = "Assunto do processo " + to_string(proximoId);

        Processo processo(proximoId++, solicitante, assunto);
        processo.setNivelPrioridade(nivel);

        cout << " Processo criado: ID " << processo.getId()
             << " | Prioridade: " << (nivel == NivelPrioridade::ALTA ? "Alta" : nivel == NivelPrioridade::MEDIA ? "Media" : "Baixa")
             << " | " << processo.getAssunto() << endl;

        caixaEntrada.empilhar(processo);
    }
}

void SimularSistema::organizarProcessos() {
    cout << "\n  Organizando processos por prioridade...\n";

    while (!caixaEntrada.vazia()) {
        Processo p = caixaEntrada.desempilhar();

        switch (p.getNivelPrioridade()) {
            case NivelPrioridade::ALTA:
                filaAlta.enfileirar(p);
                cout << "  Processo " << p.getId() << " enviado para fila ALTA.\n";
                break;
            case NivelPrioridade::MEDIA:
                filaMedia.enfileirar(p);
                cout << "  Processo " << p.getId() << " enviado para fila MEDIA.\n";
                break;
            case NivelPrioridade::BAIXA:
                filaBaixa.enfileirar(p);
                cout << "  Processo " << p.getId() << " enviado para fila BAIXA.\n";
                break;
        }
    }
    cout << " Todos os processos foram organizados.\n";
}

void SimularSistema::exibirPendentes(int dia) {
    cout << "\n PROCESSOS PENDENTES AO FINAL DO DIA " << dia << "\n";
    cout << "-----------------------------------------\n";

    cout << "Alta Prioridade:\n"; filaAlta.exibir();
    cout << "\nMedia Prioridade:\n"; filaMedia.exibirProcessos();
    cout << "\nBaixa Prioridade:\n"; filaBaixa.exibirProcessos();

    cout << "-----------------------------------------\n";
}

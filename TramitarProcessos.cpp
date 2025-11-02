#include "TramitarProcessos.hpp"

TramitarProcessos::TramitarProcessos(FilaAltaPrioridade* fAlta, FilaMediaPrioridade* fMedia, FilaBaixa* fBaixa)
    : filaAlta(fAlta), filaMedia(fMedia), filaBaixa(fBaixa) {}

void TramitarProcessos::tramitarProcessos(int npt) {
    cout << "\n=== INICIO DA TRAMITACAO (NPT = " << npt << ") ===\n";
    int tramitados = 0;

    for (int i = 0; i < 3 && tramitados < npt && !filaAlta->estaVazia(); i++) {
        Processo p = filaAlta->desenfileirar();
        cout << "Tramitado (Alta) -> ID: " << p.getId() << endl;
        tramitados++;
    }

    for (int i = 0; i < 2 && tramitados < npt && !filaMedia->vazia(); i++) {
        Processo p = filaMedia->desenfileirar();
        cout << "Tramitado (Media) -> ID: " << p.getId() << endl;
        tramitados++;
    }

    if (tramitados < npt && !filaBaixa->vazia()) {
        Processo p = filaBaixa->desenfileirar();
        cout << "Tramitado (Baixa) -> ID: " << p.getId() << endl;
        tramitados++;
    }

    cout << " Total de processos tramitados hoje: " << tramitados << endl;
}

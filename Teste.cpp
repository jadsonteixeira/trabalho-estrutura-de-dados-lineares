#include <iostream>
#include <cstdlib>
#include "SimularSistema.hpp"

using namespace std;

int main() {
    system("cls");
 
    double pA = 0.10; 
    double pM = 0.30; 
    double pB = 0.60; 

    int namin = 3;  
    int namax = 6; 
    int ntmin = 2;  
    int ntmax = 5;  

    
    SimularSistema sistema(pA, pM, pB, namin, namax, ntmin, ntmax);

    sistema.simular(3);

    cout << "\n=== SIMULACAO FINALIZADA ===\n";

    return 0;
}

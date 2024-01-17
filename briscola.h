#ifndef CARTE_BRISCOLA_H
#define CARTE_BRISCOLA_H
#include "carta.h"
#include <vector>
#include <iostream>

using namespace std;

class briscola {
private:
    //vector per il mazzo
    vector<carta> mazzo;

    //vector per le mani dei due giocatori
    vector<carta> mano_p1;
    vector<carta> mano_p2;

    //nomi dei due giocatori
    string nome_p1, nome_p2;

    //variabili per tenere traccia del punteggio dei due giocatori
    int punti_p1, punti_p2;

    //briscola della partita
    int seme_briscola;
    
    //variabile per i turni
    bool turno;

public:
    //costruttore
    briscola(string, string);
    //dichiarazione delle funzioni
    void crea_mazzo();
    void mischia();
    void estrai_briscola();
    string dimmi_briscola();
    void gioca(int, int);
    bool fine_mazzo();
    int test();
    bool get_turno();
};
#endif

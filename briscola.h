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
    bool turno = false;

    //
    int cards_left = 39;

public:
    //costruttore
    briscola(string, string);
    
    //costruttore per riprendere la partita salvata aka "carica_partita"--> prima fare funzione per mostrare partite salvate
    /*come parametro non gli do niente voglio fa i salvataggi con tanto di slots*/
    //void salva_partita("string nome salvataggio")
    //void mostra_salvataggi
    //void carica("string nome salvataggio"); NB: riguarda come si mettono a confronto due stringhe
    //dichiarazione delle funzioni
    void crea_mazzo();
    void mischia();
    void estrai_briscola();
    string dimmi_briscola();
    void gioca(int, int);
    bool fine_mazzo();
    bool fine_mano();
    void carta_giocata(int);
    int test();
    bool get_turno();
    void stampa_mano_g1();
    void stampa_mano_g2();
    int punteggio(int);
    string stampa_nome(int);
};
#endif

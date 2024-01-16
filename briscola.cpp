#include "briscola.h"
#include "carta.h"
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
using namespace std;

//costruttore per iniziare una partita, crea il mazzo, mischia il mazzo e estrae la briscola
briscola::briscola(string player1, string player2) {
    //assegno i nomi dei giocatori passati per parametro
    nome_p1 = player1;
    nome_p2 = player2;
    //creo il mazzo
    crea_mazzo();
    //lo mischio
    mischia();
    //estreggo la briscola e la rimetto in fondo al mazzo
    estrai_briscola();
    //do le carte al giocatore 1
    for (int i = 0; i < 2; ++i) {
        p1[i] = mazzo[mazzo.max_size()-i];
        mazzo.pop_back();
    }
    //do le carte al giocatore 2
    for (int i = 0; i < 2; ++i) {
        p2[i] = mazzo[mazzo.max_size()-i];
        mazzo.pop_back();
    }
    //azzerro i punteggi
    punti_p1 = 0;
    punti_p2 = 0;
}

//creo il mazzo
void briscola::crea_mazzo(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j <= 10; ++j) {
            auto p = new carta(j, i);
            mazzo.push_back(*p);
        }
    }
}

//funzione per mischiare il mazzo
void briscola::mischia() {
    random_device seme;
    default_random_engine rnd(seme());
    shuffle(mazzo.begin(), mazzo.end(), rnd);
}

// funzione per estrarre la briscola e metterla in fondo al mazzo
void briscola::estrai_briscola(){
    seme_briscola = mazzo[39].get_seme_reale();
    swap(mazzo[39], mazzo[0]);
}

//funzione test
int briscola::test() {
    //cout << mazzo.size() << endl;
    cout << mazzo[0].get_numero() << " " << mazzo[0].get_seme() << " " << mazzo[0].get_valore() << endl;
    cout << mazzo[39].get_numero() << " " << mazzo[39].get_seme() << " " << mazzo[39].get_valore() << endl;
    return 0;
}
//funzione che restituisce il nome della briscola attuale
string briscola::dimmi_briscola(){
    switch (seme_briscola) {
        case 0:
            return "Denari";
        case 1:
            return "Bastoni";
        case 2:
            return "Coppe";
        case 3:
            return "Spade";
    }
}
//funzione principale del gioco
void briscola::gioca(){}



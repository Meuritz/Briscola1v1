#ifndef BRISCOLA_BRISCOLA_H
#define BRISCOLA_BRISCOLA_H
#include "carta.h"
#include <vector>
#include <iostream>

using namespace std;

class briscola {
private:
    static vector<carta> mazzo;
    vector<carta> p1;
    vector<carta> p2;
public:
    briscola();
    static void crea_mazzo();
    void mischia();
    static void test();
};


#endif
//40 carte
//creare un mezzo
//funzione per mischiare
//3 carte a giocatore
//la carta in cima al mazzo viene girata e diventa la briscola
//il seme della carta che è stata girata è la briscola
//il seme della carta che viene giocata per prima comanda, salvo la briscola
//se entrambi hanno giocato un liscio(2, 4 ,5 ,6 ,7 ) prende il giocatore di "mano"
//chi tira una briscola prende, se vengono tirate due briscole vince quella più alta
//il gioco finisce quando termina il mazzo
//NB: il turno sta a chi prende
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
    //estreggo la briscola e la metto in fondo al mazzo
    estrai_briscola();
    //do le carte al giocatore 1
    for (int i = 0; i < 2; ++i) {
        mano_p1.push_back(mazzo[mazzo.size()]);
        mazzo.pop_back();
    }
    //do le carte al giocatore 2
    for (int i = 0; i < 2; ++i) {
        mano_p2.push_back(mazzo[mazzo.size()]);
        mazzo.pop_back();
    }
    //azzerro i punteggi
    punti_p1 = 0;
    punti_p2 = 0;
}

//creo il mazzo
void briscola::crea_mazzo(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j <= 10; ++j) {
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

void briscola::gioca(int carta_g1, int carta_g2){

//determino chi gioca per primo(più o meno in realta) questo pezzo è utile per i controlli
carta g1 = mano_p1[carta_g1]; //giocatore di mano 
carta g2 = mano_p2[carta_g2]; //giocatore non di mano

//variabile di appoggio per i punti (leggibilità del codice, per quanto possa essere leggibile)
int punti_turno = g1.get_valore() + g2.get_valore();

//se le carte hanno lo stesso seme
if (g1.get_seme_reale() == g2.get_seme_reale())
    {
        if (g1.get_valore() > g2.get_valore())
        {
            //assgno i punti a chi vince la mano, e cambio turno in modo da capire chi sara il prossimo di mano
            punti_p1 = punti_p1 + punti_turno;
            turno = 0;  
        }else{
            punti_p2 = punti_p2 + punti_turno;
            turno = 1;
        }  
    }

//se le carte hanno seme diverso
if (g1.get_seme_reale() != g2.get_seme_reale())
    {
        //se g1 gioca briscola
        if (g1.get_seme_reale() == seme_briscola)
        {
            punti_p1 = punti_p1 + punti_turno;
            turno = 0;
        }
        //se g2 gioca briscola
        else if (g2.get_seme_reale() == seme_briscola)
        {
            punti_p2 = punti_p2 + punti_turno;
            turno = 1;
        }
        else //se nessuno gioca briscola
        {
            if (turno == 0)
            {
                punti_p1 = punti_p1 + punti_turno;
            }
            else
            {
                punti_p2 = punti_p2 + punti_turno;
            }
        }
    }
    //rimuovo le carte usate dai due giocatori
        mano_p1.erase(mano_p1.begin() + carta_g1); //come parametro gli passo la posizione della carta usata
        mano_p2.erase(mano_p1.begin() + carta_g1);
    //ripesco la carta , chi ha vinto la mano pesca per primo
    if (turno = 0) //aka se il giocatore 1 ha vinto la mano(turno)
    {
        mano_p1.insert(mano_p1.begin() + carta_g1, mazzo[mazzo.size()]);
        mazzo.pop_back();

        mano_p2.insert(mano_p2.begin() + carta_g2, mazzo[mazzo.size()]);
        mazzo.pop_back();
    }
    else//aka se la vinta il giocatore 2
    {
        mano_p2.insert(mano_p2.begin() + carta_g2, mazzo[mazzo.size()]);
        mazzo.pop_back();

        mano_p2.insert(mano_p2.begin() + carta_g2, mazzo[mazzo.size()]);
        mazzo.pop_back();
    }
    
}
//funzione per controllare se il mazzo è finito
bool briscola::fine_mazzo(){
    bool stato = mazzo.empty();
    return stato;
}
//metodo get per il turno (0 = Giocatore 1 e 1 = Giocatore 2) 
bool briscola::get_turno(){
    return turno;
}

//funzione per stampare la mano dei giocatori
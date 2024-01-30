#include "carta.h"
#include <iostream>
using namespace std;

//costruttore
carta::carta(int Num, int Sem) {
    numero = Num;
    seme = Sem;
    //chiamo la funzione per assegnare il valore alla carta
    valore = Valore_Carta(Num);
}
//funzione per impostare il valore della carta
int carta::Valore_Carta(int numero_carta) {
    switch (numero_carta) {
        case 1:
            return 11;
        case 3:
            return 10;
        case 10:
            return 4;
        case 9:
            return 3;
        case 8:
            return 2;
        default:
            return 0;
    }
}
//metodi get per i campi privati
int carta::get_numero() const{
    return numero;
}
//restituisce il seme della carta sotto forma di string
string carta::get_seme() const{
    string seme;
    switch (this->seme) {
        case 0:
            seme = "Denari";
            break;
        case 1:
            seme = "Bastoni";
            break;
        case 2:
            seme = "Coppe";
            break;
        case 3:
            seme = "Spade";
            break;
    }
    return seme;
}
//restituisce il seme della carta sotto forma di int
int carta::get_seme_reale() const {
    return seme;
}
int carta::get_valore() const{
    return valore;
}
//distruttore per carta
carta::~carta() {

}

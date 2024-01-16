#include "carta.h"
#include <iostream>
using namespace std;

carta::carta(int Num, int Sem) {
    numero = Num;
    seme = Sem;
    valore = carta::Valore_Carta(Num);
}
//metodo per impostare il valore della carta
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
int carta::get_seme() const{
    return seme;
}
int carta::get_valore() const{
    return valore;
}




//valori carte
//2, 4 ,5 ,6 ,7 sono 0 punti
//1 = 11 punti
//3 = 10 punti
//10 = 4 punti
//9 = 3 punti
//8 = 2 punti
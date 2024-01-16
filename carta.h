#ifndef CARTA_H
#define CARTA_H

class carta {
private:
    //numero da 1 a 10
    //Bastoni Denari Coppe Spade
    int numero, seme, valore;
public:
    //custruttore carta
    carta(int, int);

    //funzione per impostare il valore della carta
    int Valore_Carta(int);

    //funzioni get per tutti le variabili private
    int get_numero() const;
    int get_seme() const;
    int get_valore() const;

};
#endif
//valori carte
//2, 4 ,5 ,6 ,7 sono 0 punti
//1 = 11 punti
//3 = 10 punti
//10 = 4 punti
//9 = 3 punti
//8 = 2 punti
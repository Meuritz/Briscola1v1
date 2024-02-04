#ifndef CARTE_CARTA_H
#define CARTE_CARTA_H
#include <string>
using namespace std;
class carta {
private:
    int numero, seme, valore;
public:
    //custruttore carta
    carta(int, int);
    //distruttore
    ~carta();
    //funzione per impostare il valore della carta
    int Valore_Carta(int);

    //funzioni get per le variabili private
    int get_numero() const;
    int get_seme_reale() const;
    string get_seme() const;
    int get_valore() const;
};
#endif

#include <iostream>
#include "briscola.h"
#include <windows.h>
using namespace std;

void screen_clear();
void menu();
void gioca();

int main() {

    briscola sds("dmsmsd", "hsdhsuhd");
    menu();
    return 0;
}

//per pulire lo schermo
void screen_clear(){
    for (int i = 0; i < 30; ++i) {
        cout << endl;
    }
}
//menu di gioco
void menu(){
    screen_clear();
    int scelta;
    do{
        cout << "Benvenuto alla Briscola...";
        Sleep(1000);
        cout << "Fatta MALE!!!" << endl;
        cout << "1)Gioca" << endl << "0)esci dal gioco" << endl;
        cout << "-->";
        cin >> scelta;
        switch (scelta) {
            case 1: gioca();
            case 2: exit(0);
            case 0: cout << "Uscita in corso..."; exit(0);
            default: Sleep(1000); cout << scelta << "Non 'e un opzione valida!!!" ;
        }
    }while(scelta !=1 || scelta !=2);
}

//funzione per giocare una partita
void gioca(){
string Giocatore_1, Giocatore_2;

cout << "Inserisci il nome del giocatore 1 -->";
cin >> Giocatore_1;

cout << "Inserisci il nome del giocatore 2 -->";
cin >> Giocatore_2;
//avvio la partita
briscola Partita(Giocatore_1, Giocatore_2);
    do {
        //
        int carta_g1, carta_g2;

        //SE IL TURNO 'E DEL GIOCATORE 1 (all'inizio è sempre il suo turno)
        if (Partita.get_turno() == 0){

            //stampo la mano del giocatore 1 e gli faccio scegliere la carta da giocare
            do {
                screen_clear();
                cout << "Briscola: " << Partita.dimmi_briscola() << endl;
                cout << Partita.stampa_nome(1) << " 'e il tuo turno!" << endl;
                cout << "Punteggio: " << Partita.punteggio(1) << endl;
                cout << "Scegli una carta: " << endl;
                Partita.stampa_mano_g1();
                cout << "-->";
                cin >> carta_g1;
            }while(carta_g1 > 3);

            //stampo la mano del giocatore 2 e gli faccio scegliere la carta da giocare
            do {
                screen_clear();
                cout << "Briscola: " << Partita.dimmi_briscola() << endl;
                cout << Partita.stampa_nome(2) << " 'e il tuo turno!" << endl;
                cout << "Punteggio: " << Partita.punteggio(2) << endl;
                cout << "Scegli una carta: " << endl;
                Partita.stampa_mano_g2();
                cout << "Carta giocata dall'avversario: "; 
                Partita.carta_giocata(carta_g1);
                cout << "-->";
                cin >> carta_g2;
            }while(carta_g2 > 3);
        }else{
        //se il turno è del giocatore 2
            //stampo la mano del giocatore 2 e gli faccio scegliere la carta da giocare
            do {
                screen_clear();
                cout << "Briscola: " << Partita.dimmi_briscola() << endl;
                cout << Partita.stampa_nome(2) << " 'e il tuo turno!" << endl;
                cout << "Punteggio: " << Partita.punteggio(2) << endl;
                cout << "Scegli una carta: " << endl;
                Partita.stampa_mano_g2();
                cout << "-->";
                cin >> carta_g2;
            }while(carta_g2 > 3);
            //stampo la mano del giocatore 1 e gli faccio scegliere la carta da giocare
            do {
                screen_clear();
                cout << "Briscola: " << Partita.dimmi_briscola() << endl;
                cout << Partita.stampa_nome(1) << " 'e il tuo turno!" << endl;
                cout << "Punteggio: " << Partita.punteggio(1) << endl;
                cout << "Scegli una carta: " << endl;
                Partita.stampa_mano_g1();
                cout << "Carta giocata dall'avversario: ";
                Partita.carta_giocata(carta_g2);
                cout << "-->";
                cin >> carta_g1;
            }while(carta_g1 > 3);
        }
        //gioco le carte
        Partita.gioca(carta_g1, carta_g2);
        //dico chi ha vinto la mano e stampo tutti i punteggi
        if (Partita.get_turno() == 0){
            cout << "Mano vinta da " << Partita.stampa_nome(1)<<endl;
        }else{
            cout << "Mano vinta da " << Partita.stampa_nome(2) <<endl;
        }

    } while (Partita.fine_mano() == 0); //fino a che ci sono carte nella mano(basta che ne controllo una)
    //Fine partita
    cout << "FINE PARTITA" << endl;
    if (Partita.punteggio(1) > Partita.punteggio(2)) {
        cout << "Vince " << Partita.stampa_nome(1) << " con " << Partita.punteggio(1);
    }else if(Partita.punteggio(1) < Partita.punteggio(2)){
        cout << "Vince " << Partita.stampa_nome(2) << " con " << Partita.punteggio(2);
    }else{
        cout << "partita finita in PAREGGIO...HOW?";
    }
}


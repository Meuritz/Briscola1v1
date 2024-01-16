#include "briscola.h"
#include "carta.h"
#include <vector>
#include <iostream>
using namespace std;

//creo il mazzo
briscola::briscola(){}

void briscola::crea_mazzo(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 10; ++j) {
            auto p = new carta(i, j);
            mazzo.push_back(*p);
        }
    }
}

void briscola::test() {
    cout << mazzo.size() << endl;
}
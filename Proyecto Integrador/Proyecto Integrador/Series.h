#include <iostream>
#include <string>

using namespace std;

#ifndef Series_h
#define Series_h

#include "Video.h"

class Series : public Video {
protected:
    int numDeTemporadas;
public:
    Series();
    Series(int ID, string nombre, string genero, int numDeTemporadas);
    //void setTemporadas(int temporadas);

    int getNumDeTemporadas();

    virtual void show();
};

Series::Series():Video() {
    numDeTemporadas = 0;
}

Series::Series(int ID, string nombre, string genero, int numDeTemporadas):Video(ID, nombre, genero) {
    this -> numDeTemporadas = numDeTemporadas;
}

/*void Series::setTemporadas(int temporadas) {
    this -> temporadas = temporadas;
}*/

int Series::getNumDeTemporadas() {
    return numDeTemporadas;
}

void Series::show() {
    Video::show();
    cout << "Numero de temporadas: " << numDeTemporadas << "." << endl;
}

#endif
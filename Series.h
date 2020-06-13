#include <iostream>
#include <string>
#include <vector>

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
    Series(int ID, string nombre);

    int getNumDeTemporadas();
    int getID();

    virtual void show();
    void showNombre();

};

Series::Series():Video() {
    numDeTemporadas = 0;
}

Series::Series(int ID, string nombre, string genero, int numDeTemporadas):Video(ID, nombre, genero) {
    this -> numDeTemporadas = numDeTemporadas;

}

Series::Series(int ID, string nombre):Video(ID, nombre, "") {
    numDeTemporadas = 1;
}

int Series::getNumDeTemporadas() {
    return numDeTemporadas;
}

int Series::getID() {
    return ID;
}

void Series::show() {
    Video::show();
    
    cout << "Numero de temporadas: " << numDeTemporadas << "." << endl;
}

void Series::showNombre() {
    cout << "Nombre: " << nombre << endl;
}

#endif
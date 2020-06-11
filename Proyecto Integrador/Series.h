#include <iostream>
#include <string>

using namespace std;

#ifndef Series_h
#define Series_h

#include "Video.h"

class Series : public Video {
protected:
    int temporadas;
public:
    Series();
    Series(int ID, string nombre, string genero, int temporadas);
    //void setTemporadas(int temporadas);

    int getTemporadas();
};

Series::Series():Video() {
    temporadas = 0;
}

Series::Series(int ID, string nombre, string genero, int temporadas):Video(ID, nombre, genero) {
    this -> temporadas = temporadas;
}

/*void Series::setTemporadas(int temporadas) {
    this -> temporadas = temporadas;
}*/

int Series::getTemporadas() {
    return temporadas;
}

#endif
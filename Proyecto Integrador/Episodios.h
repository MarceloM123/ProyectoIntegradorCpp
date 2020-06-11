#include <iostream>
#include <string>

using namespace std;

#ifndef Episodios_h
#define Episodios_h

#include "Video.h"
#include "Series.h"

class Episodios :  public Series {
private:
    int IDEpisodio;
    string duracion;
    double calificacion;
public:
    Episodios();
    Episodios(int ID, string nombre, string genero, int temporadas, int IDEpisodio, string duracion, double calificacion);
    //void setIDEpisodios(int IDEpisodio);
    //void setDuracion(string duracion);
    //void setCalificacion(double calificacion);

    int getIDEpisodios();
    string getDuracion();
    double getCalificacion();
};

Episodios::Episodios():Series() {
    IDEpisodio = 0;
    duracion = "";
    calificacion = 0.0;
}

Episodios::Episodios(int ID, string nombre, string genero, int temporadas, int IDEpisodio, string duracion, 
double calificacion):Series(ID, nombre, genero, temporadas) {
    this -> IDEpisodio = IDEpisodio;
    this -> duracion = duracion;
    this -> calificacion = calificacion;
}

int Episodios::getIDEpisodios() {
    return IDEpisodio;
}

string Episodios::getDuracion() {
    return duracion;
}

double Episodios::getCalificacion() {
    return calificacion;
}





#endif
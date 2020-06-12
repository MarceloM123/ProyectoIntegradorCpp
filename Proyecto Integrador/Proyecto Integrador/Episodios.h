#include <iostream>
#include <string>

using namespace std;

#ifndef Episodios_h
#define Episodios_h

//#include "Video.h"
#include "Series.h"

class Episodios :  public Series {
private:
    string IDEpisodio;
    string duracion;
    double calificacion;
    int temporada;
public:
    Episodios();
    Episodios(int ID, string IDEpisodio, string nombre, string duracion, double calificacion, int temporada, int numDeTemporadas, string genero);
    //void setIDEpisodios(int IDEpisodio);
    //void setDuracion(string duracion);
    //void setCalificacion(double calificacion);

    string getIDEpisodios();
    string getDuracion();
    double getCalificacion();
    int getTemporada();

    void show();
};

Episodios::Episodios():Series() {
    IDEpisodio = "";
    duracion = "";
    calificacion = 0.0;
    temporada = 0;
}

Episodios::Episodios(int ID, string IDEpisodio, string nombre, string duracion, double calificacion, int temporada, int numDeTemporadas, string genero):Series(ID, nombre, genero, numDeTemporadas) {
    this -> IDEpisodio = IDEpisodio;
    this -> duracion = duracion;
    this -> calificacion = calificacion;
    this -> temporada = temporada;
}

string Episodios::getIDEpisodios() {
    return IDEpisodio;
}

string Episodios::getDuracion() {
    return duracion;
}

double Episodios::getCalificacion() {
    return calificacion;
}

int Episodios::getTemporada() {
    return temporada;
}

void Episodios::show() {
    Series::show();
    cout << "Duración: " << duracion << ". Calificación: " << calificacion << "." << endl;
}

#endif
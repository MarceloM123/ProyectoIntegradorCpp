#include <iostream>
#include <string>
#include <vector>

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
    Episodios(int ID, string IDEpisodio, string nombre, string duracion, 
    double calificacion, int temporada);

    void setCalificacion(double calificacion);

    string getIDEpisodios();
    string getDuracion();
    double getCalificacion();
    int getTemporada();

    void show();
    void caliShow();
};

Episodios::Episodios():Series() {
    IDEpisodio = "";
    duracion = "00:00";
    calificacion = 0.0;
    temporada = 0;
}

Episodios::Episodios(int ID, string IDEpisodio, string nombre, string duracion, 
double calificacion, int temporada):Series(ID, nombre) {
    this -> IDEpisodio = IDEpisodio;
    this -> duracion = duracion;
    this -> calificacion = calificacion;
    this -> temporada = temporada;
}

void Episodios::setCalificacion(double calificacion) {
    this -> calificacion = calificacion;
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
    Video::epiShow();
    
    cout << ". Duración: " << duracion << ". Calificación: " << calificacion << "." << endl;
    cout << "Temporada: " << temporada << endl;
}

void Episodios::caliShow() {
    cout << calificacion << endl; 
}

#endif
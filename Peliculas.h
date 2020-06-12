#include <iostream>
#include <string>

using namespace std;

#ifndef Peliculas_h
#define Peliculas_h

#include "Video.h"

class Peliculas : public Video {
private:
    string duracion;
    double calificacion;
public:
    Peliculas();
    Peliculas(int ID, string nombre, string duracion, string genero, double calificacion);

    void setCalificacion(double calificacion);

    string getDuracion();
    double getCalificacion();

    void show();
};

Peliculas::Peliculas():Video() {
    duracion = "00:00";
    calificacion = 0.0;
}

Peliculas::Peliculas(int ID, string nombre, string duracion, string genero, double calificacion):Video(ID, nombre, genero) {
    this -> duracion = duracion;
    this -> calificacion = calificacion;
}


void Peliculas::setCalificacion(double calificacion) {
    this -> calificacion = calificacion;
}

string Peliculas::getDuracion() {
    return duracion;
}

double Peliculas::getCalificacion() {
    return calificacion;
}

void Peliculas::show() {
    Video::show();
    cout << "Duración: " << duracion << ". Calificación: " << calificacion << "." << endl;
}

#endif
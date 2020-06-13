#include <iostream>
#include <string>
#include <vector>

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
    string getGenero();

    void show();
    void caliShow();

    bool operator>=(double min);
    bool operator<=(double max);
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

string Peliculas::getGenero() {
    return genero;
}

bool Peliculas::operator>=(double min) {
    if (this->calificacion >= min) {
        return true;
    } else {
        return false;
    }
}

bool Peliculas::operator<=(double max) {
    if (this->calificacion <= max) {
        return true;
    } else {
        return false;
    }
}


void Peliculas::show() {
    Video::show();
    cout << "Duración: " << duracion << ". Calificación: " << calificacion << "." << endl;
}

void Peliculas::caliShow() {
    cout << calificacion << endl;
}

#endif
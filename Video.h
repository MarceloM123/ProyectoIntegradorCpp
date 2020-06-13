#include <iostream>
#include <string>

using namespace std;

#ifndef Video_h
#define Video_h

class Video {
protected:
    int ID;
    string nombre;
    string genero;
public:
    Video();
    Video(int ID, string nombre, string genero);

    int getID();
    string getNombre();
    string getGenero();

    virtual void show() = 0;
    virtual void epiShow();
};

Video::Video() {
    ID = 0;
    nombre = "";
    genero = "";
}

Video::Video(int ID, string nombre, string genero) {
    this -> ID = ID;
    this -> nombre = nombre;
    this -> genero = genero; 
}


int Video::getID() {
    return ID;
}

string Video::getNombre() {
    return nombre;
}

string Video::getGenero() {
    return genero;
}

void Video::show() {
    cout << "Nombre: " << nombre << ". Genero: " << genero << "." << endl;
}

void Video::epiShow() {
    cout << "Nombre: " << nombre;
}

#endif
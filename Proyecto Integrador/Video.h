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
    //void setID(int ID);
    //void setNombre(string nombre);
    //void setGenero(string genero);

    int getID();
    string getNombre();
    string getGenero();
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

/*void Video::setID(int ID) {
    this -> ID = ID;
}

void Video::setNombre(string nombre) {
    this -> nombre = nombre;
}

void Video::setGenero(string genero) {
    this -> genero = genero;
}*/

int Video::getID() {
    return ID;
}

string Video::getNombre() {
    return nombre;
}

string Video::getGenero() {
    return genero;
}

#endif
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "Video.h"
#include "Peliculas.h"
#include "Series.h"
#include "Episodios.h"

string cargarDatos(vector<Peliculas*> peliculas, vector<Series*> series, vector<Episodios*> episodios) {
    ifstream epi("ProyectoIntegrador-Episodios-1.csv");
    ifstream peli("ProyectoIntegrador-Peliculas-1.csv");
    ifstream seri("ProyectoIntegrador-Series-1.csv");

    string line;
    string valor;
    char delim = ',';

    string nombre, duracion, genero, IDEpisodio;
    int ID, numDeTemporadas, temporada;
    double calificacion;

    int col;

    // Cargar archivo de Peliculas
    if(peli.is_open()) {
        getline(epi, line);
        while(getline(epi, line)) {

            stringstream ss(line);
            col = 0;

            while(getline(ss, valor, delim)) {

                switch(col) {
                case 0:
                    ID = stoi(valor);
                    break;
                case 1:
                    nombre = valor;
                    break;
                case 2:
                    duracion = valor;
                    break;
                case 3:
                    genero = valor;
                    break;
                case 4:
                    calificacion = stod(valor);
                    break;
                }
                col++;
            }
            peliculas.push_back(new Peliculas(ID, nombre, duracion, genero, calificacion));
        }
        peli.close();
    }

    // Cargar archivo de Series
    if(seri.is_open()) {
        getline(epi, line);
        while(getline(epi, line)) {

            stringstream ss(line);
            col = 0;

            while(getline(ss, valor, delim)) {

                switch(col) {
                case 0:
                    ID = stoi(valor);
                    break;
                case 1:
                    nombre = valor;
                    break;
                case 2:
                    genero = valor;
                    break;
                case 3:
                    numDeTemporadas = stoi(valor);
                    break;
                }
                col++;
            }
            series.push_back(new Series(ID, nombre, genero, numDeTemporadas));
        }
        seri.close();
    }

    // Cargar archivos de Episodios
    if(epi.is_open()) {
        getline(epi, line);
        while(getline(epi, line)) {

            stringstream ss(line);
            col = 0;

            while(getline(ss, valor, delim)) {

                switch(col) {
                case 0:
                    ID = stoi(valor);
                    break;
                case 1:
                    IDEpisodio = valor;
                    break;
                case 2:
                    nombre = valor;
                    break;
                case 3:
                    duracion = valor;
                    break;
                case 4:
                    calificacion = stod(valor);
                    break;
                case 5:
                    temporada = stoi(valor);
                    break;
                case 6:
                    break; // nada
                case 7:
                    break; // nada
                }
                col++;
            }
            episodios.push_back(new Episodios());
        }
        epi.close();
    }









}






int main() {
    vector<Peliculas*> peliculas;
    vector<Series*> series;
    vector<Episodios*> episodios; 

    int opc;
    cout << endl << "-------------------------------------------------------------------------------------------" << endl;
    cout << "1) Cargar archivos de datos." << endl;
    cout << "2) Mostrar los videos en general con un cierto rango de calificación de un cierto género." << endl;
    cout << "3) Mostrar los videos en general de un cierto género." << endl;
    cout << "4) Mostrar los episodios de una determinada serie con un rango de calificación determinada." << endl;
    cout << "5) Mostrar las películas con cierto rango de calificación." << endl;
    cout << "6) Calificar un video." << endl;
    cout << "0) Salir." << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "Opcion: ";
    cin >> opc;

    bool sw = true;
    int opcCase1;

    while (sw) {

        switch (opc) {

        case 1:
            // Cargar archivos de datos
            break;

        case 2:
            // Mostrar los videos en general con un cierto rango de calificación de un cierto género
            break;

        case 3:
            // Mostrar los videos en general de un cierto género
            break;

        case 4:
            // Mostrar los episodios de una determinada serie con un rango de calificación determinada
            break;

        case 5:
            // Mostrar las películas con cierto rango de calificación
            break;

        case 6:
            // Calificar un video
            break;

        case 0:
            // Salir
            sw = false;
            break;

        }
    }
    return 0;
}
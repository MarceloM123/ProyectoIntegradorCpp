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

// ##### 1 #####
void cargarDatos(vector<Peliculas*> &peliculas, vector<Series*> &series, vector<Episodios*> &episodios) {
    ifstream peli("ProyectoIntegrador-Peliculas-1.csv");
    ifstream seri("ProyectoIntegrador-Series-1.csv");
    ifstream epi("ProyectoIntegrador-Episodios-1.csv");

    string line;
    string valor;
    char delim = ',';

    string nombre, duracion, genero, IDEpisodio;
    int ID, numDeTemporadas, temporada;
    double calificacion;

    int col;

    // Cargar archivo de Peliculas
    if(peli.is_open()) {
        getline(peli, line);
        while(getline(peli, line)) {

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
        getline(seri, line);
        while(getline(seri, line)) {

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
            episodios.push_back(new Episodios(ID, IDEpisodio, nombre, duracion, calificacion, temporada));
        }
        epi.close();
    }
}

// ##### 2 #####

// ##### 3 #####

// ##### 4 #####

// ##### 5 #####
void rangoPeliculas(vector<Peliculas*> peliculas, int min, int max) {
    int count = 1;

    for(int i = 0; i < peliculas.size(); i++) {

        if(peliculas[i]->getCalificacion() >= min && peliculas[i]->getCalificacion() <= max) {
            cout << endl;
            cout << count << ") ";
            peliculas[i]->show();
            cout << endl;
            count++;

        }
    }
}


// ##### 6 #####





int main() {
    vector<Peliculas*> peliculas;
    vector<Series*> series;
    vector<Episodios*> episodios; 

    bool sw = true;
    int opcCase1;

    while (sw) {
        
        int min, max;
        string genero;

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

        switch (opc) {

        case 1:
            // Cargar archivos de datos
            cargarDatos(peliculas, series, episodios);
            cout << endl << "Archivos han sido cargados" << endl;
            break;

        case 2:
            // Mostrar los videos en general con un cierto rango de calificación de un cierto género
            cout << "¿Que genero desea ver?" << endl;
            cout << "1) Drama" << endl;
            cout << "2) Acción" << endl;
            cout << "3) Misterio" << endl;
            cin >> genero;

            cout << "Numero minimo de rango (0-10): ";
            cin >> min;
            cout << "Numero maximo de rango (0-10): ";
            cin >> max;

            
            break;

        case 3:
            // Mostrar los videos en general de un cierto género
            break;

        case 4:
            // Mostrar los episodios de una determinada serie con un rango de calificación determinada
            break;

        case 5:
            // Mostrar las películas con cierto rango de calificación
            cout << "Numero minimo de rango (0-10): ";
            cin >> min;
            cout << "Numero maximo de rango (0-10): ";
            cin >> max;

            rangoPeliculas(peliculas, min, max);
            cout << endl;

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
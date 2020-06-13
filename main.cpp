#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

#include "Video.h"
#include "Peliculas.h"
#include "Series.h"
#include "Episodios.h"

// ##### 1 ##### Cargar archivos de datos
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
    } else {cout << "No se leyo archivo" << endl;}

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
    } else {cout << "No se leyo archivo" << endl;}

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
    } else {cout << "No se leyo archivo" << endl;}
}

// ##### 2 ##### Mostrar los videos en general con un cierto rango de calificación de un cierto género
void rangoGeneroVideos(vector<Peliculas*> peliculas, vector<Series*> series, 
vector<Episodios*> episodios, string genero, double min, double max) {

    int count = 1;

    for(int i = 0; i < peliculas.size(); i++) {
        
        string peliGenero = peliculas[i]->getGenero();
        
        if(peliculas[i]->getCalificacion() >= min && peliculas[i]->getCalificacion() <= max && peliGenero == genero) {

            cout << endl;
            cout << count << ") ";
            peliculas[i]->show();
            cout << endl;

            count++;
        }
    }

    for(int i = 0; i < episodios.size(); i++) {
        for(int j = 0; j < series.size(); j++) {

            if(series[j]->getID() == episodios[i]->getID()) {

                if(episodios[i]->getCalificacion() >= min && episodios[i]->getCalificacion() <= max && series[j]->getGenero() == genero) {

                cout << endl;
                cout << count << ") ";
                episodios[i]->show();
                cout << endl;

                count++;                  

                }
            }
        }
    } 


}

// ##### 3 ##### Mostrar los videos en general de un cierto género
void generoVideos(vector<Peliculas*> peliculas, vector<Series*> series, 
vector<Episodios*> episodios, string genero) {

    int count = 1; 

    for(int i = 0; i < peliculas.size(); i++) {
        
        string peliGenero = peliculas[i]->getGenero();
        
        if(peliGenero == genero) {

            cout << endl;
            cout << count << ") ";
            peliculas[i]->show();
            cout << endl;

            count++;
        }

    }

    for(int i = 0; i < episodios.size(); i++) {
        for(int j = 0; j < series.size(); j++) {

            if(series[j]->getID() == episodios[i]->getID()) {

                if(series[j]->getGenero() == genero) {

                cout << endl;
                cout << count << ") ";
                episodios[i]->show();
                cout << endl;

                count++;                  

                }
            }
        }
    } 

}

// ##### 4 ##### Mostrar los episodios de una determinada serie con un rango de calificación determinada
void episodiosSerieCalificacion(vector<Series*> series, 
vector<Episodios*> episodios, double min, double max) {

    int opcion;
    cout << endl << "Escoga una de las series" << endl << endl;

    int cont = 1;
    for(int i = 0; i < series.size(); i++) {
    
        cout << cont << ") ";
        series[i]->showNombre();
        cont++;
    }
    cout << "Ingresa el numero de la serie: ";
    cin >> opcion;

    cout << endl << "Deme el rango minimo de calificación (0.0 - 10.0): ";
    cin >> min;
    cout << "Deme el rango minimo de calificación (0.0 - 10.0): ";
    cin >> max;
    cout << endl;
    
    int count = 1;
    for(int i = 0; i < episodios.size(); i++) {
        if(series[opcion-1]->getID() == episodios[i]->getID()) {

            if(episodios[i]->getCalificacion() >= min && episodios[i]->getCalificacion() <= max) {

            cout << endl;
            cout << count << ") ";
            episodios[i]->show();
            cout << endl;

            count++;                  

            }
        }
        
    } 
}

// ##### 5 ##### Mostrar las películas con cierto rango de calificación
void rangoPeliculas(vector<Peliculas*> peliculas, double min, double max) {

    int count = 1;
    for(int i = 0; i < peliculas.size(); i++) {

        if(peliculas[i]->operator>=(min) && peliculas[i]->operator<=(max)) {
            cout << endl;
            cout << count << ") ";
            peliculas[i]->show();
            cout << endl;
            count++;

        }
    }
}

// ##### 6 ##### Calificar un video
void calificarVideo(vector<Peliculas*> peliculas, vector<Series*> series, vector<Episodios*> episodios) {

    int opcion;
    cout << endl << "Que tipo de video desea calificar: " << endl;
    cout << "1) Peliculas" << endl;
    cout << "2) Episodios de series" << endl;
    cout << "#: ";
    cin >> opcion;

    
    if (opcion == 1) {

        int count = 1;
        int opcPeli;
        cout << "Escoga una de las peliculas: " << endl;
        for(int i = 0; i < peliculas.size(); i++) {

            cout << endl;
            cout << count << ") ";
            peliculas[i]->show();
            cout << endl;

            count++;
        }
        cout << "#: ";
        cin >> opcPeli;

        cout << endl << "~~ Pelicula seleccionada ~~" << endl;
        peliculas[opcPeli-1]->show();
        cout << endl << "Calificación pasada: "; 
        peliculas[opcPeli-1]->caliShow();

        double nuevaCali;
        cout << "Ingrese su nueva calificación (0.0 - 10.0): ";
        cin >> nuevaCali;

        peliculas[opcPeli-1]->setCalificacion(nuevaCali);

    } else if(opcion == 2) {

        int count = 1;
        int opcEpi;
        cout << "Escoga una de los episodios: " << endl;
        for(int i = 0; i < episodios.size(); i++) {

            cout << endl;
            cout << count << ") ";
            episodios[i]->show();
            cout << endl;

            count++;
        }
        cout << "#: ";
        cin >> opcEpi;

        cout << endl << "~~ Episodio seleccionado ~~" << endl;
        episodios[opcEpi-1]->show();
        cout << endl << "Calificación pasada: "; 
        episodios[opcEpi-1]->caliShow();

        double nuevaCali;
        cout << "Ingrese su nueva calificación (0.0 - 10.0): ";
        cin >> nuevaCali;

        episodios[opcEpi-1]->setCalificacion(nuevaCali);

        /*
        int count = 1; ESTO YA NO
        int opcSerie;
        cout << endl << "Seleccione una serie: " << endl;
        for(int i = 0; i < series.size(); i++) {

            cout << endl;
            cout << count << ") ";
            series[i]->show();
            cout << endl;

            count++;
        }
        cout << "#: ";
        cin >> opcSerie;

        int countEpi = 1;
        int opcEpi;
        cout << endl << "Seleccione un episodio: " << endl;
        for(int i = 0; i < episodios.size(); i++) {
            if(series[opcSerie-1]->getID() == episodios[i]->getID()) {

                cout << endl;
                cout << countEpi << ") ";
                episodios[i]->show();
                cout << endl;

                countEpi++;           
            }
        }

        cout << "#: ";
        cin >> opcEpi;

        for(int i = 0; i < episodios.size(); i++) {
            if(series[opcSerie-1]->getID() == episodios[i]->getID()) {

                cout << endl << "~~ Episodio seleccionado ~~" << endl;;
                episodios[opcEpi-1]->show();
                cout << endl;

                cout << endl << "~~ Episodio seleccionado ~~" << endl;
                episodios[opcEpi-1]->show();
                cout << endl << "Calificación pasada: "; 
                episodios[opcEpi-1]->caliShow();

                double nuevaCali;
                cout << "Ingrese su nueva calificación (0.0 - 10.0): ";
                cin >> nuevaCali; 

                episodios[opcEpi-1]->setCalificacion(nuevaCali); 

            }
        }*/
    }
}

int main() {
    vector<Peliculas*> peliculas;
    vector<Series*> series;
    vector<Episodios*> episodios; 

    bool sw = true;
    int opcCase1;

    while (sw) {
        
        double min, max;
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
            cout << "Por favor escriba el nombre del genero (justo como se ve): ";
            cin >> genero;
            cout << endl;

            cout << "Numero minimo de calificación (0.0 - 10.0): ";
            cin >> min;
            cout << "Numero maximo de calificación (0.0 - 10.0): ";
            cin >> max;

            rangoGeneroVideos(peliculas, series, episodios, genero, min, max);
            cout << endl;

            break;

        case 3:
            // Mostrar los videos en general de un cierto género
            cout << "¿Que genero desea ver?" << endl;
            cout << "1) Drama" << endl;
            cout << "2) Acción" << endl;
            cout << "3) Misterio" << endl;
            cout << "Por favor escriba el nombre del genero (como se ve): ";
            cin >> genero;
            cout << endl;

            generoVideos(peliculas, series, episodios, genero);
            cout << endl;

            break;

        case 4:
            // Mostrar los episodios de una determinada serie con un rango de calificación determinada
            episodiosSerieCalificacion(series, episodios, min, max);
            cout << endl;

            break;

        case 5:
            // Mostrar las películas con cierto rango de calificación
            cout << "Numero minimo de rango (0.0 - 10.0): ";
            cin >> min;
            cout << "Numero maximo de rango (0.0 - 10.0): ";
            cin >> max;

            rangoPeliculas(peliculas, min, max);
            cout << endl;

            break;

        case 6:
            // Calificar un video
            calificarVideo(peliculas, series, episodios);
            cout << endl;
            break;

        case 0:
            // Salir
            sw = false;
            break;

        }
    }
    return 0;
}
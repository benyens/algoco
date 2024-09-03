#include "data_reader.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<int> leerListaDesdeCSV(const string& nombreArchivo) {
    vector<int> lista;
    ifstream archivo(nombreArchivo);
    string linea;

    if (archivo.is_open()) {
        if (getline(archivo, linea)) {
            stringstream ss(linea);
            string valor;
            while (getline(ss, valor, ',')) {
                lista.push_back(stoi(valor));
            }
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }

    return lista;
}

vector<vector<int>> leerMatrizDesdeCSV(const string& nombreArchivo) {
    vector<vector<int>> matriz;
    ifstream archivo(nombreArchivo);
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string valor;
            vector<int> fila;

            while (getline(ss, valor, ',')) {
                fila.push_back(stoi(valor));
            }

            matriz.push_back(fila);
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }

    return matriz;
}
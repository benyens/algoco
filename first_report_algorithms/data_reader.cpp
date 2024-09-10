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

void guardarListaEnCSV(const std::vector<int>& lista, const std::string& nombreArchivo) {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (size_t i = 0; i < lista.size(); ++i) {
            archivo << lista[i];
            if (i < lista.size() - 1) {
                archivo << ",";
            }
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }
}

void guardarMatrizEnCSV(const vector<vector<int>>& matriz, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (const auto& fila : matriz) {
            for (size_t i = 0; i < fila.size(); ++i) {
                archivo << fila[i];
                if (i < fila.size() - 1) {
                    archivo << ",";
                }
            }
            archivo << "\n";
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }
}

void guardarAlgoritmosEnCSV(const string& nombreAlgoritmo, double tiempoEjecucion, const string& archivoSalida) {
    ofstream file;
    file.open(archivoSalida, ios::app); // Para que no se sobreescriba el archivo.
    if (file.is_open()) {
        file << nombreAlgoritmo << "," << tiempoEjecucion << "\n";
        file.close();
    } else {
        cerr << "No se pudo abrir el archivo " << archivoSalida << endl;
    }
}
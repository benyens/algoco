#ifndef data_reader_H
#define data_reader_H

#include <vector>
#include <string>

using namespace std;

vector<int> leerListaDesdeCSV(const string& nombreArchivo);
vector<vector<int>> leerMatrizDesdeCSV(const string& nombreArchivo);
void guardarListaEnCSV(const vector<int>& lista, const string& nombreArchivo);
void guardarMatrizEnCSV(const vector<vector<int>>& matriz, const string& nombreArchivo);
void guardarAlgoritmosEnCSV(const string& nombreAlgoritmo, double tiempoEjecucion, const string& nombreArchivo);
#endif
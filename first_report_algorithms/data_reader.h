#ifndef data_reader_H
#define data_reader_H

#include <vector>
#include <string>

using namespace std;

vector<int> leerListaDesdeCSV(const string& nombreArchivo);
vector<vector<int>> leerMatrizDesdeCSV(const string& nombreArchivo);
void guardarListaEnCSV(const vector<int>& lista, const string& nombreArchivo);

#endif
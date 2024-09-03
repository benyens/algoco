#include <iostream>
#include "data_reader.h"
#include "algorithms.h"
#include <chrono>  // Para medir el tiempo

using namespace std;

int main() {
    // Leer lista desde CSV
    string archivoLista = "unsorted.csv";
    string archivoListaMiddle = "sorted_middle.csv";
    vector<int> lista = leerListaDesdeCSV(archivoLista);
    vector<int> listaMiddle = leerListaDesdeCSV(archivoListaMiddle);

    // Leer matrices desde CSV
    string squareMatrixCSV = "square_matrix.csv";
    string rectangularMatrixCSV = "rectangular_matrix.csv";
    vector<vector<int>>  squareMatrix = leerMatrizDesdeCSV(squareMatrixCSV);
    vector<vector<int>> rectangularMatrix = leerMatrizDesdeCSV(rectangularMatrixCSV);

    // Benchmarking de un algoritmo de ordenamiento (por ejemplo, Selection Sort)
    auto inicio = chrono::high_resolution_clock::now();
    selectionSort(lista);
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << "Selection Sort duró " << duracion.count() << " segundos.\n";

    // Benchmarking de mergeSort
    auto inicio = chrono::high_resolution_clock::now();
    mergeSort(listaMiddle, 0, listaMiddle.size() - 1); // Para lista medianamente ordenada (40% ordenada)
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << "Merge Sort duró " << duracion.count() << " segundos.\n";

    // Benchmarking de quickSort
    auto inicio = chrono::high_resolution_clock::now();
    quickSort(listaMiddle, 0, listaMiddle.size() - 1); // Para lista medianamente ordenada (40% ordenada)
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << "Quick Sort duró " << duracion.count() << " segundos.\n";

    // Benchmarking de la multiplicación de matrices
    inicio = chrono::high_resolution_clock::now();
    auto resultado = multiplicacionMatrices(squareMatrix, rectangularMatrix);
    fin = chrono::high_resolution_clock::now();
    duracion = fin - inicio;
    cout << "Multiplicación de matrices duró " << duracion.count() << " segundos.\n";

    // Benchmarking de Strassen
    inicio = chrono::high_resolution_clock::now();
    auto resultadoStrassen = strassen(squareMatrix, rectangularMatrix);
    fin = chrono::high_resolution_clock::now();
    duracion = fin - inicio;
    cout << "Strassen duró " << duracion.count() << " segundos.\n";
    
    return 0;
}
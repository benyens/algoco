#include <iostream>
#include "data_reader.h"
#include "algorithms.h"
#include <chrono>  // Para medir el tiempo.
#include <algorithm>  // Para sort de C++.

using namespace std;

int main() {
    // Carpeta donde se guardarán los resultados.
    string carpeta = "resultados/";
    string carpetatiempos = "tiempos/";

    // Leer lista desde CSV.
    string archivoLista4 = "datasets/unsorted10^4.csv";
    string archivoListaMiddle4 = "datasets/sorted_middle10^4.csv";
    vector<int> lista4 = leerListaDesdeCSV(archivoLista4);
    vector<int> listaMiddle4 = leerListaDesdeCSV(archivoListaMiddle4);
    string archivoLista5 = "datasets/unsorted10^5.csv";
    string archivoListaMiddle5 = "datasets/sorted_middle10^5.csv";
    vector<int> lista5 = leerListaDesdeCSV(archivoLista5);
    vector<int> listaMiddle5 = leerListaDesdeCSV(archivoListaMiddle5);


    // Leer matrices desde CSV.
    string squareMatrixCSV = "datasets/square_matrix.csv";
    string rectangularMatrixCSV = "datasets/rectangular_matrix.csv";
    vector<vector<int>>  squareMatrix = leerMatrizDesdeCSV(squareMatrixCSV);
    vector<vector<int>> rectangularMatrix = leerMatrizDesdeCSV(rectangularMatrixCSV);

#if ALG_SELECTION_10_4 || defined(RUN_ALL)
    { // Benchmarking de SelectionSort lista desordenada 10^4
        string archivoResultados = carpetatiempos + "10^4.csv";
        auto inicio = chrono::high_resolution_clock::now();
        selectionSort(lista4);
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Selection Sort con lista desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "sortedSelectionUnsorted10^4.csv";
        guardarListaEnCSV(lista4, archivoSalida);
        guardarAlgoritmosEnCSV("Selection Sort Unsorted 10^4", duracion.count(), archivoResultados);
    }
#endif

#if ALG_SELECTION_MIDDLE_10_4 || defined(RUN_ALL)
    { // Benchmarking de SelectionSort lista medianamente desordenada 10^4.
        string archivoResultados = carpetatiempos + "10^4.csv";
        auto inicio = chrono::high_resolution_clock::now();
        selectionSort(lista4);
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Selection Sort con lista medianamente desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "MiddleSortedSelection10^4.csv";
        guardarListaEnCSV(lista4, archivoSalida);
        guardarAlgoritmosEnCSV("Selection Sort Middle Sorted 10^4", duracion.count(), archivoResultados);
    }
#endif

#if ALG_MERGE_10_4 || defined(RUN_ALL)
    { // Benchmarking de MergeSort lista desordenada 10^4 .
        string archivoResultados = carpetatiempos + "10^4.csv";
        auto inicio = chrono::high_resolution_clock::now();
        mergeSort(lista4, 0, lista4.size() - 1); 
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Merge Sort con lista desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "sortedMergeUnsorted10^4.csv";
        guardarListaEnCSV(lista4, archivoSalida);
        guardarAlgoritmosEnCSV("Merge Sort Unsorted 10^4", duracion.count(), archivoResultados);
    }
#endif

#if ALG_MERGE_MIDDLE_10_4 || defined(RUN_ALL)
    { // Benchmarking de MergeSort lista medianamente desordenada 10^4.
        string archivoResultados = carpetatiempos + "10^4.csv";
        auto inicio = chrono::high_resolution_clock::now();
        mergeSort(listaMiddle4, 0, listaMiddle4.size() - 1); 
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Merge Sort con lista medianamente desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "sortedMergeMiddleSorted10^4.csv";
        guardarListaEnCSV(listaMiddle4, archivoSalida);
        guardarAlgoritmosEnCSV("Merge Sort Middle Sorted 10^4", duracion.count(), archivoResultados);
    }
#endif
 
#if ALG_QUICK_10_4 || defined(RUN_ALL)
    { // Benchmarking de QuickSort lista desordenada 10^4.
        string archivoResultados = carpetatiempos + "10^4.csv";
        auto inicio = chrono::high_resolution_clock::now();
        quickSort(lista4, 0, lista4.size() - 1); 
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Quick Sort con lista desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "quickSortUnsorted10^4.csv";
        guardarListaEnCSV(lista4, archivoSalida);
        guardarAlgoritmosEnCSV("Quick Sort Unsorted 10^4", duracion.count(), archivoResultados);
    }
#endif

#if ALG_QUICK_MIDDLE_10_4 || defined(RUN_ALL)
    { // Benchmarking de QuickSort lista medianamente desordenada 10^4.
        string archivoResultados = carpetatiempos + "10^4.csv";
        auto inicio = chrono::high_resolution_clock::now();
        quickSort(listaMiddle4, 0, listaMiddle4.size() - 1); // Para lista medianamente ordenada (40% ordenada).
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Quick Sort con lista medianamente desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "quickSortMiddleSorted10^4.csv";
        guardarListaEnCSV(listaMiddle4, archivoSalida);
        guardarAlgoritmosEnCSV("Quick Sort Middle Sorted 10^4", duracion.count(), archivoResultados);
    }
#endif

#if ALG_CPP_SORT_10_4 || defined(RUN_ALL)
    { //Benchmarking de Sort implementado en C++ 10^4.
        string archivoResultados = carpetatiempos + "10^4.csv";
        auto inicio = chrono::high_resolution_clock::now();
        sort(lista4.begin(), lista4.end());
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Sort de C++ con lista desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "sortedCpp10^4.csv";
        guardarAlgoritmosEnCSV("Sort C++ Unsorted 10^4", duracion.count(), archivoResultados);
    }
#endif
 
#if ALG_CPP_SORT_MIDDLE_10_4 || defined(RUN_ALL)
    { //Benchmarking de Sort implementado en C++ lista medianamente ordenada 10^4.
        string archivoResultados = carpetatiempos + "10^4.csv";
        auto inicio = chrono::high_resolution_clock::now();
        sort(listaMiddle4.begin(), listaMiddle4.end());
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Sort de C++ con lista medianamente desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "sortedCppMiddleSorted10^4.csv";
        guardarAlgoritmosEnCSV("Sort C++ Middle Sorted 10^4", duracion.count(), archivoResultados);
    }
#endif

#if ALG_SELECTION_10_5 || defined(RUN_ALL)
    { // Benchmarking de SelectionSort lista desordenada 10^5
        string archivoResultados = carpetatiempos + "10^5.csv";
        auto inicio = chrono::high_resolution_clock::now();
        selectionSort(lista5);
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Selection Sort con lista desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "sortedSelectionUnsorted10^5.csv";
        guardarListaEnCSV(lista5, archivoSalida);
        guardarAlgoritmosEnCSV("Selection Sort Unsorted 10^5", duracion.count(), archivoResultados);
    }
#endif

#if ALG_SELECTION_MIDDLE_10_5 || defined(RUN_ALL)
    { // Benchmarking de SelectionSort lista medianamente desordenada 10^5.
        string archivoResultados = carpetatiempos + "10^5.csv";
        auto inicio = chrono::high_resolution_clock::now();
        selectionSort(lista5);
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Selection Sort con lista medianamente desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "sortedSelectionMiddleSorted10^5.csv";
        guardarListaEnCSV(lista5, archivoSalida);
        guardarAlgoritmosEnCSV("Selection Sort Middle Sorted 10^5", duracion.count(), archivoResultados);
    }
#endif

#if ALG_MERGE_10_5 || defined(RUN_ALL)
    { // Benchmarking de MergeSort lista desordenada 10^5 .
        string archivoResultados = carpetatiempos + "10^5.csv";
        auto inicio = chrono::high_resolution_clock::now();
        mergeSort(lista5, 0, lista5.size() - 1); 
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Merge Sort con lista desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "sortedMergeUnsorted10^5.csv";
        guardarListaEnCSV(lista5, archivoSalida);
        guardarAlgoritmosEnCSV("Merge Sort Unsorted 10^5", duracion.count(), archivoResultados);
    }
#endif

#if ALG_MERGE_MIDDLE_10_5 || defined(RUN_ALL)
    { // Benchmarking de MergeSort lista medianamente desordenada 10^5.
        string archivoResultados = carpetatiempos + "10^5.csv";
        auto inicio = chrono::high_resolution_clock::now();
        mergeSort(listaMiddle5, 0, listaMiddle5.size() - 1); 
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Merge Sort con lista medianamente desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "sortedMergeMiddleSorted10^5.csv";
        guardarListaEnCSV(listaMiddle5, archivoSalida);
        guardarAlgoritmosEnCSV("Merge Sort Middle Sorted 10^5", duracion.count(), archivoResultados);
    }
#endif

#if ALG_QUICK_10_5 || defined(RUN_ALL)
    { // Benchmarking de QuickSort lista desordenada 10^5.
        string archivoResultados = carpetatiempos + "10^5.csv";
        auto inicio = chrono::high_resolution_clock::now();
        quickSort(lista5, 0, lista5.size() - 1); 
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Quick Sort con lista desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "quickSortUnsorted10^5.csv";
        guardarListaEnCSV(lista5, archivoSalida);
        guardarAlgoritmosEnCSV("Quick Sort Unsorted 10^5", duracion.count(), archivoResultados);
    }
#endif

#if ALG_QUICK_MIDDLE_10_5 || defined(RUN_ALL)
    { // Benchmarking de QuickSort lista medianamente desordenada 10^5.
        string archivoResultados = carpetatiempos + "10^5.csv";
        auto inicio = chrono::high_resolution_clock::now();
        quickSort(listaMiddle5, 0, listaMiddle5.size() - 1); // Para lista medianamente ordenada (60% ordenada).
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Quick Sort con lista medianamente desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "quickSortMiddleSorted10^5.csv";
        guardarListaEnCSV(listaMiddle5, archivoSalida);
        guardarAlgoritmosEnCSV("Quick Sort Middle Sorted 10^5", duracion.count(), archivoResultados);
    }
#endif

#if ALG_CPP_SORT_10_5 || defined(RUN_ALL)
    { //Benchmarking de Sort implementado en C++ 10^5.
        string archivoResultados = carpetatiempos + "10^5.csv";
        auto inicio = chrono::high_resolution_clock::now();
        sort(lista5.begin(), lista5.end());
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Sort de C++ con lista desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "sortedCpp10^5.csv";
        guardarAlgoritmosEnCSV("Sort C++ Unsorted 10^5", duracion.count(), archivoResultados);
    }
#endif

#if ALG_CPP_SORT_MIDDLE_10_5 || defined(RUN_ALL)
    { //Benchmarking de Sort implementado en C++ lista medianamente ordenada 10^5.
        string archivoResultados = carpetatiempos + "10^5.csv";
        auto inicio = chrono::high_resolution_clock::now();
        sort(listaMiddle5.begin(), listaMiddle5.end());
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Sort de C++ con lista medianamente desordenada duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "sortedCppMiddleSorted10^5.csv";
        guardarAlgoritmosEnCSV("Sort C++ Middle Sorted 10^5", duracion.count(), archivoResultados);
    }
#endif

#if ALG_MATRIX_MULTIPLICATION_RECTANGULAR || defined(RUN_ALL)
    { // Benchmarking de la multiplicación de matrices Rentangulares.
        string archivoResultados = carpetatiempos + "MatrixMultiplication.csv";
        auto inicio = chrono::high_resolution_clock::now();
        auto resultado = multiplicacionMatrices(rectangularMatrix, rectangularMatrix); // Se multiplica por si misma
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Multiplicación de matrices duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "MatrixMultiplicationRectangular.csv";
        guardarMatrizEnCSV(resultado, archivoSalida);
        guardarAlgoritmosEnCSV("Matrix Multiplication Rectangular", duracion.count(), archivoResultados);
    }
#endif

#if ALG_MATRIX_MULTIPLICATION_SQUARE || defined(RUN_ALL)
    { // Benchmarking de la multiplicación de matrices Cuadradas.
        string archivoResultados = carpetatiempos + "MatrixMultiplication.csv";
        auto inicio = chrono::high_resolution_clock::now();
        auto resultado = multiplicacionMatrices(squareMatrix, squareMatrix);
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Multiplicación de matrices duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "MatrixMultiplicationSquare.csv";
        guardarMatrizEnCSV(resultado, archivoSalida);
        guardarAlgoritmosEnCSV("Matrix Multiplication Square", duracion.count(), archivoResultados);
    }
#endif

#if ALG_OPTIMIZED_MULTIPLICATION_RECTANGULAR || defined(RUN_ALL)
    { // Benchmarking de la multiplicación de matrices optimizada Rectangulares.
        string archivoResultados = carpetatiempos + "MatrixMultiplication.csv";
        auto inicio = chrono::high_resolution_clock::now();
        auto resultadoOptimizado = multiplicacionMatricesOptimizada(rectangularMatrix, rectangularMatrix);  // Multiplicación optimizada.
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Multiplicación optimizada de matrices duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "optimizedMatrixMultiplicationRectangular.csv";
        guardarMatrizEnCSV(resultadoOptimizado, archivoSalida);
        guardarAlgoritmosEnCSV("Matrix Multiplication Rectangular Optimized", duracion.count(), archivoResultados);
    }
#endif

#if ALG_OPTIMIZED_MULTIPLICATION_SQUARE || defined(RUN_ALL)
    { // Benchmarking de la multiplicación de matrices optimizada Cuadradas.
        string archivoResultados = carpetatiempos + "MatrixMultiplication.csv";
        auto inicio = chrono::high_resolution_clock::now();
        auto resultadoOptimizado = multiplicacionMatricesOptimizada(squareMatrix, squareMatrix);  // Multiplicación optimizada.
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Multiplicación optimizada de matrices duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "optimizedMatrixMultiplicationSquare.csv";
        guardarMatrizEnCSV(resultadoOptimizado, archivoSalida);
        guardarAlgoritmosEnCSV("Matrix Multiplication Square Optimized", duracion.count(), archivoResultados);
    }
#endif

#if ALG_STRASSEN || defined(RUN_ALL)
    { // Benchmarking de Strassen.
        string archivoResultados = carpetatiempos + "MatrixMultiplication.csv";
        auto inicio = chrono::high_resolution_clock::now();
        auto resultadoStrassen = strassen(squareMatrix, squareMatrix); // Multiplicación de matrices cuadradas.
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "Strassen duró " << duracion.count() << " segundos.\n";
        string archivoSalida = carpeta + "StrassenMultiplication.csv";
        guardarMatrizEnCSV(resultadoStrassen, archivoSalida);
        guardarAlgoritmosEnCSV("Strassen", duracion.count(), archivoResultados);
    }
#endif

    return 0;
}
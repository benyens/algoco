#include "algorithms.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

//  Implementación de SelectionSort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

//  Implementación de MergeSort
void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}
// Implementación de MergeSort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// Implementación de QuickSort (Algoritmo adaptado de https://www.geeksforgeeks.org/cpp-program-for-quicksort/)

// Función para intercambiar dos elementos
void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función de partición. Con pivote random
int particion(vector<int>& arr, int bajo, int alto) {
    int indiceRandom= bajo + rand() % (alto - bajo + 1);

    // Intercambiar el pivote aleatorio con el último elemento
    intercambiar(arr[indiceRandom], arr[alto]);

    int pivote = arr[alto];  // Se toma el último elemento como pivote
    int i = (bajo - 1);  // Índice del elemento más pequeño

    for (int j = bajo; j <= alto - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivote) {
            i++;  // Incrementa el índice del elemento más pequeño
            intercambiar(arr[i], arr[j]);
        }
    }
    intercambiar(arr[i + 1], arr[alto]);
    return (i + 1);
}

// Implementación del algoritmo de QuickSort
void quickSort(vector<int>& arr, int bajo, int alto) {
    if (bajo < alto) {
        // Se obtiene el índice de partición
        int indiceParticion = particion(arr, bajo, alto);

        // Se ordenan recursivamente los elementos antes y después de la partición
        quickSort(arr, bajo, indiceParticion - 1);
        quickSort(arr, indiceParticion + 1, alto);
    }
}

//  Multiplicación de Matrices Tradicional Cúbica
vector<vector<int>> multiplicacionMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();

    // Resultado es una matriz de n x m
    vector<vector<int>> C(n, vector<int>(m, 0));

    // Multiplicación tradicional O(n^3)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

// Función para transponer una matriz
vector<vector<int>> transponerMatriz(const vector<vector<int>>& B) {
    int filas = B.size();
    int columnas = B[0].size();
    vector<vector<int>> B_transpuesta(columnas, vector<int>(filas));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            B_transpuesta[j][i] = B[i][j];
        }
    }

    return B_transpuesta;
}

// Algoritmo optimizado usando la transposición de la segunda matriz.
vector<vector<int>> multiplicacionMatricesOptimizada(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();
    
    vector<vector<int>> B_transpuesta = transponerMatriz(B);

    vector<vector<int>> C(n, vector<int>(m, 0));


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                C[i][j] += A[i][k] * B_transpuesta[j][k];  
            }
        }
    }

    return C;
}

// Implementación de Strassen.

// Función para sumar dos matrices
std::vector<std::vector<int>> sumarMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Función para restar dos matrices
std::vector<std::vector<int>> restarMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Implementación del algoritmo de Strassen (Código adaptado de GeeksforGeeks https://www.geeksforgeeks.org/strassens-matrix-multiplication/)
std::vector<std::vector<int>> strassen(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    
    // Caso base: multiplicación convencional
    if (n == 1) {
        std::vector<std::vector<int>> C(1, std::vector<int>(1, A[0][0] * B[0][0]));
        return C;
    }

    // Dividir las matrices en submatrices
    int newSize = n / 2;
    std::vector<int> inner(newSize);
    std::vector<std::vector<int>> 
        a11(newSize, inner), a12(newSize, inner), a21(newSize, inner), a22(newSize, inner),
        b11(newSize, inner), b12(newSize, inner), b21(newSize, inner), b22(newSize, inner);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calcular las siete multiplicaciones intermedias
    auto m1 = strassen(sumarMatrices(a11, a22), sumarMatrices(b11, b22));
    auto m2 = strassen(sumarMatrices(a21, a22), b11);
    auto m3 = strassen(a11, restarMatrices(b12, b22));
    auto m4 = strassen(a22, restarMatrices(b21, b11));
    auto m5 = strassen(sumarMatrices(a11, a12), b22);
    auto m6 = strassen(restarMatrices(a21, a11), sumarMatrices(b11, b12));
    auto m7 = strassen(restarMatrices(a12, a22), sumarMatrices(b21, b22));

    // Calcular las submatrices resultantes
    auto c11 = sumarMatrices(restarMatrices(sumarMatrices(m1, m4), m5), m7);
    auto c12 = sumarMatrices(m3, m5);
    auto c21 = sumarMatrices(m2, m4);
    auto c22 = sumarMatrices(restarMatrices(sumarMatrices(m1, m3), m2), m6);

    // Combinar las submatrices en la matriz resultante
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }

    return C;
}
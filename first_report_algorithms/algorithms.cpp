#include "algorithms.h"
#include <vector>
#include <algorithm>

using namespace std;

// Ejemplo de implementación: Selection Sort
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

// Implementa otros algoritmos como MergeSort, QuickSort aquí...

// Ejemplo de implementación: Multiplicación de Matrices Tradicional
vector<vector<int>> multiplicacionMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = B[0].size();
    int p = A[0].size();

    vector<vector<int>> C(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Implementa el algoritmo de Strassen aquí...

vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    // Implementación de Strassen
    return A;
}   
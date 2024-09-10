#ifndef algorithms_H
#define algorithms_H
#include <vector>

using namespace std;

void selectionSort(std::vector<int>& arr);
void mergeSort(std::vector<int>& arr, int left, int right);
void quickSort(std::vector<int>& arr, int low, int high);


vector<vector<int>> multiplicacionMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B);
vector<vector<int>> multiplicacionMatricesOptimizada(const vector<vector<int>>& A, const vector<vector<int>>& B);
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B);

#endif 
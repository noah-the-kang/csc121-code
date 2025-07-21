#ifndef SORTS_H
#define SORTS_H

#include <vector>
using namespace std;

// Selection Sort
void selectionSort(vector<int>& v);
void selectionSort(vector<int>& v, size_t begin, size_t end);

// Insertion Sort
void insertionSort(vector<int>& v);
void insertionSort(vector<int>& v, size_t begin, size_t end);

#endif

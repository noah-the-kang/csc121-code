#ifndef SORTS_H
#define SORTS_H

#include <vector>
using namespace std;

// Selection Sort
void selectionSort(vector<int>& v, size_t begin, size_t end);
inline void selectionSort(vector<int>& v) {
    selectionSort(v, 0, v.size());
}

// Insertion Sort
void insertionSort(vector<int>& v, size_t begin, size_t end);
inline void insertionSort(vector<int>& v) {
    insertionSort(v, 0, v.size());
}

#endif

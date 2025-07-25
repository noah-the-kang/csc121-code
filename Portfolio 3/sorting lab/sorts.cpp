#include "sorts.h"

// Selection Sort (range)
void selectionSort(vector<int>& v, size_t begin, size_t end) {
    for (size_t i = begin; i < end; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < end; ++j) {
            if (v[j] < v[minIndex]){
                minIndex = j;
            }
        }
        if (minIndex != i){
            std::swap(v[i], v[minIndex]);
        }
    }
}


// Insertion Sort (range)
void insertionSort(vector<int>& v, size_t begin, size_t end) {
    for (size_t i = begin + 1; i < end; ++i) {
        int key = v[i];
        size_t j = i;
        while (j > begin && v[j - 1] > key) {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = key;
    }
}

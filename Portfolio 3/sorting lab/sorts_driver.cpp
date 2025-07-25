#include <iostream>
#include <string>
#include <vector>
#include "sorts.h"

using namespace std;

vector<int> generateRandomVector(size_t size, int lowerBound,
                                 int upperBound) {
    vector<int> v(size);
    for (int i = 0; i < size; ++i) {
        v[i] = rand() % (upperBound - lowerBound + 1) + lowerBound;
    }
    return v;
}

int main(){
    cout << "Welcome to the Sorting Lab!" << endl;
    bool running = true;
    do {
        cout << "Would you like to sort a vector? (y/n): ";
        string input;
        getline(cin, input);
        if (input[0] == 'y') {
            // Call sorting function
            cout << "Enter the size of the vector: ";
            int vectorSize;
            cin >> vectorSize;
            cin.ignore();
            cout << "Enter the upper bound: ";
            int upperBound;
            cin >> upperBound;
            cin.ignore();
            cout << "Enter the lower bound: ";
            int lowerBound;
            cin >> lowerBound;
            cin.ignore();

            cout << "Choose a sorting algorithm (1 for Selection Sort,"
                 << " 2 for Insertion Sort): ";
            int choice;
            cin >> choice;
            cin.ignore();

            cout << "Would you like to sort within a specific range?"
                 << " (y/n): ";
            string rangeInput;
            bool isRanged = true;
            getline(cin, rangeInput);
            int rangeStart, rangeEnd;
            if (rangeInput[0] == 'y') {
                cout << "Enter the sorting range of the vector: " << endl;
                cout << "Start index: ";
                cin >> rangeStart;
                cin.ignore();
                cout << "End index: ";
                cin >> rangeEnd;
                cin.ignore();
            } else {
                isRanged = false;
            }

        
            vector<int> v = generateRandomVector(vectorSize, lowerBound,
                            upperBound);
            cout << "Generated vector: ";
            for (const auto& num : v) {
                cout << num << " ";
            }
            cout << endl;

            if (choice == 1) {
                cout << "You chose Selection Sort." << endl;
                if (isRanged){
                    selectionSort(v, rangeStart, rangeEnd);
                } else {
                    selectionSort(v);
                }
                cout << "Sorted vector: ";
                for (const auto& num : v) {
                    cout << num << " ";
                }
                cout << endl;
            } else if (choice == 2) {
                cout << "You chose Insertion Sort." << endl;
                if (isRanged){
                    insertionSort(v, rangeStart, rangeEnd);
                } else {
                    insertionSort(v);
                }
                cout << "Sorted vector: ";
                for (const auto& num : v) {
                    cout << num << " ";
                }
                cout << endl;
            } else {
                cout << "Invalid choice. Exiting." << endl;
            }

            
        } else {
            cout << "Have a great day!" << endl;
            running = false;
        }
    } while (running);


    return 0;
}

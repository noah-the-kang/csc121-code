#include <iostream>
#include <string>
#include <cctype>
#include "floorsuffix.h"
using namespace std;

// Reads building letter and room number from user input
void readRoom(char &building, int &roomNum) {
    string input;
    cout << "Which room are you looking for?  ";
    getline(cin, input);

    int i = 0;
    // Skip leading whitespace
    while (i < input.length() && isspace(input[i])) i++;

    // Find first letter (building)
    while (i < input.length() && !isalpha(input[i])) i++;
    if (i < input.length()) {
        building = toupper(input[i]);
        i++;
    } else {
        building = '?';
    }

    // Find first digit (room number)
    while (i < input.length() && !isdigit(input[i])) i++;
    roomNum = 0;
    while (i < input.length() && isdigit(input[i])) {
        roomNum = roomNum * 10 + (input[i] - '0');
        i++;
    }
}

// Determines the floor from the room number
int getFloor(int roomNum) {
    return roomNum / 100;
}

int main() {
    cout << endl;
    cout << "Welcome to the Floor Determining Program!!!" << endl << endl;

    string again;
    do {
        char building;
        int roomNum;

        readRoom(building, roomNum);

        cout << endl << "Thank you!!  Calculating...  Done." << 
            endl << endl;

        int floor = getFloor(roomNum);
        string suffix = getFloorSuffix(floor);

        cout << "Your room is on the " << floor << suffix
             << " floor of the " << building << " building." << endl 
             << endl;

        cout << "Do you have another class/office to find?  ";
        getline(cin, again);
        cout << endl;

    } while (!again.empty() && (tolower(again[0]) == 'y'));

    cout << "Thank you for using the FDP!!" << endl << endl;
    cout << "Endeavor to have a localized day..." << endl << endl;
    return 0;
}

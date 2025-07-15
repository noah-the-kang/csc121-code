#include <iostream>
#include <string>
#include <cctype>
#include "floorsuffix.h"
using namespace std;

// Reads building letter and room number from user input
void readRoom(string& building, int& roomNum) {
    string input;
    cout << "Which room are you looking for?  ";
    getline(cin, input);

    // Find first letter (building)
    int i = 0;
    while (i < input.length() && !isalpha(input[i])) i++;
    if (i < input.length()) {
        building = toupper(input[i]);
        i++;
    } else {
        building = "?";
    }

    // Find first digit (room number)
    while (i < input.length() && !isdigit(input[i])) i++;
    roomNum = 0;
    while (i < input.length() && isdigit(input[i])) {
        roomNum = roomNum * 10 + (input[i] - '0');
        i++;
    }
}

// Helper function to round up to the next multiple of 100
int roundUpTo100(int n) {
    return ((n + 99) / 100) * 100;
}

// Determines the floor from the room number and rooms per floor
int getFloor(int roomNum, int roomsPerFloor) {
    return roomNum / roomsPerFloor;
}

// Determines if a room number is valid for the building
bool isValidRoom(int roomNum, int roomsPerFloor, int numFloors, bool hasBasement, bool basementIsZero) {
    int totalFloors = numFloors + (hasBasement ? 1 : 0);
    int minRoom = 0;
    int maxRoom = roomsPerFloor * totalFloors - 1;
    if (roomNum < minRoom || roomNum > maxRoom)
        return false;
    // Room must be in the valid range for its floor
    int offset = roomNum % roomsPerFloor;
    if (offset >= roomsPerFloor)
        return false;
    return true;
}

int main() {
    cout << endl;
    cout << "            Welcome to the Floor Determining Program!!!" << endl << endl;

    string anotherBuilding;
    do {
        // --- Building setup phase ---
        char basementChoice;
        bool hasBasement = false;
        bool basementIsZero = true;
        int numFloors = 0;
        char buildingLetter = '?';
        int userRoomsPerFloor = 100;
        int roomsPerFloor = 100;

        cout << "Is there a basement in this building? (y/n): ";
        cin >> basementChoice;
        cin.ignore(10000, '\n');
        hasBasement = (tolower(basementChoice) == 'y');

        if (hasBasement) {
            char zeroOrOne;
            cout << "Does the basement count as 0-hundred or 1-hundred? (Enter 0 or 1): ";
            cin >> zeroOrOne;
            cin.ignore(10000, '\n');
            basementIsZero = (zeroOrOne == '0');
        }

        cout << "How many floors does the building have (not counting basement)? ";
        cin >> numFloors;
        cin.ignore(10000, '\n');

        cout << "How many rooms per floor? ";
        cin >> userRoomsPerFloor;
        cin.ignore(10000, '\n');
        roomsPerFloor = roundUpTo100(userRoomsPerFloor);

        cout << "What is the building's letter? ";
        cin >> buildingLetter;
        buildingLetter = toupper(buildingLetter);
        cin.ignore(10000, '\n');

        cout << endl;

        // --- Room loop for this building ---
        string again;
        do {
            string roomBuilding;
            int roomNum;

            readRoom(roomBuilding, roomNum);

            // Check if room is in this building
            if (toupper(roomBuilding[0]) != buildingLetter) {
                cout << "\nSorry, that room is not in this building (" << buildingLetter << ")." << endl << endl;
            } else if (!isValidRoom(roomNum, roomsPerFloor, numFloors, hasBasement, basementIsZero)) {
                cout << "\nSorry, room " << roomNum << " does not exist in this building." << endl << endl;
            } else {
                cout << endl << "Thank you!!  Calculating...  Done." << endl << endl;

                int floor = getFloor(roomNum, roomsPerFloor);

                // Adjust for basement if present
                if (hasBasement) {
                    if (basementIsZero) {
                        if (floor == 0)
                            cout << "Your room is in the basement of the " << buildingLetter << " building." << endl << endl;
                        else {
                            string suffix = getFloorSuffix(floor);
                            cout << "Your room is on the " << floor << suffix
                                 << " floor of the " << buildingLetter << " building." << endl << endl;
                        }
                    } else { // basement is 1-hundred
                        if (floor == 1)
                            cout << "Your room is in the basement of the " << buildingLetter << " building." << endl << endl;
                        else {
                            string suffix = getFloorSuffix(floor - 1);
                            cout << "Your room is on the " << (floor - 1) << suffix
                                 << " floor of the " << buildingLetter << " building." << endl << endl;
                        }
                    }
                } else {
                    string suffix = getFloorSuffix(floor);
                    cout << "Your room is on the " << floor << suffix
                         << " floor of the " << buildingLetter << " building." << endl << endl;
                }
            }

            cout << "Do you have another class/office to find in this building?  ";
            getline(cin, again);
            cout << endl;

            // Skip leading whitespace and check first non-whitespace character
            int i = 0;
            while (i < again.length() && isspace(again[i])) i++;
            if (i < again.length())
                again[0] = again[i];

        } while (!again.empty() && (again[0] == 'y' || again[0] == 'Y'));

        cout << "Do you have another building to set up? ";
        getline(cin, anotherBuilding);
        cout << endl;

        // Skip leading whitespace and check first non-whitespace character
        int i = 0;
        while (i < anotherBuilding.length() && isspace(anotherBuilding[i])) i++;
        if (i < anotherBuilding.length())
            anotherBuilding[0] = anotherBuilding[i];

    } while (!anotherBuilding.empty() && (anotherBuilding[0] == 'y' || anotherBuilding[0] == 'Y'));

    cout << "Thank you for using the FDP!!" << endl << endl;
    cout << "Endeavor to have a localized day..." << endl << endl;
    return 0;
}

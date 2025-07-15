#include <iostream>
#include <string>
#include <cctype>
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

// Determines the floor from the room number
int getFloor(int roomNum) {
    return roomNum / 100;
}

// Determines the floor suffix ("st", "nd", "rd", "th")
string getFloorSuffix(int floor) {
    if (floor % 100 >= 11 && floor % 100 <= 13)
        return "th";
    switch (floor % 10) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}

int main() {
    cout << endl;
    cout << "            Welcome to the Floor Determining Program!!!" << endl << endl;

    string again;
    do {
        string building;
        int roomNum;

        readRoom(building, roomNum);

        cout << endl << "Thank you!!  Calculating...  Done." << endl << endl;

        int floor = getFloor(roomNum);
        string suffix = getFloorSuffix(floor);

        cout << "Your room is on the " << floor << suffix
             << " floor of the " << building << " building." << endl << endl;

        cout << "Do you have another class/office to find?  ";
        getline(cin, again);
        cout << endl;
    } while (!again.empty() && (again[0] == 'y' || again[0] == 'Y'));

    cout << "Thank you for using the FDP!!" << endl << endl;
    cout << "Endeavor to have a localized day..." << endl << endl;
    return 0;
}

#include "roman.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to convert a single digit to its Roman numeral representation
string convertDigit(int digit, string ones, string fives, string tens) {
    string result = "";
    
    switch (digit){
        case 0: return ""; // No representation for zero in Roman numerals
        case 1: result = ones; break;
        case 2: result = ones + ones; break;
        case 3: result = ones + ones + ones; break;
        case 4: result = ones + fives; break;
        case 5: result = fives; break;
        case 6: result = fives + ones; break;
        case 7: result = fives + ones + ones; break;
        case 8: result = fives + ones + ones + ones; break;
        case 9: result = ones + tens; break;
        default: return "";
    }
    
    return result;
}

// Function to convert Arabic number to Roman numeral
string arabicToRoman(int number) {
    string romanNumeral = "";
    
    int thousands = number / 1000;
    int hundreds = (number % 1000) / 100;
    int tens = (number % 100) / 10;
    int ones = number % 10;
    
    romanNumeral += convertDigit(thousands, "M", "", "");
    romanNumeral += convertDigit(hundreds, "C", "D", "M");
    romanNumeral += convertDigit(tens, "X", "L", "C");
    romanNumeral += convertDigit(ones, "I", "V", "X");
    
    return romanNumeral;
}


// Displays a random pre-message before the Roman numeral result
void displayRandomPreMessage() {
    const string messages[] = {
        "Ah, I believe that would be",
        "Hmm...I think that is",
        "The Roman numeral is",
        "In ancient Rome, that would be"
    };
    int idx = rand() % 4;
    cout << messages[idx] << " ";
}


// Displays a random post-message after the Roman numeral result
void displayRandomPostMessage() {
    const string messages[] = {
        ", right?",
        "! Impressive.",
        ", as the Romans would say.",
        "! That's correct."
    };
    int idx = rand() % 4;
    cout << messages[idx] << endl;
}


// Combines displayRandomPreMessage and displayRandomPostMessage to 
// display the Roman numeral result with random messages
void displayResult(const string& romanResult) {
    displayRandomPreMessage();
    cout << romanResult;
    displayRandomPostMessage();
    cout << endl;
}

// Helper to trim whitespace
string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t");
    size_t end = s.find_last_not_of(" \t");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

// Function to get a valid number and optional fraction (only twelfths or 1/4 allowed)
bool getValidNumber(int& whole, int& fracNum, int& fracDen) {
    while (true) {
        cout << "Enter your whole number:  ";
        cin >> whole;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input. Please enter a valid integer.\n" << endl;
            continue;
        }
        if (whole >= 4000) {
            cout << "Oh, I'm sorry, that value is too large for Roman civilization." << endl;
            cout << "Please try again with a number [strictly] less than 4000, thank you..." << endl << endl;
            continue;
        }
        if (whole <= 0) {
            cout << "Oh, I'm sorry, that value is too small for Roman civilization." << endl;
            cout << "Please try again with a number [strictly] greater than 0, thank you..." << endl << endl;
            continue;
        }

        // Ask if user wants to enter a fraction
        cout << "Do you want to enter a fraction? (y/n): ";
        char fracChoice;
        cin >> fracChoice;
        cin.ignore(10000, '\n'); // clear the rest of the line

        if (tolower(fracChoice) == 'y') {
            cout << "Enter the numerator: ";
            cin >> fracNum;
            cout << "Enter the denominator: ";
            cin >> fracDen;
            cin.ignore(10000, '\n'); // clear the rest of the line

            // Only allow n/12 (1 <= n < 12), 1/2, 1/3, 1/4, 1/6
            bool valid = false;
            if (fracDen == 12 && fracNum > 0 && 12 % fracDen == 0){
                valid = true;
            }

            if (!valid) {
                cout << "\nOh, I'm sorry, Roman civilization did not respect the concept of '" << fracNum << "/" << fracDen << "'.\n";
                cout << "I'll have to insist that you stick strictly to versions of '1/12', '1/2', '1/3', '1/4', or '1/6'...\n\n    ...if you don't mind.\n" << endl;
                continue;
            }
        } else {
            fracNum = 0;
            fracDen = 1;
        }
        return true;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random

    string userResponse;
    int number, fracNum, fracDen;
    string romanResult;
    
    cout << endl;
    cout << "            Welcome to the Roman Numeral Program!!!" << endl;
    cout << endl;
    
    cout << "Will you be converting numbers to Roman form with us today?"  
        << " (y/n) ";
    getline(cin, userResponse);
    cout << endl;
    
    if (tolower(userResponse[0]) != 'y') {
        cout << "Thank you for using the RNP!!" << endl;
        cout << endl;
        cout << "Endeavor to have a plebeian day!" << endl;
        cout << endl;
        return 0;
    }
    
    cout << "Excellent!  Glad to have you along!" << endl;
    cout << endl;
    
    do {
        while (!getValidNumber(number, fracNum, fracDen)) {
            // keep prompting until valid
        }
        cout << endl;

        romanResult = arabicToRoman(number);

        displayResult(romanResult);

        cout << "Would you like to convert another number?  ";
        getline(cin, userResponse);
        cout << endl;

    } while (tolower(userResponse[0]) == 'y');
    
    cout << endl;
    cout << "Thank you for using the RNP!!" << endl;
    cout << endl;
    cout << "Endeavor to have a plebeian day!" << endl;
    cout << endl;
    
    return 0;
}

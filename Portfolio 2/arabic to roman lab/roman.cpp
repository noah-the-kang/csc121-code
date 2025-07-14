#include "roman.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

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
        default: return ""; // Invalid digit, should not happen in this context
    }
    
    return result;
}

// Function to convert Arabic number to Roman numeral
string arabicToRoman(int number) {
    string romanNumeral = "";
    
    // Extract each digit and convert based on place value
    int thousands = number / 1000;
    int hundreds = (number % 1000) / 100;
    int tens = (number % 100) / 10;
    int ones = number % 10;
    
    // Build the Roman numeral string from left to right
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

// Function to get a valid number from the user
int getValidNumber() {
    int num;
    while (true) {
        cout << "Enter your number:  ";
        cin >> num;

        if (cin.fail()) {
            cin.clear(); // clear error state
            cin.ignore(10000, '\n'); // discard invalid input
            cout << "\nInvalid input. Please enter a valid integer.\n" << endl;
            continue;
        }

        if (num >= 4000) {
            cout << "Oh, I'm sorry, that value is too large for Roman civilization." << endl;
            cout << "Please try again with a number [strictly] less than 4000, thank you..." << endl << endl;
            continue;
        }

        if (num <= 0) {
            cout << "Oh, I'm sorry, that value is too small for Roman civilization." << endl;
            cout << "Please try again with a number [strictly] greater than 0, thank you..." << endl << endl;
            continue;
        }

        break; // valid input
    }
    return num;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random

    string userResponse;
    int number;
    string romanResult;
    
    cout << endl;
    cout << "            Welcome to the Roman Numeral Program!!!" << endl;
    cout << endl;
    
    cout << "Will you be converting numbers to Roman form with us today?"  
        << " (y/n) ";
    cin >> userResponse;
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
        number = getValidNumber();
        cout << endl;

        romanResult = arabicToRoman(number);

        displayResult(romanResult);

        cout << "Would you like to convert another number?  ";
        cin >> userResponse;
        cout << endl;

    } while (tolower(userResponse[0]) == 'y');
    
    cout << endl;
    cout << "Thank you for using the RNP!!" << endl;
    cout << endl;
    cout << "Endeavor to have a plebeian day!" << endl;
    cout << endl;
    
    return 0;
}

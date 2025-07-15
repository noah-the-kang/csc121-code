#ifndef ROMAN_H
#define ROMAN_H

#include <string>
using namespace std;

// Roman numeral conversion
string convertDigit(int digit, string ones, string fives, string tens);
string arabicToRoman(int number);

// User input and validation
bool getValidNumber(int& whole, int& fracNum, int& fracDen);
string trim(const string& s);

// Roman fraction symbol
bool getRomanFraction(int fracNum, int fracDen);

// Display functions
void displayRandomPreMessage();
void displayRandomPostMessage();
void displayResult(const string& romanResult);

// Utility
inline bool isValidNumber(int num) { return num > 0 && num < 4000; }
inline bool wantsToContinue(string response) { return (tolower(response[0]) == 'y'); }

#endif

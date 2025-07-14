#ifndef ROMAN_H
#define ROMAN_H

#include <string>
using namespace std;

string convertDigit(int digit, string ones, string fives, string tens);
string arabicToRoman(int number);
bool wantsToContinue(string response);
bool isValidNumber(int num);
void displayRandomPreMessage();
void displayRandomPostMessage();
void displayResult(const string& romanResult);
int getValidNumber();

inline bool isValidNumber(int num) { return num > 0 && num < 4000; }
inline bool wantsToContinue(string response) { return (tolower(response[0]) == 'y'); }

#endif

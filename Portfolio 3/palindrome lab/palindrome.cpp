#include <iostream>
#include <vector>
#include <string>

using namespace std;

void removePunctuation(std::string& phrase) {
    const std::string punct = "?:;.!'\",`~@#$%^&*()-_+=|\\}{][/><";
    std::string result;
    for (char c : phrase) {
        if (punct.find(c) == std::string::npos && c != ' ') {
            result += c;
        }
    }
    phrase = result;
}


bool isPalindrome(string& phrase, bool isPhrase = false) {
    int left = 0;
    int right = phrase.size() - 1;

    if (isPhrase){
        removePunctuation(phrase);
    }
    
    while (left < right) {
        if (tolower(phrase[left]) != tolower(phrase[right])) {
            return false;
        } else {
            left++;
            right--;
        }
    }
    return true;
}

int main(){
    bool running = true;
    while (running){
        cout << "Would you like to check a word/phrase? (y/n): ";
        string running_response;
        cin >> running_response;
        if (running_response[0] == 'y'){
            cout << "Would you like to check a word or phrase? (w/p): ";
            string type_response;
            cin >> type_response;
            if (type_response[0] == 'w') {
                cout << "Enter a word: ";
                string word;
                cin >> word;
                if (isPalindrome(word)) {
                    cout << "The word is a palindrome." << endl;
                } else {
                    cout << "The word is not a palindrome." << endl;
                }
            } else {
                cout << "Enter a phrase: ";
                string phrase;
                cin.ignore();
                getline(cin, phrase);
                removePunctuation(phrase);
                if (isPalindrome(phrase, true)) {
                    cout << "The phrase is a palindrome." << endl;
                } else {
                    cout << "The phrase is not a palindrome." << endl;
                }
            }
        } else {
            cout << "Exiting!" << endl;
            running = false;
        }
    }


    return 0;
}

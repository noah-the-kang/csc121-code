#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool isConsonant(char c) {
    c = tolower(c);
    return (c >= 'a' && c <= 'z' && !isVowel(c));
}

string toPigLatin(const string& word) {
    if (word.empty()) {return word;}

    string pigLatinWord;

    // Cases
    // q vs qu
    if (word.substr(0,2) == "qu"){
        pigLatinWord = word.substr(2) + "quay";
    } else if (isConsonant(word[0]) && isConsonant(word[1]) && isConsonant(word[2])) {
        // Three consonants at the start
        pigLatinWord = word.substr(3) + word.substr(0, 3) + "ay";
    } else if (isConsonant(word[0]) && isConsonant(word[1])) {
        // Two consonants at the start
        pigLatinWord = word.substr(2) + word.substr(0, 2) + "ay";
    } else if (isConsonant(word[0])) {
        // One consonant at the start
        pigLatinWord = word.substr(1) + word[0] + "ay";
    } else if (isVowel(word[0])) {
        // Starts with a vowel
        pigLatinWord = word + "yay";
    } else {
        // Non-alphabetic character or empty string
        pigLatinWord = word;
    }



    return pigLatinWord;
}

string convertSentenceToPigLatin(const string& sentence) {
    string pigLatinSentence;
    size_t start = 0, end;

    while ((end = sentence.find(' ', start)) != string::npos) {
        pigLatinSentence += toPigLatin(sentence.substr(start, end - start)) + " ";
        start = end + 1;
    }
    pigLatinSentence += toPigLatin(sentence.substr(start)); // Last word

    return pigLatinSentence;
}

string pigLatinToEnglish(const string& word) {
    if (word.length() < 3) {return word;} // Too short to be Pig Latin

    string pigLatinWord = word.substr(0, word.length() - 2); // Remove "ay" or "way"
    char lastChar = pigLatinWord.back();

    if (lastChar == 'w') {
        return pigLatinWord.substr(0, pigLatinWord.length() - 3); // Remove "way"
    } else {
        return lastChar + pigLatinWord.substr(0, pigLatinWord.length() - 1); // Move last char to front
    }
}

string convertPigLatinSentenceToEnglish(const string& sentence) {
    string englishSentence;
    size_t start = 0, end;

    while ((end = sentence.find(' ', start)) != string::npos) {
        englishSentence += pigLatinToEnglish(sentence.substr(start, end - start)) + " ";
        start = end + 1;
    }
    englishSentence += pigLatinToEnglish(sentence.substr(start)); // Last word

    return englishSentence;
}


int main(){
    bool running = true;
    while (running){
        cout << "Would you like to use this program? (y/n) ";
        string choice;
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        if (choice[0] == 'y')
        {
            cout << "Would you like to convert to Pig Latin or English? (p/e) ";
            string choice;
            cin >> choice;
            cin.ignore(); // Clear the newline character from the input buffer
            if (choice[0] == 'p') {
                cout << "Enter a sentence to convert to Pig Latin: ";
                string sentence;
                getline(cin, sentence);
                cout << "Pig Latin: " << convertSentenceToPigLatin(sentence) << endl;
            } else if (choice[0] == 'e') {
                cout << "Enter a Pig Latin sentence to convert to English: ";
                string sentence;
                getline(cin, sentence);
                cout << "English: " << convertPigLatinSentenceToEnglish(sentence) << endl;
            } else {
                cout << "Invalid choice." << endl;
            }
        } else {
            running = false;
            cout << "Exiting!" << endl;
        }
        
        
    }


    return 0;
}

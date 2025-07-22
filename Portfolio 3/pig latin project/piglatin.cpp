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

string toPigLatin(const string& enteredWord) {
    const string punct = "?:;.!'\",`~@#$%^&*()-_+=|\\}{][/><";
    if (enteredWord.empty()) {return enteredWord;}

    string pigLatinWord;
    string word = "";

    for (char c : enteredWord) {
        word += tolower(c);
    }

    // Cases
    // Word starts with "qu"
    if (word.substr(0,2) == "qu"){
        pigLatinWord = word.substr(2) + "quay";
    } else if (isConsonant(word[0]) && isConsonant(word[1]) &&
        isConsonant(word[2])) {
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
        // All other cases
        pigLatinWord = word.substr(1) + word[0] + "ay";
    }

    // fix punctuation
    for (int i = 0; i < pigLatinWord.size(); i++) {
        if (punct.find(pigLatinWord[i]) != string::npos) {
            pigLatinWord += pigLatinWord[i];
            pigLatinWord.erase(i, 1);
        }
    }

    return pigLatinWord;
}


string convertSentenceToPigLatin(const string& sentence) {
    string pigLatinSentence;
    size_t start = 0;
    size_t end = sentence.find(' ', start);

    while (end != string::npos) {
        pigLatinSentence += toPigLatin(
            sentence.substr(start, end - start)) + " ";
        start = end + 1;
        end = sentence.find(' ', start);
    }
    pigLatinSentence += toPigLatin(sentence.substr(start)); // last word

    // Capitalize first letter
    pigLatinSentence[0] = static_cast<char>(toupper(pigLatinSentence[0]));

    return pigLatinSentence;
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
            cout << "Enter a sentence to convert to Pig Latin: ";
            string sentence;
            getline(cin, sentence);
            cout << "Pig Latin: " << convertSentenceToPigLatin(sentence)
                << endl;
        } else {
            running = false;
            cout << "Exiting!" << endl;
        }
        
        
    }


    return 0;
}

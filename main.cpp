#include <iostream>
#include <curl/curl.h>

using namespace std;

string getRandomString() {
    return "donut";
}

void showDifferences(string guess, string correctString) {
    for (size_t cur = 0; cur < correctString.size(); cur++) {

        if (cur >= guess.size()) {
            break;
        }

        if (guess[cur] == correctString[cur]) {
            cout << "\033[1;32m" << guess[cur] << "\033[0m";
        } else if (correctString.find(guess[cur])<correctString.length()) {
            cout << "\033[1;33m" << guess[cur] << "\033[0m";
        } else {
            cout << guess[cur];
        }


    }
    cout << endl;
}

bool makeGuess(string correctString) {
    string guess;
    cout << "Make a guess." << endl;
    cin >> guess;

    if (guess == correctString){
        cout << "Congrats!" << endl;
        return true;
    } else {
        showDifferences(guess, correctString);
        return false;
    }
}

int main() {
    string stringToGuess = getRandomString();
    cout << "Size of the correct string is: " << stringToGuess.length() << endl;
    int numGuesses = 5;

    for (int i = numGuesses; i > 0; i--) {
        if (makeGuess(stringToGuess)){
            break;
        }
    }
    cout << "Game Over." << endl;
}

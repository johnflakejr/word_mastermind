#include <iostream>
#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>

using namespace std;

string getRandomString() {
    
    curlpp::Cleanup myCleanup;

    ostringstream os;
    string url = "https://random-word-api.herokuapp.com/word?number=1";
    os << curlpp::options::Url(url);
    string stringToGuess = os.str();

    //Discard [" and "] from API results:
    int len = stringToGuess.length();
    stringToGuess = stringToGuess.substr(2, len - 4);
    return stringToGuess;
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
    cin >> guess;

    if (guess == correctString){
        cout << "Congrats!" << endl;
        return true;
    } else {
        showDifferences(guess, correctString);
        return false;
    }
}

void printCharFillIn(int len) {
    for (int i = 0; i < len; i++) {
        cout << "#";
    }
    cout << endl;
}

int main() {

    string stringToGuess = getRandomString();
    int len = stringToGuess.length();

    printCharFillIn(len);


    for (int i = len; i > 0; i--) {
        if (makeGuess(stringToGuess)){
            break;
        }
    }

    cout << "Game Over." << endl;
}

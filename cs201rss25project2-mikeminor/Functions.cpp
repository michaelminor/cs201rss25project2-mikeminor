#include "Functions.h"


bool isMenuItem(string str) {
    return (str == "1" || str == "2" || str == "3" || str == "4" || str == "5" || str == "6" || str == "Q" || str == "q");
}


string menu() {
    cout << "Select a game to play:\n";
    cout << "1 - Craps\n";
    cout << "2 - Scraps\n";
    cout << "3 - Rock, Paper, Scissors\n";
    cout << "4 - Rock, Paper, Scissors, Spock\n";
    cout << "5 - Blackjack\n";
    cout << "6 - Hangman\n";
    cout << "Q - Quit\n";
    cout << "Enter your choice: ";

    string choice;
    cin >> choice;


    while (!isMenuItem(choice)) {
        cout << "Invalid choice. Please enter a valid option: ";
        cin >> choice;
    }

    return choice;
}

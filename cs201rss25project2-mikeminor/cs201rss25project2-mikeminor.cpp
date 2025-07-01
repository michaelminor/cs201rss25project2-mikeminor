/*
Mike Minor
16358106
*/

#include "Games.h"
#include "Functions.h"


//main, utlizes do while loop to select game based on user input, while the option selected isn't q or Q
int main() {
    cout << "Welcome to My Games!\n";
    string choice;

    do {
        choice = menu();

        if (choice == "1") {
            craps();
        }
        else if (choice == "2") {
            scraps();
        }
        else if (choice == "3") {
            rockPaperScissors();
        }
        else if (choice == "4") {
            rockPaperScissorsSpock();
        }
        else if (choice == "5") {
            blackjack();
        }
        else if (choice == "6") {
            hangman();
        }

    } while (choice != "Q" && choice != "q");

    cout << "Thanks for playing!\n";
    return 0;
}

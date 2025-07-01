#include "Games.h"

using namespace std;

//function for craps, sets the rules for the game of craps. The game utilizes the rand built in function to roll a dice between 1-6.
void craps() {
    cout << "Welcome to Craps!\n";

    srand(time(0));
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int sum = dice1 + dice2;

    cout << "You rolled: " << dice1 << " + " << dice2 << " = " << sum << endl;

    if (sum == 7 || sum == 11) {
        cout << "You win!\n";
    }
    else if (sum == 2 || sum == 3 || sum == 12) {
        cout << "You lose!\n";
    }
    else {
        cout << "Rolling again...\n";
        int point = sum;
        while (true) {
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            sum = dice1 + dice2;
            cout << "You rolled: " << sum << endl;
            if (sum == point) {
                cout << "You win!\n";
                break;
            }
            else if (sum == 7) {
                cout << "You lose!\n";
                break;
            }
        }
    }
}

// similar to craps, sets rules for the game and uses rand function to roll dice
void scraps() {
    cout << "Welcome to Scraps!\n";

    srand(time(0));
    int dice1 = rand() % 8 + 1;
    int dice2 = rand() % 8 + 1;
    int dice3 = rand() % 8 + 1;
    int sum = dice1 + dice2 + dice3;

    cout << "You rolled: " << dice1 << " + " << dice2 << " + " << dice3 << " = " << sum << endl;

    if (sum > 12) {
        cout << "You win!\n";
    }
    else {
        cout << "You lose!\n";
    }
}

//play against the computer also using rand functiont o determine what the computer's selection will be. Branches to determine who wins, computer or player.
void rockPaperScissors() {
    cout << "Welcome to Rock, Paper, Scissors!\n";

    string choices[] = { "Rock", "Paper", "Scissors" };
    srand(time(0));
    int computerChoice = rand() % 3;

    cout << "Choose: Rock, Paper, or Scissors: ";
    string playerChoice;
    cin >> playerChoice;

    cout << "Computer chose: " << choices[computerChoice] << endl;

    if (playerChoice == choices[computerChoice]) {
        cout << "It's a tie!\n";
    }
    else if ((playerChoice == "Rock" && choices[computerChoice] == "Scissors") ||
        (playerChoice == "Paper" && choices[computerChoice] == "Rock") ||
        (playerChoice == "Scissors" && choices[computerChoice] == "Paper")) {
        cout << "You win!\n";
    }
    else {
        cout << "You lose!\n";
    }
}

//Same as above, adds spock to the logic.
void rockPaperScissorsSpock() {
    cout << "Welcome to Rock, Paper, Scissors, Spock!\n";

    string choices[] = { "Rock", "Paper", "Scissors", "Spock" };
    srand(time(0));
    int computerChoice = rand() % 4;

    cout << "Choose: Rock, Paper, Scissors, or Spock: ";
    string playerChoice;
    cin >> playerChoice;

    cout << "Computer chose: " << choices[computerChoice] << endl;

    if (playerChoice == choices[computerChoice]) {
        cout << "It's a tie!\n";
    }
    else if ((playerChoice == "Rock" && (choices[computerChoice] == "Scissors" || choices[computerChoice] == "Spock")) ||
        (playerChoice == "Paper" && (choices[computerChoice] == "Rock" || choices[computerChoice] == "Spock")) ||
        (playerChoice == "Scissors" && (choices[computerChoice] == "Paper" || choices[computerChoice] == "Spock")) ||
        (playerChoice == "Spock" && (choices[computerChoice] == "Rock" || choices[computerChoice] == "Scissors"))) {
        cout << "You win!\n";
    }
    else {
        cout << "You lose!\n";
    }
}

//establishes the game blackjack. Rand function to draw random value cards from 1-10 and determines who wins or loses based on highest score without going over 21.
void blackjack() {
    cout << "Welcome to Blackjack!\n";

    srand(time(0));
    int playerCard1 = rand() % 10 + 1;
    int playerCard2 = rand() % 10 + 1;
    int dealerCard = rand() % 10 + 1;
    int playerTotal = playerCard1 + playerCard2;

    cout << "You have: " << playerCard1 << " and " << playerCard2 << " (Total: " << playerTotal << ")\n";
    cout << "Dealer has: " << dealerCard << endl;

    if (playerTotal > 21) {
        cout << "Bust! You lose.\n";
    }
    else if (playerTotal == 21) {
        cout << "Blackjack! You win!\n";
    }
    else {
        cout << "Drawing dealer's second card...\n";
        int dealerTotal = dealerCard + (rand() % 10 + 1);
        cout << "Dealer's total: " << dealerTotal << endl;

        if (dealerTotal > 21 || playerTotal > dealerTotal) {
            cout << "You win!\n";
        }
        else if (playerTotal == dealerTotal) {
            cout << "It's a tie!\n";
        }
        else {
            cout << "You lose!\n";
        }
    }
}

/*function for hangman creates a vector for the words, rand to select the random word, creates a string of the length of the word _, as letters are guessed it is added to the guessed letters string,
  if a letter is correct the letter replaces the _ in each index the matching letter is found, as an incorrect guess is made the number of lives is decreased by 1, if the hidden word matches the guessed word the game ends
  with the player winning, if the lives = 0 then the while loop does not run and the else statement runs for a loss*/
void hangman() {
    cout << "Welcome to Hangman!\n";

    string words[] = { "apple", "banana", "cherry", "grape", "orange" };
    srand(time(0));
    string word = words[rand() % 5];
    string hidden(word.length(), '_');
    int lives = 6;
    string guessedLetters = "";

    while (lives > 0 && hidden != word) {
        cout << "Word: " << hidden << " (Lives: " << lives << ")\n";
        cout << "Enter a letter: ";
        char guess;
        cin >> guess;

        if (guessedLetters.find(guess) != string::npos) {
            cout << "You already guessed that letter!\n";
            continue;
        }
        guessedLetters += guess;

        bool correctGuess = false;
        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                hidden[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            lives--;
            cout << "Incorrect guess! Lives remaining: " << lives << endl;
        }
    }

    if (hidden == word) {
        cout << "You win! The word was: " << word << endl;
    }
    else {
        cout << "You lost! The word was: " << word << endl;
    }
}
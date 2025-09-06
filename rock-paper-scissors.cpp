#include <iostream>
#include <ctime>

//Function Declarations
char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer, int &playerScore, int &computerScore, int &tieScore);

int main() {
    char player;
    char computer;

    //scoreboard items
    int playerScore = 0, computerScore = 0, tieScore = 0; 

    std::cout << "Rock-Paper-Scissors Game!\n";
    std::cout << "Enter 'e' anytime to exit.\n\n";

    do {
        player = getUserChoice();

        if (player == 'e') {
            break; // exit
        }

        std::cout << "Your choice: ";
        showChoice(player);

        computer = getComputerChoice();
        std::cout << "Computer's choice: ";
        showChoice(computer);

        chooseWinner(player, computer, playerScore, computerScore, tieScore);

    } while (player != 'e');

    // Final results
    std::cout << "\n===== Final Scoreboard =====\n";
    std::cout << "You won: " << playerScore << " times\n";
    std::cout << "Computer won: " << computerScore << " times\n";
    std::cout << "Ties: " << tieScore << "\n";
    std::cout << "Thanks for playing!\n";

    return 0;
}

char getUserChoice() {
    char player;

    do {
        std::cout << "\nChoose one of the following\n";
        std::cout << "*************************\n";
        std::cout << "'r' for Rock\n";
        std::cout << "'p' for Paper\n";
        std::cout << "'s' for Scissors\n";
        std::cout << "'e' to Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> player;

        if (player != 'r' && player != 'p' && player != 's' && player != 'e') {
            std::cout << "Invalid input! Please try again.\n";
        }

    } while (player != 'r' && player != 'p' && player != 's' && player != 'e');

    return player;
}

//computer will generate random choice 
char getComputerChoice() {
    srand(time(0)); 
    int num = rand() % 3 + 1;

    switch (num) {
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }
    return 0; 
}

void showChoice(char choice) {
    switch (choice) {
        case 'r': std::cout << "Rock\n"; break;
        case 'p': std::cout << "Paper\n"; break;
        case 's': std::cout << "Scissors\n"; break;
        case 'e': std::cout << "Exit\n"; break;
    }
}

void chooseWinner(char player, char computer, int &playerScore, int &computerScore, int &tieScore) {
    if (player == computer) {
        std::cout << "It's a tie!\n";
        tieScore++;
    }
    else if ((player == 'r' && computer == 's') ||
             (player == 'p' && computer == 'r') ||
             (player == 's' && computer == 'p')) {
        std::cout << "You win!\n";
        playerScore++;
    }
    else {
        std::cout << "You lose!\n";
        computerScore++;
    }
}

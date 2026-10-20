#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> computerChoice(1, 3);
    int playerChoice;
    int playerScore = 0;
    int computerScore = 0;

    std::cout << "Rock Paper Scissors\n";

    while (true) {
        std::cout << "\n1. Rock\n2. Paper\n3. Scissors\n0. Quit\nChoose: ";
        if (!(std::cin >> playerChoice) || playerChoice == 0) {
            break;
        }

        if (playerChoice < 1 || playerChoice > 3) {
            std::cout << "Invalid choice.\n";
            continue;
        }

        const int computer = computerChoice(generator);
        const char* names[] = {"", "Rock", "Paper", "Scissors"};
        std::cout << "You chose: " << names[playerChoice] << "\n";
        std::cout << "Computer chose: " << names[computer] << "\n";

        if (playerChoice == computer) {
            std::cout << "Draw.\n";
        } else if ((playerChoice == 1 && computer == 3) ||
                   (playerChoice == 2 && computer == 1) ||
                   (playerChoice == 3 && computer == 2)) {
            ++playerScore;
            std::cout << "You win.\n";
        } else {
            ++computerScore;
            std::cout << "Computer wins.\n";
        }

        std::cout << "Score: You " << playerScore << " - " << computerScore
                  << " Computer\n";
    }

    std::cout << "Final score: You " << playerScore << " - " << computerScore
              << " Computer\n";
    return 0;
}

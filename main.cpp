#include <iostream>
#include <string>
#include "FBullCowGame.cpp"
void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main()
{
    bool bPlayAgain;
    do
    {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    } while (bPlayAgain);

    return 0; // exit the application
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? ";
    std::string Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
}

void PlayGame()
{
    BCGame.Reset();
    int MaxTries = BCGame.GetMaxTries();

    //  loop for the number of turns asking guesses
    // TODO change from FOR to WHILE loop once we are validating tries
    for (int count = 1; count <= MaxTries; count++)
    {
        std::string Guess = GetGuess(); // TODO make loop checking valid

        // submit valid guess to the game
        // print number of bulls and cows

        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }

    // TODO summarise game
}

// introduce the game
void PrintIntro()
{
    constexpr int WORLD_LENGTH = 9;

    std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
    std::cout << "Can you guess the " << WORLD_LENGTH;
    std::cout << " letter isogram I'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

std::string GetGuess()
{
    int CurrentTry = BCGame.GetCurrentTry();

    // get guess from the player
    std::cout << "Enter you guess (" << CurrentTry << "): ";
    std::string Guess = "";
    std::getline(std::cin, Guess);
    return Guess;
}

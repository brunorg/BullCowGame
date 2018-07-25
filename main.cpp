/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
 */
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // instantiate a new game

// the entry point32 for our application
int main()
{
    bool bPlayAgain = false;
    do
    {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    } while (bPlayAgain);

    return 0; // exit the application
}

// introduce the game
void PrintIntro()
{
    std::cout << "\n\nWelcome to Bulls and Cows, a fun word game" << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();

    //  loop asking for guesses while the game is NOT won
    // and there are still tries remaining

    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
    {
        FText Guess = GetValidGuess(); // TODO make loop checking valid

        // submit valid guess to the game, and receive count
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

        // print32 number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
    }

    PrintGameSummary();
}

// loop continually until the user gives a valide guess
FText GetValidGuess()
{
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid;
    do
    {
        // get guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Enter you guess (" << CurrentTry << "): ";
        std::getline(std::cin, Guess);

        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
        case EGuessStatus::Wrong_Lenght:
            std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
            break;
        case EGuessStatus::Not_Isogram:
            std::cout << "Please enter without repeating letters.\n";
            break;
        case EGuessStatus::Not_LowerCase:
            std::cout << "Please enter all lowercase letters.\n";
            break;
        default:
            // assume the guess is valid
            break;
        }
        std::cout << std::endl;
    } while (Status != EGuessStatus::OK);
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again with the same hidden word (y/n)? ";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

// introduce the game
void PrintGameSummary()
{
    if (BCGame.IsGameWon()) {
        std::cout << "Congratulations YOU WIN the game in " << BCGame.GetCurrentTry() << " tries!\n\n";
    } else {
        std::cout << "You lose. Better luck next time!!\n\n";
    }
    return;
}
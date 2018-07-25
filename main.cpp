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
    std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();

    //  loop for the number of turns asking for guesses
    for (int32 count = 1; count <= MaxTries; count++) // TODO change from FOR to WHILE
    {
        FText Guess = GetValidGuess(); // TODO make loop checking valid

        // submit valid guess to the game, and receive count
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

        // print32 number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
        std::cout << "Your guess was: " << Guess << "\n\n";
    }

    // TODO summarise game
}

// loop continually until the user gives a valide guess
FText GetValidGuess()
{
    EGuessStatus Status = EGuessStatus::Invalid;
    do
    {
        // get guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Enter you guess (" << CurrentTry << "): ";
        FText Guess = "";
        std::getline(std::cin, Guess);

        EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
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
            return Guess;
        }
    } while (Status != EGuessStatus::OK);
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again (y/n)? ";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

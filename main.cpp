#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();

// the entry point for our application
int main()
{
    PrintIntro();
    PlayGame();
    return 0; // exit the application
}

void PlayGame()
{
    // loop for the number of turns asking for guesses
    constexpr int NUMBER_OF_TURNS = 5;
    for (int i = 1; i <= NUMBER_OF_TURNS; i++)
    {
        string Guess = GetGuess();
        cout << "Your guess was: " << Guess << endl;
        cout << endl;
    }
}

// introduce the game
void PrintIntro()
{
    constexpr int WORLD_LENGTH = 9;

    cout << "Welcome to Bulls and Cows, a fun word game" << endl;
    cout << "Can you guess the " << WORLD_LENGTH;
    cout << " letter isogram I'm thinking of?" << endl;
    cout << endl;
    return;
}

string GetGuess()
{
    // get guess from the player
    cout << "Enter you guess: ";
    string Guess = "";
    getline(cin, Guess);
    return Guess;
}

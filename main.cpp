#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// the entry point for our application
int main()
{
    PrintIntro();

    // loop for the number of turns asking for guesses
    constexpr int NUMBER_OF_TURNS = 5;
    for (int i = 1; i <= NUMBER_OF_TURNS; i++)
    {
        GetGuessAndPrintBack();
        cout << endl;
    }

    cout << endl;
    return 0;
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

string GetGuessAndPrintBack()
{
    cout << "Enter you guess: ";
    string Guess = "";
    getline(cin, Guess);

    // print the guess back
    cout << "Your guess was: " << Guess << endl;
    return Guess;
}
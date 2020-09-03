#include <iostream>
#include <ctime>

bool bGameOver = false;

void PrintIntro(int Difficulty)
{
    std::cout << "\n\n   |------| |----|    |-------|\n";
    std::cout << "  |....|    |.|  |.|  |.|      \n";
    std::cout << " |...|      |.|   |.| |.----|  \n";
    std::cout << "  |....|    |.|  |.|  |.|      \n";
    std::cout << "   |------| |----|    |-|      \n\n";
    std::cout << "CDF Mainframe Scan Software v2.34\n\n"
              << "Security Level: " << Difficulty;
}

bool PlayGame(int Difficulty)
{
    PrintIntro(Difficulty);
    std::cout << "\nIllegal blocking of lawful inspection detected.\nEnter the three number code to access the data...\n\n";

    srand (time(NULL));

    const int FirstNumber = rand() % Difficulty + Difficulty;
    const int SecondNumber = rand() % Difficulty + Difficulty;
    const int ThirdNumber = rand() % Difficulty + Difficulty;

    const int Sum = FirstNumber + SecondNumber + ThirdNumber;
    const int Product = FirstNumber * SecondNumber * ThirdNumber;

    std::cout << "\nThe three code numbers add up to: " << Sum;
    std::cout << "\nThe code numbers multiplied equal: " << Product;

    int PlayerGuessA, PlayerGuessB, PlayerGuessC;

    std::cout << "\nEnter each number of the code followed by space then press ENTER...\n";
    std::cin >> PlayerGuessA;
    std::cin >> PlayerGuessB;
    std::cin >> PlayerGuessC;
    std::cout << "\nYou entered: " << PlayerGuessA << " " << PlayerGuessB << " " << PlayerGuessC;
    std::cout << std::endl;

    const int GuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
    const int GuessProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;

    if (GuessSum == Sum && GuessProduct == Product)
    {
        std::cout << "Code correct, access granted";
        bGameOver = false;
        return true;
    }
    else
    {
        std::cout << "Code incorrect, access denied\n"
                  << "The code was: " << FirstNumber << " " << SecondNumber << " " << ThirdNumber;
        bGameOver = true;
        return false;
    }
}

int main()
{
    int LevelDifficulty = 1;
    int MaxDifficulty = 5;
    while (bGameOver == false && LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    if (LevelDifficulty == MaxDifficulty)
    {
        std::cout << "\n\n Hack success, downloading evidence now...";
    }

    return 0;
}

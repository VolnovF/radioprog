#include "constants.h"

#include <iostream>

double readTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double towerHeight{};
    std::cin >> towerHeight;

    return towerHeight;
}

double calculateBallHeight(double towerHeight, int fallTime)
{
    double ballHeight{ towerHeight - ((gravity * fallTime * fallTime) / 2) };

    return ballHeight;
}

void printBallHeight(double ballHeight, int fallTime)
{
    if (ballHeight > 0)
    {
        std::cout << "At " << fallTime << " seconds, the ball is at height: " << ballHeight << " meters\n";
    }
    else
    {
        std::cout << "At " << fallTime << " seconds, the ball is on the ground.\n";
    }
}

void calculateAndPrintBallHeight(double towerHeight, int fallTime)
{
    double ballHeight{ calculateBallHeight(towerHeight, fallTime) };

    printBallHeight(ballHeight, fallTime);
}

int main()
{
    double towerHeight{ readTowerHeight() };
    
    for (int time{ 0 }; time <= timeToFall; ++time)
    {
        calculateAndPrintBallHeight(towerHeight, time);
    };

    return 0;
}
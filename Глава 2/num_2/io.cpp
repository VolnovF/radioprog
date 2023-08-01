#include <iostream>

int readNumber()
{
    std::cout << "Enter an integer: ";
    int number{};
    std::cin >> number;
    return number;
}

void writeAnswer(int result)
{
    std::cout << "x + y is " << result << ".\n";
}
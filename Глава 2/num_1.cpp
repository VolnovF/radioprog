#include <iostream>

int readNumber();
void writeAnswer(int result);

int main()
{
    // Ввод значений
    int x{ readNumber() };
    int y{ readNumber() };

    // Вывод результатов сложения
    writeAnswer(x + y);

    return 0;
}

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
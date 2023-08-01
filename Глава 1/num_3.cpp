#include <iostream>

int main()
{
    // Ввод первого числа
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    
    // Ввод второго числа
    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    // Вывод результатов сложения и вычитания
    std::cout << x << " + " << y << " is " << x + y << ".\n";
    std::cout << x << " - " << y << " is " << x - y << ".\n";

    return 0;
}
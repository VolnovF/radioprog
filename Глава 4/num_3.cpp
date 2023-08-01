#include <iostream>

double readDouble()
{
    std::cout << "Enter a double value: ";
    double value{};
    std::cin >> value;
    return value;
}

char readOperator()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;
}

void printAnswer(char op, double x, double y)
{
    switch (op)
    {
        case '+': 
        {
            std::cout << x << " + " << y << " is " << x + y << '\n';
            break;
        }
        case '-':
        {
            std::cout << x << " - " << y << " is " << x - y << '\n';
            break;
        }
        case '*':
        {
            std::cout << x << " * " << y << " is " << x * y << '\n';
            break;
        }
        case '/':
        {
            std::cout << x << " / " << y << " is " << x / y << '\n';
            break;
        }
    }
}

int main()
{
    double x{ readDouble() };
    double y{ readDouble() };

    char operation{ readOperator() };

    printAnswer(operation, x, y);

    return 0;
}
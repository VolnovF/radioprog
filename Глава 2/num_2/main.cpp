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
#include "io.h"
#include <iostream>

int main()
{
    // Ввод значений
    int x{ readNumber() };
    int y{ readNumber() };

    // Вывод результатов сложения
    writeAnswer(x + y);

    return 0;
}
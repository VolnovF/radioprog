# Глава 7 – Порядок выполнения программы и обработка ошибок  

___

## Вопрос 1

В главе 4 мы написали программу, имитирующую падение мяча с башни. Поскольку у нас еще не было циклов, мяч мог падать только 5 секунд.

Возьмите приведенную ниже программу и измените ее так, чтобы мяч падал столько секунд, сколько необходимо, пока не достигнет земли.

`constants.h`:

```cpp
#ifndef CONSTANTS_H
#define CONSTANTS_H
 
namespace myConstants
{
    const double gravity { 9.8 }; // в метрах/секунда в квадрате
}
#endif
```

Основной файл исходного кода:

```cpp
#include <iostream>
#include "constants.h"
 
double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };
 
    // Проверяем, не ушли ли мы под землю
    // Если это так, устанавливаем высоту на уровне земли
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}
 
void calculateAndPrintHeight(double initialHeight, int time)
{
    std::cout << "At " << time << " seconds, the ball is at height: " << calculateHeight(initialHeight, time) << "\n";
}
 
int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;
        
    calculateAndPrintHeight(initialHeight, 0);
    calculateAndPrintHeight(initialHeight, 1);
    calculateAndPrintHeight(initialHeight, 2);
    calculateAndPrintHeight(initialHeight, 3);
    calculateAndPrintHeight(initialHeight, 4);
    calculateAndPrintHeight(initialHeight, 5);
        
    return 0;
}
```

__Ответ:__

[num_1](num_1)
___

## Вопрос 2

Простое число – это натуральное число больше 1, которое без остатка делится только на 1 и само себя. Завершите следующую программу, написав функцию `isPrime()` с использованием цикла `for`.

```cpp
#include <iostream>
#include <cassert>
 
bool isPrime(int x)
{
    // напишите эту функцию с помощью цикла for
}
 
int main()
{
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(!isPrime(99));
    assert(isPrime(13417));
 
    std::cout << "Success!";
 
    return 0;
}
```

__Ответ:__

[num_2.cpp](num_2.cpp)

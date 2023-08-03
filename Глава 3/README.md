# Глава 3 – Отладка программ на C++

___

## Вопрос 1

Используйте встроенный отладчик, чтобы пошагово выполнить следующую программу и отследить значение `x`. На основании полученной информации исправьте программу:

```cpp
#include <iostream>
 
int readNumber(int x)
{
    std::cout << "Please enter a number: ";
    std::cin >> x;
    return x;
}
 
void writeAnswer(int x)
{
    std::cout << "The sum is:" << x;
}
 
int main()
{
    int x {};
    readNumber(x);
    x = x + readNumber(x);
    writeAnswer(x);
 
    return 0;
}
```

__Ответ:__

[num_1.cpp](num_1.cpp)
___

## Вопрос 2

Используйте встроенный отладчик для пошагового выполнения следующей программы. Для входных данных введите `8` и `4`. На основе полученной информации исправьте программу:

```cpp
#include <iostream>
 
int readNumber()
{
    std::cout << "Please enter a number:";
    int x {};
    std::cin >> x;
    return x;
}
 
void writeAnswer(int x)
{
    std::cout << "The quotient is:" << x;
}
 
int main()
{
    int x{ };
    int y{ };
    x = readNumber();
    x = readNumber();
    writeAnswer(x/y);
 
    return 0;
}
```

__Ответ:__

[num_2.cpp](num_2.cpp)
___

## Вопрос 3

Как выглядит стек вызовов в следующей программе, когда точка выполнения находится в строке 4? Для этого упражнения нужны только имена функций, а не номера строк, указывающие точки возврата.

```cpp
#include <iostream>
 
void d()
{ // здесь
}
 
void c()
{
}
 
void b()
{
    c();
    d();
}
 
void a()
{
    b();
}
 
int main()
{
    a();
 
    return 0;
}
```

__Ответ:__

Снизу вверх: `main()`, `a()`, `b()`, `d()`.

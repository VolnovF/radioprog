# Глава 6 – Область видимости объектов и преобразования  

___

## Вопрос 1

Исправьте следующую программу:

```cpp
#include <iostream>
 
int main()
{
        std::cout << "Enter a positive number: ";
        int num{};
        std::cin >> num;
 
 
        if (num < 0)
                std::cout << "Negative number entered.  Making positive.\n";
                num = -num;
 
        std::cout << "You entered: " << num;
 
        return 0;
}
```

__Ответ:__

[num_1.cpp](num_1.cpp)
___

## Вопрос 2

Напишите файл с именем `constants.h`, который поможет запуститься следующей программе. Если ваш компилятор поддерживает C++17, используйте переменные `inline constexpr`. В противном случае используйте обычные переменные `constexpr`. Для `max_class_size` вы можете выбрать любое значение.

```cpp
main.cpp:
#include "constants.h"
 
#include <iostream>
 
int main()
{
        std::cout << "How many students are in your class? ";
        int students{};
        std::cin >> students;
 
 
        if (students > constants::max_class_size)
                std::cout << "There are too many students in this class";
        else
                std::cout << "This class isn't too large";
 
        return 0;
}
```

__Ответ:__

[num_2](num_2)
___

## Вопрос 3

Завершите следующую программу, написав функцию `passOrFail()`, которая должна возвращать `true` для первых 3 вызовов и `false` для последующих.

```cpp
#include <iostream>
 
int main()
{
        std::cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
        std::cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
        std::cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
        std::cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
        std::cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';
 
        return 0;
}
```

Программа должна выдать следующий результат:

```text
User #1: Pass
User #2: Pass
User #3: Pass
User #4: Fail
User #5: Fail
```

__Ответ:__

[num_3.cpp](num_3.cpp)

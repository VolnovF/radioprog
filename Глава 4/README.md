# Глава 4 – Основные типы данных

___

## Вопрос 1

Почему символьные константы обычно лучше, чем литеральные константы? Почему символьные константы с `const`/`constexpr` обычно лучше, чем символьные константы с `#define`?

__Ответ:__

Использование литеральных констант затрудняет понимание кода и предназначения константы.

Символьные констаны с `const`/`constexpr` обычно лучше объектно-подобных макросов препроцессора по нескольким причинам:

1) Макросы препроцессора не отображаются в отладчике;

2) Идентификаторы макросов могут конфликтовать с кодом, в том числе из-за не соблюдения ими правил областей видимости.

___

## Вопрос 2

Выберите подходящий тип данных для переменной в каждой из следующих ситуаций. Будьте как можно более конкретными. Если ответ является целочисленным типом, выберите `int`, `long` или определенный целочисленный тип фиксированной ширины (например, `std::int_fast16_t`) в зависимости от диапазона значений. Если переменная должна быть константной, укажите это.

a) возраст пользователя (в годах)

b) нравится ли пользователю цвет, или нет

c) число пи (3,14159265)

d) количество страниц в учебнике (предположим, что размер важен)

e) длина дивана в метрах с точностью до 2 знаков после запятой

f) сколько раз вы моргнули с момента своего рождения (примечание: ответ исчисляется миллионами)

g) пользователь выбирает пункт в меню, в котором список пунктов пронумерован буквами

h) год рождения (при условии, что размер важен)

__Ответ:__

a) `int`

b) `bool`

c) `constexpr double`

d) `std::int_least16_t`

e) `float`

f) `std::int_least32_t`

g) `char`

h) `std::int_least16_t`

___

## Вопрос 3

Напишите следующую программу: Пользователя просят ввести 2 числа с плавающей запятой (используйте тип `double`). Затем пользователя просят ввести один из следующих математических символов: \+, \-, \* или /. Программа вычисляет ответ, исходя из этих двух чисел, введенных пользователем, и печатает результаты в консоль. Если пользователь вводит неверный символ, программа не должна ничего печатать.
Пример вывода программы:

```text
Enter a double value: 6.2
Enter a double value: 5
Enter one of the following: +, -, *, or /: *
6.2 * 5 is 31
```

__Ответ:__

[num_3.cpp](num_3.cpp)
___

## Вопрос 4

Дополнительное задание: немного сложнее.

Напишите короткую программу для имитации падения мяча с башни. Для начала у пользователя следует спросить высоту башни в метрах. Предположим, что ускорение свободного падения – обычное (9,8 м/с2), и что мяч не имеет начальной скорости (мяч не движется до старта). Программа должна вывести высоту мяча над землей через 0, 1, 2, 3, 4 и 5 секунд. Мяч не должен уходить под землю (высота 0).

Ваша программа должна включать заголовочный файл с именем `constants.h`, который содержит символьную константу для хранения значения ускорения свободного падения (`9.8`).

Для вычисления высоты мяча через x секунд используйте функцию

Пример вывода:

```text
Enter the height of the tower in meters: 100
At 0 seconds, the ball is at height: 100 meters
At 1 seconds, the ball is at height: 95.1 meters
At 2 seconds, the ball is at height: 80.4 meters
At 3 seconds, the ball is at height: 55.9 meters
At 4 seconds, the ball is at height: 21.6 meters
At 5 seconds, the ball is on the ground.
```

Примечание: в зависимости от высоты башни мяч может не достигнуть земли за 5 секунд – это нормально. Мы улучшим эту программу, как только пройдем циклы.

Примечание: В C++ символ `^` не является символом возведения в степень. Реализуйте формулу, используя умножение вместо возведения в степень.

Примечание: не забудьте использовать литералы типа `double` для чисел с плавающей запятой, например. `2.0`, а не `2`.

__Ответ:__

[num_4](num_4)
___

## Вопрос 5

Найдите 3 проблемы (затрагивающие 4 строки) в следующем коде.

```cpp
#include <cstdint>
#include <iostream>
 
int main()
{
  std::cout << "How old are you?\n";
 
  std::uint8_t age{};
  std::cin >> age;
 
  std::cout << "Allowed to drive a car in Texas [";
 
  if (age >= 16)
    std::cout << "x";
  else
    std::cout << " ";
 
  std::cout << "]\n";
 
  return 0;
}
```

Пример вывода:

```text
How old are you?
6
Allowed to drive a car in Texas [ ]
How old are you?
19
Allowed to drive a car in Texas [x]
```

__Ответ:__

1) Использование типа данных `std::uint8_t` в строке 8. На части устройств этот тип отсутствует и обрабатывается как символ `char`. Следует заменить его на  `std::uint16_t`

2) Использование «магического числа» `16` в строке 13. Следует заменить его константой времени компиляции

3) В строках 14 и 16 символы `x` и пробел стоят в двойных кавычках. Следует заменить эти двойные кавычки на одинарные

# Глава M – Семантика перемещения и умные указатели  

___

## Вопрос 1

Объясните, когда следует использовать указатели следующих типов.

1a) `std::unique_ptr`

1b) `std::shared_ptr`

1c) `std::weak_ptr`

1d) `std::auto_ptr`

__Ответ:__

a) Когда нужен умный указатель на объект, которым больше никто не будет владеть

b) Когда нужен умный указатель на объект, которым будут владеть ещё несколько таких-же указателей

c) Когда нужно получить `std::shared_ptr`, но без влияния на его время жизни

d) Не стоит использовать. Устарел и удалён с C++17

___

## Вопрос 2

Объясните, почему семантика перемещения сосредоточена на r-значениях.

__Ответ:__

Потому что переместить его будет менее затратно переместить, чем копировать. А копировать r-значение нет смысла, ведь оно временное, а значит больше не будет использоваться и уничтожится

___

## Вопрос 3

Что не так со следующим кодом? Обновите программы, чтобы они соответствовали передовой практике.

3а)

```cpp

#include <iostream>
#include <memory> // для std::shared_ptr

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    auto* res{ new Resource{} };
    std::shared_ptr<Resource> ptr1{ res };
    std::shared_ptr<Resource> ptr2{ res };

    return 0;
}

```

3b)

```cpp

#include <iostream>
#include <memory> // для std::shared_ptr

class Something;  // предполагаем, что Something - класс, который может вызвать исключение

int main()
{
    doSomething(std::shared_ptr{ new Something{} }, std::shared_ptr{ new Something{} });

    return 0;
}

```

__Ответ:__

a) Нельзя копировать/перемещать `std::shared_ptr` при помощи исходного указателя. Два `std::shared_ptr` не будут знать друг об друге и два раза очистят `res`. Также правильнее использовать `std::make_shared()`

```cpp

#include <iostream>
#include <memory> // для std::shared_ptr

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    suto ptr1{ std::make_shared<Resource>() };
    auto ptr2{ ptr1 };

    return 0;
}

```

b)  Проброс исключения при перемещени может привести к потери данныч. Стоит использовать `std::make_shared()`

```cpp

#include <iostream>
#include <memory> // для std::shared_ptr

class Something;  // предполагаем, что Something - класс, который может вызвать исключение

int main()
{
    doSomething( std::make_shared<Something>(),  std::make_shared<Something>());

    return 0;
}

```
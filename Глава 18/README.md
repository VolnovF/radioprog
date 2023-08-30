# Глава 18 – Виртуальные функции  

___

## Вопрос 1

Каждая из следующих программ имеет какой-либо недостаток. Просмотрите каждую программу (визуально, а не путем компиляции) и определите, что с ней не так. Предполагается, что результат вывода каждой программы будет "Derived".

1а)

```cpp
#include <iostream>
 
class Base
{
protected:
    int m_value;
 
public:
    Base(int value)
        : m_value{ value }
    {
    }
 
    const char* getName() const { return "Base"; }
};
 
class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }
 
    const char* getName() const { return "Derived"; }
};
 
int main()
{
    Derived d{ 5 };
    Base& b{ d };
    std::cout << b.getName() << '\n';
 
    return 0;
}
```

1b)

```cpp
#include <iostream>
 
class Base
{
protected:
    int m_value;
 
public:
    Base(int value)
        : m_value{ value }
    {
    }
 
    virtual const char* getName() { return "Base"; }
};
 
class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }
 
    virtual const char* getName() const { return "Derived"; }
};
 
int main()
{
    Derived d{ 5 };
    Base& b{ d };
    std::cout << b.getName() << '\n';
 
    return 0;
}
```

1c)

```cpp
#include <iostream>
 
class Base
{
protected:
    int m_value;
 
public:
    Base(int value)
        : m_value{ value }
    {
    }
 
    virtual const char* getName() { return "Base"; }
};
 
class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }
 
    const char* getName() override { return "Derived"; }
};
 
int main()
{
    Derived d{ 5 };
    Base b{ d };
    std::cout << b.getName() << '\n';
 
    return 0;
}
```

1d)

```cpp
#include <iostream>
 
class Base final
{
protected:
    int m_value;
 
public:
    Base(int value)
        : m_value{ value }
    {
    }
 
    virtual const char* getName() { return "Base"; }
};
 
class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }
 
    const char* getName() override { return "Derived"; }
};
 
int main()
{
    Derived d{ 5 };
    Base& b{ d };
    std::cout << b.getName() << '\n';
 
    return 0;
}
```

1e)

```cpp
#include <iostream>
 
class Base
{
protected:
    int m_value;
 
public:
    Base(int value)
        : m_value{ value }
    {
    }
 
    virtual const char* getName() { return "Base"; }
};
 
class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }
 
    virtual const char* getName() = 0;
};
 
const char* Derived::getName()
{
    return "Derived";
}
 
int main()
{
    Derived d{ 5 };
    Base& b{ d };
    std::cout << b.getName() << '\n';
 
    return 0;
}
```

1f)

```cpp
#include <iostream>
 
class Base
{
protected:
    int m_value;
 
public:
    Base(int value)
        : m_value{ value }
    {
    }
 
    virtual const char* getName() { return "Base"; }
};
 
class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }
 
    virtual const char* getName() { return "Derived"; }
};
 
int main()
{
    auto* d{ new Derived(5) };
    Base* b{ d };
    std::cout << b->getName() << '\n';
    delete b;
 
    return 0;
}
```

__Ответ:__

a) Base.getName() не виртуальная. Не получается вызвать b.getName()

b) Derived.getName() не считается переопределением, т.к. Derived.getName() константная, а Base.getName() нет

c) 

d) class Base final, наследование от него невозможно

e) Невозможно создать экземпляр Derived

f) Утечка памяти из-за отсутствия виртуального деструктора в Base
___

## Вопрос 2

2a) Создайте абстрактный класс с именем Shape (фигура). Этот класс должен иметь три функции: чисто виртуальную функцию печати print(), которая принимает и возвращает std::ostream&, перегруженный operator<< и пустой виртуальный деструктор.

2b) Наследуйте от Shape два класса: Triangle (треугольник) и Circle (круг). Triangle в качестве членов должен иметь 3 объекта Point (точка). Circle должен иметь один объект Point для центра и целочисленное значение радиуса. Перегрузите функцию print(), чтобы запустилась следующая программа:

```cpp
int main()
{
    Circle c{ Point{ 1, 2, 3 }, 7 };
    std::cout << c << '\n';
 
    Triangle t{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}};
    std::cout << t << '\n';
 
    return 0;
}
```

Она должно напечатать:

```text
Circle(Point(1, 2, 3), radius 7)
Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9))
```

Вот класс Point, который вы можете использовать:

```cpp
class Point
{
private:
    int m_x{};
    int m_y{};
    int m_z{};
 
public:
    Point(int x, int y, int z)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {
 
    }
 
    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        return out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
    }
};
```

2c) Учитывая приведенные выше классы (Point, Shape, Circle и Triangle), завершите следующую программу:

```cpp
#include <vector>
#include <iostream>
 
int main()
{
    std::vector<Shape*> v{
      new Circle{Point{1, 2, 3}, 7},
      new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
      new Circle{Point{4, 5, 6}, 3}
    };
 
    // здесь выводим каждую фигуру в векторе v в отдельной строке
 
    //                                       напишите ↓ эту функцию
    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; 
 
    // здесь удаляем каждый элемент вектора
 
    return 0;
}
```

Подсказка: вам нужно добавить функцию getRadius() в Circle и преобразовать Shape* в Circle*, чтобы получить к ней доступ.

__Ответ:__

[num_2.cpp](num_2.cpp)

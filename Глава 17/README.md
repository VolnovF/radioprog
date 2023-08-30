# Глава 17 – Наследование  

___

## Вопрос 1

Для каждой из следующих программ определите, что они выводят, или, если они не будут компилироваться, укажите, почему. Это упражнение предназначено для выполнения путем проверки в уме, поэтому не компилируйте код.

a)

```cpp
#include <iostream>
 
class Base
{
public:
    Base()
    {
        std::cout << "Base()\n";
    }
    ~Base()
    {
        std::cout << "~Base()\n";
    }
};
 
class Derived: public Base
{
public:
    Derived()
    {
        std::cout << "Derived()\n";
    }
    ~Derived()
    {
        std::cout << "~Derived()\n";
    }
};
 
int main()
{
    Derived d{};
 
    return 0;
}
```

b)

```cpp
#include <iostream>
 
class Base
{
public:
    Base()
    {
        std::cout << "Base()\n";
    }
    ~Base()
    {
        std::cout << "~Base()\n";
    }
};
 
class Derived: public Base
{
public:
    Derived()
    {
        std::cout << "Derived()\n";
    }
    ~Derived()
    {
        std::cout << "~Derived()\n";
    }
};
 
int main()
{
    Derived d;
    Base b;
 
    return 0;
}
```

Подсказка: локальные переменные уничтожаются в порядке, обратном определению.

c)

```cpp
#include <iostream>
 
class Base
{
private:
    int m_x;
public:
    Base(int x): m_x{ x }
    {
        std::cout << "Base()\n";
    }
    ~Base()
    {
        std::cout << "~Base()\n";
    }
 
    void print() const { std::cout << "Base: " << m_x << '\n';  }
};
 
class Derived: public Base
{
public:
    Derived(int y):  Base{ y }
    {
        std::cout << "Derived()\n";
    }
    ~Derived()
    {
        std::cout << "~Derived()\n";
    }
 
    void print() const { std::cout << "Derived: " << m_x << '\n'; }
};
 
int main()
{
    Derived d{ 5 };
    d.print();
 
    return 0;
}
```

d)

```cpp
#include <iostream>
 
class Base
{
protected:
    int m_x;
public:
    Base(int x): m_x{ x }
    {
        std::cout << "Base()\n";
    }
    ~Base()
    {
        std::cout << "~Base()\n";
    }
 
    void print() const { std::cout << "Base: " << m_x << '\n';  }
};
 
class Derived: public Base
{
public:
    Derived(int y):  Base{ y }
    {
        std::cout << "Derived()\n";
    }
    ~Derived()
    {
        std::cout << "~Derived()\n";
    }
 
    void print() const { std::cout << "Derived: " << m_x << '\n'; }
};
 
int main()
{
    Derived d{ 5 };
    d.print();
 
    return 0;
}
```

e)

```cpp
#include <iostream>
 
class Base
{
protected:
    int m_x;
public:
    Base(int x): m_x{ x }
    {
        std::cout << "Base()\n";
    }
    ~Base()
    {
        std::cout << "~Base()\n";
    }
 
    void print() const { std::cout << "Base: " << m_x << '\n';  }
};
 
class Derived: public Base
{
public:
    Derived(int y):  Base{ y }
    {
        std::cout << "Derived()\n";
    }
    ~Derived()
    {
        std::cout << "~Derived()\n";
    }
 
    void print() { std::cout << "Derived: " << m_x << '\n'; }
};
 
class D2 : public Derived
{
public:
    D2(int z): Derived{ z }
    {
        std::cout << "D2()\n";
    }
    ~D2()
    {
        std::cout << "~D2()\n";
    }
 
        // обратите внимание: здесь нет функции print()
};
 
int main()
{
    D2 d{ 5 };
    d.print();
 
    return 0;
}
```

__Ответ:__

a) 

```text
Base()
Derived()
~Derived()
~Base()
```

b) 

```text
Base()
Derived()
Base()
~Base()
~Derived()
~Base()
```

c) Derived.print() не имеет доступа к Base.m_x

d)

```text
Base()
Derived()
Derived: 5
~Derived()
~Base()
```

e)

```text
Base()
Derived()
D2()
Derived: 5
~D2()
~Derived()
~Base()
```
___

## Вопрос 2

a) Напишите классы Apple и Banana, производные от общего класса Fruit. У Fruit должно быть два члена: название и цвет.

Должна запуститься следующая программа:

```cpp
int main()
{
    Apple a{ "red" };
    Banana b{};
 
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    
    return 0;
}
```

И выдать следующий результат:

```text
My apple is red.
My banana is yellow.
```

b) Добавьте в предыдущую программу новый класс GrannySmith (такой сорт яблок), унаследованный от Apple.

Должна запуститься следующая программа:

```cpp
int main()
{
    Apple a{ "red" };
    Banana b;
    GrannySmith c;
 
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    
    return 0;
}
```

И выдать следующий результат:

```text
My apple is red.
My banana is yellow.
My granny smith apple is green.
```

__Ответ:__

[num_2.cpp](num_2.cpp)
___

## Вопрос 3

Время испытания! Следующий вопрос теста более сложный и длинный. Мы собираемся написать простую игру, в которой вы сражаетесь с монстрами. Цель игры – собрать как можно больше золота перед смертью или достижением 20 уровня.

Наша программа будет состоять из 3 классов: класса Creature (существо), класса Player (игрок) и класса Monster (монстр). И Player, и Monster наследуются от Creature.

a) Сначала создайте класс Creature. Существа Creature имеют 5 атрибутов: имя (std::string), символ (char), количество здоровья (int), количество урона, которое они наносят за атаку (int), и количество золота, которое они несут (int). Реализуйте их как члены класса. Напишите полный набор методов-геттеров (функций получения для каждого члена). Добавьте еще три функции:

    void reduceHealth(int) уменьшает здоровье Creature на целочисленное значение;
    
    bool isDead() возвращает true, когда здоровье Creature равно или меньше нуля;

    void addGold(int) добавляет Creature золото.

Должна запуститься следующая программа:

```cpp
#include <iostream>
#include <string>
 
int main()
{
    Creature o{ "orc", 'o', 4, 2, 10 };
    o.addGold(5);
    o.reduceHealth(1);
    std::cout << "The " << o.getName() << " has " << o.getHealth()
              << " health and is carrying " << o.getGold() << " gold.\n";
 
    return 0;
}
```

И выдать следующий результат:

```text
The orc has 3 health and is carrying 15 gold.
```

b) Теперь мы собираемся создать класс Player. Класс Player наследуется от Creature. У игрока есть одна дополнительная переменная-член, уровень игрока, который начинается с 1. У игрока есть имя собственное (введенное пользователем), он использует символ '@', имеет 10 единиц здоровья, для начала наносит 1 очко повреждения и не имеет золота. Напишите функцию с именем levelUp(), которая увеличивает уровень и урон игрока на 1. Также напишите функцию-геттер для получения значения уровня. Наконец, напишите функцию с именем hasWon(), которая возвращает true, если игрок достиг 20-го уровня.

Напишите новую функцию main(), которая запрашивает у пользователя имя и выводит следующий результат:

```text
Enter your name: Alex
Welcome, Alex.
You have 10 health and are carrying 0 gold.
```

c) Далее идет класс Monster. Monster также наследуется от Creature. У монстров нет ненаследуемых переменных-членов.

Сначала напишите пустой класс Monster, наследованный от Creature, а затем внутри класса Monster добавьте перечисление с именем Type, которое содержит перечислители для трех монстров, которые будут у нас в этой игре: DRAGON (дракон), ORC (орк) и SLIME (слизь) (вам также понадобится перечислитель max_types, так как он может быть немного полезен).

d) У каждого типа монстра будет свое имя, символ, начальное здоровье, золото и урон.

Следующим шагом будет написание конструктора Monster, чтобы мы могли создавать монстров. Конструктор Monster в качестве параметра должен принимать перечисление Type, а затем создавать объект Monster с соответствующими характеристиками для этого вида монстров.

Есть несколько способов реализовать это (что-то лучше, что-то хуже). Однако в этом случае, поскольку все наши атрибуты монстров предопределены (не случайны), мы будем использовать таблицу поиска. Таблица поиска – это массив, содержащий все предопределенные атрибуты. Мы можем использовать таблицу поиска для поиска атрибутов заданного монстра, когда это необходимо.

Так как же реализовать эту таблицу поиска? Это не трудно. Нам просто нужен массив, содержащий элемент для каждого типа монстра. Каждый элемент массива будет содержать объект существа Creature, который содержит все предопределенные значения атрибутов для этого типа монстра. Мы помещаем этот массив внутри статической функции-члена Monster, чтобы можно было получить объект Creature по умолчанию для заданного Monster::Type.

Определение таблицы поиска будет следующим:

```cpp
// как закрытый член класса Monster
static const Creature& getDefaultCreature(Type type)
{
  static std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
    { { "dragon", 'D', 20, 4, 100 },
      { "orc", 'o', 4, 2, 25 },
      { "slime", 's', 1, 1, 10 } }
  };
 
  return monsterData.at(static_cast<std::size_t>(type));
}
```

Теперь мы можем вызывать эту функцию для поиска любых нужных нам значений! Например, чтобы получить количество золота дракона, мы можем вызвать getDefaultCreature(Type::dragon).getGold().

Используйте эту функцию и делегирующие конструкторы для реализации своего конструктора Monster.

Следующая программа должна компилироваться:

```cpp
#include <iostream>
#include <string>
 
int main()
{
    Monster m{ Monster::Type::orc };
    std::cout << "A " << m.getName() 
              << " (" << m.getSymbol() << ") was created.\n";
 
    return 0;
}
```

и напечатать:

```text
A orc (o) was created.
```

e) Наконец, добавьте к Monster статическую функцию с именем getRandomMonster(). Эта функция должна выбрать случайное число от 0 до max_types-1 и вернуть монстра (по значению) с этим типом (вам нужно преобразовать int с помощью static_cast в Type, чтобы передать его конструктору Monster).

Урок «9.5 – Генерирование случайных чисел» содержит код, который можно использовать для выбора случайного числа.

Должна запуститься следующая функция main:

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()
 
int main()
{
    // устанавливаем начальное значение в значение системных часов
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
    // отбрасываем первый результат
    std::rand(); 
 
    for (int i{ 0 }; i < 10; ++i)
    {
        Monster m{ Monster::getRandomMonster() };
        std::cout << "A " << m.getName()
                  << " (" << m.getSymbol() << ") was created.\n";
    }
 
    return 0;
}
```

Результаты этой программы должны быть рандомизированы.

f) Наконец-то мы готовы написать нашу игровую логику!

Вот правила игры:

    Игрок в какой-либо момент сталкивается только с одним случайно сгенерированным монстром.
    Для каждого монстра у игрока есть два выбора: (R)un (бежать) или (F)ight (сражаться).
    Если игрок решает бежать, у него есть 50%-ый шанс сбежать.
    Если игрок сбегает, он переходит к следующему столкновению без каких-либо негативных последствий.
    Если игроку не удается сбежать, монстр получает бесплатную атаку, и игрок выбирает свое следующее действие.
    Если игрок решает сражаться, он атакует первым. Здоровье монстра уменьшается на величину урона игрока.
    Если монстр умирает, игрок забирает всё золото, которое несет монстр. Игрок также повышает уровень, увеличивая значения своих уровня и урона на 1.
    Если монстр не умирает, он атакует игрока в ответ. Здоровье игрока уменьшается на величину урона монстра.
    Игра заканчивается, когда игрок умирает (поражение) или достигает 20 уровня (победа).
    Если игрок умирает, игра должна сообщить ему, на каком он уровне и сколько у него золота.
    Если игрок выигрывает, игра должна сообщить ему, что он выиграл, и сколько у него золота.

Вот пример игровой сессии:

```text
Enter your name: Alex
Welcome, Alex
You have encountered a slime (s).
(R)un or (F)ight: f
You hit the slime for 1 damage.
You killed the slime.
You are now level 2.
You found 10 gold.
You have encountered a dragon (D).
(R)un or (F)ight: r
You failed to flee.
The dragon hit you for 4 damage.
(R)un or (F)ight: r
You successfully fled.
You have encountered a orc (o).
(R)un or (F)ight: f
You hit the orc for 2 damage.
The orc hit you for 2 damage.
(R)un or (F)ight: f
You hit the orc for 2 damage.
You killed the orc.
You are now level 3.
You found 25 gold.
You have encountered a dragon (D).
(R)un or (F)ight: r
You failed to flee.
The dragon hit you for 4 damage.
You died at level 3 and with 35 gold.
Too bad you can't take it with you!
```

Подсказка: создайте 4 функции:

    функция main() должна обрабатывать настройку игры (создание игрока) и основной цикл игры;
    fightMonster() обрабатывает битву между игроком и одним монстром, в том числе спрашивает игрока, что он хочет сделать, обрабатывает случаи побега или драки;
    attackMonster() обрабатывает атаку игрока на монстра, включая повышение уровня;
    attackPlayer() обрабатывает атаку монстра на игрока.

__Ответ:__

[num_3.cpp](num_3.cpp)

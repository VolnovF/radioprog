# Глава 12 – Основы объектно-ориентированного программирования

___

## Вопрос 1

a) Напишите класс с именем Point2d. Point2d должен содержать две переменные-члены типа double: m_x и m_y, обе по умолчанию равны 0.0. Предоставьте конструктор и функцию печати.

Должна запуститься следующая программа:

```cpp
#include <iostream>
 
int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
 
    return 0;
}
```

Она должна напечатать:

```text
Point2d(0, 0)
Point2d(3, 4)
```

b) Теперь добавьте функцию-член с именем distanceTo, которая принимает другой объект Point2d в качестве параметра и вычисляет расстояние между ними. Для двух точек (x1, y1) и (x2, y2) расстояние между ними можно рассчитать как std::sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)). Функция std::sqrt находится в заголовке cmath.

Должна запуститься следующая программа:

```cpp
#include <iostream>
 
int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: "
              << first.distanceTo(second) << '\n';
 
    return 0;
}
```

Она должна напечатать:

```text
Point2d(0, 0)
Point2d(3, 4)
Distance between two points: 5
```

c) Измените функцию distanceTo с функции-члена на функцию, не являющуюся членом, которая принимает в качестве параметров два объекта Point. Также переименуйте ее в distanceFrom.

Должна запуститься следующая программа:

```cpp
#include <iostream>
 
int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: "
              << distanceFrom(first, second) << '\n';
 
    return 0;
}
```

Она должна напечатать:

```text
Point2d(0, 0)
Point2d(3, 4)
Distance between two points: 5
```

__Ответ:__

[num_1.cpp](num_1.cpp)
___

## Вопрос 2

Напишите деструктор для данного класса:

```cpp
#include <iostream>
 
class HelloWorld
{
private:
    char *m_data{};
 
public:
    HelloWorld()
    {
        m_data = new char[14];
        const char *init{ "Hello, World!" };
        for (int i = 0; i < 14; ++i)
            m_data[i] = init[i];
    }
 
    ~HelloWorld()
    {
        // замените этот комментарий своей реализацией деструктора
    }
 
    void print() const
    {
        std::cout << m_data << '\n';
    }
 
};
 
int main()
{
    HelloWorld hello{};
    hello.print();
 
    return 0;
}
```

__Ответ:__

[num_2.cpp](num_2.cpp)
___

## Вопрос 3

Давайте создадим генератор случайных монстров. Это должно быть весело.

a) Во-первых, давайте создадим перечисление типов монстров с именем MonsterType. Включите следующие типы монстров: Дракон (Dragon), Гоблин (Goblin), Огр (Ogre), Орк (Orc), Скелет (Skeleton), Тролль (Troll), Вампир (Vampire) и Зомби (Zombie). Добавьте дополнительный перечислитель max_monster_types, чтобы мы могли подсчитать количество перечислителей.

b) Теперь давайте создадим класс Monster. У нашего монстра будет 4 атрибута (переменных-члена): тип (MonsterType), имя (std::string), рев (std::string) и количество очков жизни (int). Создайте класс Monster с этими 4 переменными-членами.

c) перечисление MonsterType специфично для класса Monster, поэтому переместите это перечисление внутрь класса как открытое объявление. Когда перечисление находится внутри класса, слово "Monster" в "MonsterType" будет избыточным, его можно удалить.

d) Создайте конструктор, который позволит вам инициализировать все переменные-члены.

Должна скомпилироваться следующая программа:

```cpp
int main()
{
    Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };
 
    return 0;
}
```

e) Теперь мы хотим иметь возможность распечатать информацию о нашем монстре, чтобы можно было проверить ее правильность. Для этого нам нужно написать функцию, которая преобразует Monster::Type в строку. Напишите эту функцию (с именем getTypeString()), а также функцию-член print().

Следующая программа должна компилироваться:

```cpp
int main()
{
    Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };
    skeleton.print();
 
    return 0;
}
```

и печатать:

```text
Bones the skeleton has 4 hit points and says *rattle*
```

f) Теперь мы можем создать генератор случайных монстров. Давайте посмотрим, как будет работать наш класс MonsterGenerator. В идеале мы попросим его дать нам монстра, и он создаст для нас случайного монстра. Нам не нужно более одного MonsterGenerator. Это хороший кандидат для статического класса (в котором все функции статические). Создайте статический класс MonsterGenerator. Создайте статическую функцию с именем generateMonster(). Она должна возвращать монстра. А пока сделайте так, чтобы она возвращала анонимный объект Monster(Monster::Type::skeleton, "Bones", "*rattle*", 4).

Следующая программа должна компилироваться:

```cpp
int main()
{
    Monster m{ MonsterGenerator::generateMonster() };
    m.print();
 
    return 0;
}
```

и печатать:

```text
Bones the skeleton has 4 hit points and says *rattle*
```

g) Теперь MonsterGenerator должен генерировать случайные атрибуты. Для этого нам понадобится следующая удобная функция:

```cpp
// Генерируем случайное число от min до max (включительно)
// Предполагается, что srand() уже был вызван
int getRandomNumber(int min, int max)
{
    // static используется для повышения эффективности,
    // поэтому мы вычисляем это значение только один раз
    static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
    // равномерно распределяем случайные числа по нашему диапазону
    return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
}
```

Однако, поскольку MonsterGenerator напрямую полагается на эту функцию, давайте поместим ее в класс как статическую функцию.

h) Теперь отредактируйте функцию generateMonster(), чтобы сгенерировать случайный Monster::Type (от 0 до Monster::Type::max_monster_types-1) и случайное количество очков жизни (от 1 до 100). Это должно быть довольно просто. Как только вы это сделаете, определите внутри этой функции два статических фиксированных массива размером 6 (с именами s_names и s_roars) и инициализируйте их: 6 – именами, и 6 – звуками на ваш выбор. Выберите случайное имя из этих массивов.

Следующая программа должна компилироваться:

```cpp
#include <ctime>   // для time()
#include <cstdlib> // для rand() и srand()
 
int main()
{
    // устанавливаем начальное значение в значение системных часов
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
    std::rand(); // При использовании Visual Studio отбрасываем первое случайное значение
 
    Monster m{ MonsterGenerator::generateMonster() };
    m.print();
 
    return 0;
}
```

i) Почему мы объявили переменные s_names и s_roars статическими?

__Ответ:__

[num_3.cpp](num_3.cpp)

i) Потому-что для нескольких генераторов их достаточно инициализировать одни раз.
___

## Вопрос 4

Хорошо, время снова вернуться к картам. Это будет испытание. Давайте перепишем игру блэкджек, которую мы написали в предыдущей главе, используя классы! Вот полный код без классов:

```cpp
#include <algorithm>
#include <array>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>
 
enum class CardSuit
{
  SUIT_CLUB,
  SUIT_DIAMOND,
  SUIT_HEART,
  SUIT_SPADE,
 
  MAX_SUITS
};
 
enum class CardRank
{
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_9,
  RANK_10,
  RANK_JACK,
  RANK_QUEEN,
  RANK_KING,
  RANK_ACE,
 
  MAX_RANKS
};
 
struct Card
{
  CardRank rank{};
  CardSuit suit{};
};
 
struct Player
{
  int score{};
};
 
using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;
 
// Максимальный счет до проигрыша.
constexpr int maximumScore{ 21 };
 
// Минимальный счет, который должен иметь дилер.
constexpr int minimumDealerScore{ 17 };
 
void printCard(const Card& card)
{
  switch (card.rank)
  {
  case CardRank::RANK_2:
    std::cout << '2';
    break;
  case CardRank::RANK_3:
    std::cout << '3';
    break;
  case CardRank::RANK_4:
    std::cout << '4';
    break;
  case CardRank::RANK_5:
    std::cout << '5';
    break;
  case CardRank::RANK_6:
    std::cout << '6';
    break;
  case CardRank::RANK_7:
    std::cout << '7';
    break;
  case CardRank::RANK_8:
    std::cout << '8';
    break;
  case CardRank::RANK_9:
    std::cout << '9';
    break;
  case CardRank::RANK_10:
    std::cout << 'T';
    break;
  case CardRank::RANK_JACK:
    std::cout << 'J';
    break;
  case CardRank::RANK_QUEEN:
    std::cout << 'Q';
    break;
  case CardRank::RANK_KING:
    std::cout << 'K';
    break;
  case CardRank::RANK_ACE:
    std::cout << 'A';
    break;
  default:
    std::cout << '?';
    break;
  }
 
  switch (card.suit)
  {
  case CardSuit::SUIT_CLUB:
    std::cout << 'C';
    break;
  case CardSuit::SUIT_DIAMOND:
    std::cout << 'D';
    break;
  case CardSuit::SUIT_HEART:
    std::cout << 'H';
    break;
  case CardSuit::SUIT_SPADE:
    std::cout << 'S';
    break;
  default:
    std::cout << '?';
    break;
  }
}
 
int getCardValue(const Card& card)
{
  if (card.rank <= CardRank::RANK_10)
  {
    return (static_cast<int>(card.rank) + 2);
  }
 
  switch (card.rank)
  {
  case CardRank::RANK_JACK:
  case CardRank::RANK_QUEEN:
  case CardRank::RANK_KING:
    return 10;
  case CardRank::RANK_ACE:
    return 11;
  default:
    assert(false && "should never happen");
    return 0;
  }
}
 
void printDeck(const deck_type& deck)
{
  for (const auto& card : deck)
  {
    printCard(card);
    std::cout << ' ';
  }
 
  std::cout << '\n';
}
 
deck_type createDeck()
{
  deck_type deck{};
 
  index_type card{ 0 };
 
  auto suits{ static_cast<index_type>(CardSuit::MAX_SUITS) };
  auto ranks{ static_cast<index_type>(CardRank::MAX_RANKS) };
 
  for (index_type suit{ 0 }; suit < suits; ++suit)
  {
    for (index_type rank{ 0 }; rank < ranks; ++rank)
    {
      deck[card].suit = static_cast<CardSuit>(suit);
      deck[card].rank = static_cast<CardRank>(rank);
      ++card;
    }
  }
 
  return deck;
}
 
void shuffleDeck(deck_type& deck)
{
  static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
 
  std::shuffle(deck.begin(), deck.end(), mt);
}
 
bool playerWantsHit()
{
  while (true)
  {
    std::cout << "(h) to hit, or (s) to stand: ";
 
    char ch{};
    std::cin >> ch;
 
    switch (ch)
    {
    case 'h':
      return true;
    case 's':
      return false;
    }
  }
}
 
// Возвращает true, если у игрока «перебор». В противном случае - false.
bool playerTurn(const deck_type& deck, index_type& nextCardIndex, Player& player)
{
  while (true)
  {
    std::cout << "You have: " << player.score << '\n';
 
    if (player.score > maximumScore)
    {
      return true;
    }
    else
    {
      if (playerWantsHit())
      {
        player.score += getCardValue(deck[nextCardIndex++]);
      }
      else
      {
        // У игрока нет перебора
        return false;
      }
    }
  }
}
 
// Возвращает true, если у дилера «перебор». В противном случае - false.
bool dealerTurn(const deck_type& deck, index_type& nextCardIndex, Player& dealer)
{
  while (dealer.score < minimumDealerScore)
  {
    dealer.score += getCardValue(deck[nextCardIndex++]);
  }
 
  return (dealer.score > maximumScore);
}
 
bool playBlackjack(const deck_type& deck)
{
  index_type nextCardIndex{ 0 };
 
  Player dealer{ getCardValue(deck[nextCardIndex++]) };
 
  std::cout << "The dealer is showing: " << dealer.score << '\n';
 
  Player player{ getCardValue(deck[nextCardIndex]) + getCardValue(deck[nextCardIndex + 1]) };
  nextCardIndex += 2;
 
  if (playerTurn(deck, nextCardIndex, player))
  {
    return false;
  }
 
  if (dealerTurn(deck, nextCardIndex, dealer))
  {
    return true;
  }
 
  return (player.score > dealer.score);
}
 
int main()
{
  auto deck{ createDeck() };
 
  shuffleDeck(deck);
 
  if (playBlackjack(deck))
  {
    std::cout << "You win!\n";
  }
  else
  {
    std::cout << "You lose!\n";
  }
 
  return 0;
}
```

Ух ты! С чего нам вообще начать? Не волнуйтесь, мы можем это сделать, но нам понадобится стратегия. Эта программа для блэкджека состоит из четырех частей: логика работы с картами, логика работы с колодой карт, логика раздачи карт из колоды и логика игры. Наша стратегия будет заключаться в том, чтобы поработать над каждой из этих частей отдельно, тестируя каждую часть с помощью небольшой тестовой программы. Таким образом, вместо того, чтобы пытаться переписать всю программу за раз, мы можем сделать это в 4 тестируемых частях.

Начните с копирования исходной программы в вашу среду IDE, а затем закомментируйте всё, кроме строк #include.

a) Начнем с того, что сделаем Card классом, а не структурой. Хорошей новостью является то, что класс Card очень похож на класс Monster из предыдущего вопроса теста. Во-первых, создайте закрытые члены, которые будут содержать ранг и масть (назовите их соответственно m_rank и m_suit). Во-вторых, создайте открытый конструктор для класса Card, чтобы мы могли инициализировать объекты Card. В-третьих, сделайте объекты класса создаваемыми по умолчанию, либо добавив конструктор по умолчанию, либо добавив аргументы по умолчанию в текущий конструктор. Наконец, переместите функции printCard() и getCardValue() внутрь класса как открытые члены (не забудьте сделать их константными!).

Должна компилироваться следующая тестовая программа:

```cpp
#include <iostream>
 
// ...
 
int main()
{
  const Card cardQueenHearts{ CardRank::RANK_QUEEN, CardSuit::SUIT_HEART };
  cardQueenHearts.print();
  std::cout << " has the value " << cardQueenHearts.value() << '\n';
 
  return 0;
}
```

b) Хорошо, теперь поработаем над классом Deck. Колода должна содержать 52 карты, поэтому используйте закрытый член std::array, чтобы создать фиксированный массив из 52 карт с именем m_deck. Во-вторых, создайте конструктор, который не принимает параметров и инициализирует m_deck по одному экземпляру каждой карты (измените код из исходной функции createDeck()). В-третьих, переместите printDeck в класс Deck как открытый член. В-четвертых, переместите shuffleDeck в класс как открытый член.

Самая сложная часть этого шага – инициализация колоды с использованием модифицированного кода из исходной функции createDeck(). Следующая подсказка показывает, как это сделать.

Должна компилироваться следующая тестовая программа:

```cpp
// ...
 
int main()
{
  Deck deck{};
  deck.print();
  deck.shuffle();
  deck.print();
 
  return 0;
}
```

c) Теперь нам нужен способ отслеживать, какая карта будет сдана следующей (в исходной программе для этого был nextCardIndex). Сначала добавьте член с именем m_cardIndex в Deck и инициализируйте его значением 0. Создайте открытую функцию-член с именем dealCard(), которая должна возвращать константную ссылку на текущую карту и продвигать m_cardIndex к следующему индексу. shuffle() также следует обновить, чтобы сбрасывать m_cardIndex (поскольку, если вы перемешаете колоду, вы начнете раздачу снова с верха колоды).

Должна скомпилироваться следующая тестовая программа:

```cpp
// ...
 
int main()
{
  Deck deck{};
  
  deck.shuffle();
  deck.print();
  
  std::cout << "The first card has value: " << deck.dealCard().value() << '\n';
  std::cout << "The second card has value: " << deck.dealCard().value() << '\n';
 
  return 0;
}
```

d) Теперь переходим к классу игрока Player. Поскольку playerTurn и dealerTurn очень отличаются друг от друга, мы оставим их как функции, не являющиеся членами. Сделайте Player классом и добавьте функцию-член drawCard, которая раздает игроку одну карту из колоды, увеличивая счет игрока. Нам также понадобится функция-член для доступа к счету игрока. Для удобства добавьте функцию-член с именем isBust(), которая возвращает значение true, если счет игрока превышает максимальное значение (maximumScore).

Должен компилироваться следующий код:

```cpp
// ...
 
int main()
{
  Deck deck{};
  
  deck.shuffle();
  deck.print();
  
  Player player{};
  Player dealer{};
 
  player.drawCard(deck);
  dealer.drawCard(deck);
 
  std::cout << "The player drew a card with value: " << player.score() << '\n';
  std::cout << "The dealer drew a card with value: " << dealer.score() << '\n';
 
  return 0;
}
```

e) Почти готово! Теперь просто исправьте оставшуюся программу, чтобы использовать классы, которые вы написали выше. Поскольку большинство функций перенесено в классы, вы можете отказаться от них.

__Ответ:__

[num_4.cpp](num_4.cpp)

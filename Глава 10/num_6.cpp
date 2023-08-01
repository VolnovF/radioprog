#include <iostream>
#include <array>
#include <ctime>
#include <random>
#include <algorithm>

// a)
enum CardRank
{
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace,
    maxRank
};

enum CardSuit
{
    clubs,
    diamonds,
    hearts,
    spades,
    maxSuit
};

// b)
struct Card
{
    CardRank rank{};
    CardSuit suit{};
};

// c)
void printCard(const Card& card)
{
    switch (static_cast<int>(card.rank))
    {
        case two:    std::cout << '2';   break;
        case three:  std::cout << '3';   break;
        case four:   std::cout << '4';   break;
        case five:   std::cout << '5';   break;
        case six:    std::cout << '6';   break;
        case seven:  std::cout << '7';   break;
        case eight:  std::cout << '8';   break;
        case nine:   std::cout << '9';   break;
        case ten:    std::cout << 'T';   break;
        case jack:   std::cout << 'J';   break;
        case queen:  std::cout << 'Q';   break;
        case king:   std::cout << 'K';   break;
        case ace:    std::cout << 'A';   break;
    };
    switch (static_cast<int>(card.suit))
    {
        case clubs:     std::cout << 'C';   break;
        case diamonds:  std::cout << 'D';   break;
        case hearts:    std::cout << 'H';   break;
        case spades:    std::cout << 'S';   break;
    };
}

// d)
using deck_t = std::array<Card, 52>;

deck_t createDeck()
{
    deck_t deck{};
    for (size_t i{ 0 }; i < deck.size(); i++)
    {
        deck[i].rank = static_cast<CardRank>(i % maxRank);
        deck[i].suit = static_cast<CardSuit>((i / maxRank) % maxSuit);
    }
    return deck;
}

// e)
void printDeck(const deck_t& deck)
{
    for (size_t i{ 0 }; i < deck.size(); i++)
    {
        printCard(deck[i]);
        std::cout << ' ';
    };
}

// f)
void shuffleDeck(deck_t& deck)
{
    static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(deck.begin(), deck.end(), mersenne);
}

// g)
int getCardValue(const Card& card)
{
    switch (static_cast<int>(card.rank))
    {
        case two: 
        case three:
        case four:
        case five:
        case six:
        case seven:
        case eight:
        case nine:
            return (static_cast<int>(card.rank) + 2);
        case ten:
        case jack:
        case queen:
        case king:
            return 10;
        case ace:
            return 11;
        default:
            return 0;
    };
}

int main()
{
    deck_t deck{ createDeck() };
    shuffleDeck(deck);
    printDeck(deck);
    std::cout << '\n' << getCardValue(deck[0]) << '\n';
    
    return 0;
}
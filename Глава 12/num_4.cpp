#include <iostream>
#include <array>
#include <ctime>
#include <random>
#include <algorithm>

constexpr int maxScore{ 21 };
constexpr int minDealerScore{ 17 };

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

struct Card
{
private:
    CardRank m_rank{};
    CardSuit m_suit{};
public:
    Card(CardRank rank = two, CardSuit suit = clubs): m_rank{ rank }, m_suit{ suit }
    {
    }
    void print() const
    {
        switch (m_rank)
        {
            case two:
                std::cout << '2';
                break;
            case three:
                std::cout << '3';
                break;
            case four:
                std::cout << '4';
                break;
            case five:
                std::cout << '5';
                break;
            case six:
                std::cout << '6';
                break;
            case seven:
                std::cout << '7';
                break;
            case eight:
                std::cout << '8';
                break;
            case nine:
                std::cout << '9';
                break;
            case ten:
                std::cout << 'T';
                break;
            case jack:
                std::cout << 'J';
                break;
            case queen:
                std::cout << 'Q';
                break;
            case king:
                std::cout << 'K';
                break;
            case ace:
                std::cout << 'A';
                break;
            default:
                std::cout << '?';
                break;
        }
    
        switch (m_suit)
        {   
            case clubs:
                std::cout << 'C';
                break;
            case diamonds:
                std::cout << 'D';
                break;
            case hearts:
                std::cout << 'H';
                break;
            case spades:
                std::cout << 'S';
                break;
            default:
                std::cout << '?';
                break;
        }
    }
    int getValue() const
    {
        switch (static_cast<int>(m_rank))
        {
            case two: 
            case three:
            case four:
            case five:
            case six:
            case seven:
            case eight:
            case nine:
                return (static_cast<int>(m_rank) + 2);
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
};

class Deck
{
private:
    std::array<Card, 52> m_deck;
    size_t m_nextCard;
public:
    Deck()
    {
        m_nextCard = 0;
        for (size_t i{ 0 }; i < m_deck.size(); i++)
        {
            m_deck[i] =
            {
                static_cast<CardRank>(i % maxRank),
                static_cast<CardSuit>((i / maxRank) % maxSuit)
            };
        };
    }
    void shuffle()
    {
        static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
        std::shuffle(m_deck.begin(), m_deck.end(), mersenne);
        m_nextCard = 0;
    }
    void print()
    {
        for (size_t i{ 0 }; i < m_deck.size(); i++)
        {
            m_deck[i].print();
            std::cout << ' ';
        };
    }
    const Card& dealCard()
    {
        ++m_nextCard;
        return m_deck[m_nextCard - 1];
    }
};

class Player
{
private:
    int m_score;
public:
    void drawCard(Deck& deck)
    {
        m_score += deck.dealCard().getValue();
    }
    int score() const
    {
        return m_score;
    }
    bool isBust() const
    {
        return (m_score > maxScore);
    }
};

void printDealerScore(const Player& dealer)
{
    std::cout << "Dealer has " << dealer.score() << " points\n";
}
void printPlayerScore(const Player& player)
{
    std::cout << "You have " << player.score() << " points\n";
}

void playerMakeMove(Deck& deck, Player& player)
{
    bool playerChoice{};
    while (true)
    {
        printPlayerScore(player);

        if (player.score() > maxScore)
        {
            return;
        };
        std::cout << "\nHit or stand? (1/0): ";
        std::cin >> playerChoice;
        switch (playerChoice)
        {
            case false:
                return;
            case true:
                player.drawCard(deck);
                break;
        }
    };
}

void dealerMakeMove(Deck& deck, Player& dealer)
{
    while (dealer.score() < minDealerScore)
    {
        std::cout << "\nDealer takes a card\n";
        dealer.drawCard(deck);
        printDealerScore(dealer);
    }
}

bool playBlackjack(Deck& deck)
{
    Player player{};
    Player dealer{};
    
    dealer.drawCard(deck);
    printDealerScore(dealer);

    player.drawCard(deck);
    player.drawCard(deck);
    
    playerMakeMove(deck, player);
    if (player.score() == maxScore && dealer.score() < 10)
    {
        return true;
    }
    else if (player.score() > maxScore)
    {
        return false;
    };

    dealerMakeMove(deck, dealer);
    if ((dealer.score() > maxScore) || (player.score() > dealer.score()))
    {
        return true;
    }
    else
    {
        return false;
    };
}


int main()
{
    Deck deck{};
    deck.shuffle();
    if (playBlackjack(deck))
    {
        std::cout << "\nYou win\n";
    }
    else
    {
        std::cout << "\nYou lose\n";
    }
    return 0;
}
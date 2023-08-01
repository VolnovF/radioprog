#include <iostream>
#include <array>
#include <ctime>
#include <random>
#include <algorithm>

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
    CardRank rank{};
    CardSuit suit{};
};

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

void shuffleDeck(deck_t& deck)
{
    static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(deck.begin(), deck.end(), mersenne);
}

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

using score_t = int;

void giveNextCard(score_t& score, const deck_t& deck, size_t& nextCard)
{
    score += getCardValue(deck[nextCard]);
    ++nextCard;
}

void printDealerScore(const score_t& dealerScore)
{
    std::cout << "Dealer has " << dealerScore << " points\n";
}
void printPlayerScore(const score_t& playerScore)
{
    std::cout << "You have " << playerScore << " points\n";
}

constexpr score_t maxScore{ 21 };
void playerMakeMove(score_t& playerScore, const deck_t& deck, size_t& nextCard)
{
    bool playerChoice{};
    while (true)
    {
        printPlayerScore(playerScore);

        if (playerScore > maxScore)
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
                giveNextCard(playerScore, deck, nextCard);
                break;
        }
    };
}

constexpr score_t dealerMinScore{ 17 };
void dealerMakeMove(score_t& dealerScore, const deck_t& deck, size_t& nextCard)
{
    while (dealerScore < dealerMinScore)
    {
        std::cout << "\nDealer takes a card\n";
        giveNextCard(dealerScore, deck, nextCard);
        printDealerScore(dealerScore);
    }
}

bool playBlackjack(deck_t& deck)
{
    size_t nextCard{0};
    score_t dealer{0}, player{0};
    
    giveNextCard(dealer, deck, nextCard);
    printDealerScore(dealer);

    giveNextCard(player, deck, nextCard);
    giveNextCard(player, deck, nextCard);
    
    playerMakeMove(player, deck, nextCard);
    if (player == maxScore && dealer < 10)
    {
        return true;
    }
    else if (player > maxScore)
    {
        return false;
    };

    dealerMakeMove(dealer, deck, nextCard);
    if (dealer > maxScore || player > dealer)
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
    deck_t deck{ createDeck() };
    shuffleDeck(deck);
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
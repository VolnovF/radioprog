#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <cstdlib>
#include <ctime>
 
class Creature
{
protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;
public:
    Creature(std::string_view name, char symbol, int health, int damage, int gold):
        m_name{ name },
        m_symbol{ symbol },
        m_health{ health },
        m_damage{ damage },
        m_gold{ gold }
    {
    }
 
    const std::string& getName() const
        { return m_name; }
    char getSymbol() const
        { return m_symbol; }
    int getHealth() const
        { return m_health; }
    int getDamage() const
        { return m_damage; }
    int getGold() const
        { return m_gold; }
 
    void reduceHealth(int health)
        { m_health -= health; }
    bool isDead() const
        { return m_health <= 0; }
    void addGold(int gold)
        { m_gold += gold; }
};

class Player : public Creature
{
private:
    int m_level{ 1 };
public:
    Player(std::string_view name)
        : Creature{ name, '@', 10, 1, 0 }
    {
    }
 
    void levelUp()
    {
        ++m_level;
        ++m_damage;
    }
    int getLevel() const
        { return m_level; }
    bool hasWon() const
        { return m_level >= 20; }
};

int getRandomNumber(int min, int max)
{
    static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
       return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
}

class Monster : public Creature
{
public:
    enum class Type
    {
        dragon,
        orc,
        slime,
        max_types
    };
private:
    static const Creature& getDefaultCreature(Type type)
    {
        static std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData
        {
        { 
            { "dragon", 'D', 20, 4, 100 },
            { "orc", 'o', 4, 2, 25 },
            { "slime", 's', 1, 1, 10 }
        }
        };
        return monsterData.at(static_cast<std::size_t>(type));
    }
public:
    Monster(Type type): Creature{ getDefaultCreature(type) }
    {
    }  
    static Monster getRandomMonster()
    {
        return Monster
        {
            static_cast<Type>(getRandomNumber(0, static_cast<int>(Type::max_types) - 1))
        };
    }
};

void attackPlayer(const Monster& monster, Player& player)
{
    if ( monster.isDead() )
    {
        return;
    }
    player.reduceHealth( monster.getDamage() );
    std::cout << "The " << monster.getName() << " hit you for "
        << monster.getDamage() << " damage.\n";
}

void attackMonster(Player& player, Monster& monster)
{
    if ( player.isDead() )
    {
        return;
    }
    std::cout << "You hit the " << monster.getName() << " for "
        << player.getDamage() << " damage.\n";
    monster.reduceHealth( player.getDamage() );
    if ( monster.isDead() )
    {
        std::cout << "You killed the " << monster.getName() << ".\n";
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << ".\n"
            << "You found " << monster.getGold() << " gold.\n";
        player.addGold( monster.getGold() );
    }
}

void fightMonster(Player& player)
{
    Monster monster{ Monster::getRandomMonster() };
    std::cout << "You have encountered a " << monster.getName()
        << " (" << monster.getSymbol() << ").\n";
 
    while ( !player.isDead() && !monster.isDead() )
    {
        std::cout << "(R)un or (F)ight: ";
        char playerInput{};
        std::cin >> playerInput;
        if ( playerInput == 'r' || playerInput == 'R' )
        {
            if ( getRandomNumber(0, 1) )
            {
                std::cout << "You successfully fled.\n";
                return;
            }
            else
            {
                std::cout << "You failed to flee.\n";
                attackPlayer(monster, player);
                continue;
            }
        }
        if ( playerInput == 'f' || playerInput == 'F' )
        {
            attackMonster(player, monster);
            attackPlayer(monster, player);
        }
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
 
    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;
    
    Player player{ playerName };
    std::cout << "Welcome, " << player.getName() << '\n';
    
    while ( !player.isDead() && !player.hasWon() )
    {
        fightMonster(player);
    }
    if ( player.isDead() )
    {
        std::cout << "You died at level " << player.getLevel()
            << " and with " << player.getGold() << " gold.\n"
            << "Too bad you can't take it with you!\n";
    }
    else
    {
        std::cout << "You won the game with " << player.getGold() << " gold!\n";
    }
    
    return 0;
}
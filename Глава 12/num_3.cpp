#include <iostream>
#include <string>
#include <array>
#include <ctime>
#include <cstdlib>

class Monster
{
public:
    enum class Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types
    };
private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_health{};
public:
    Monster(Type type, const std::string& name, const std::string& roar, int health):
        m_type{ type }, m_name{ name }, m_roar{ roar }, m_health{ health }
    {
    }
    void print()
    {
        std::cout << m_name << " the "; // Bones the skeleton has 4 hit points and says *rattle*
        switch ( static_cast<int>(m_type) )
        {
        case 0:
            std::cout << "dragon ";
            break;
        case 1:
            std::cout << "goblin ";
            break;
        case 2:
            std::cout << "ogre ";
            break;
        case 3:
            std::cout << "orc ";
            break;
        case 4:
            std::cout << "skeleton ";
            break;
        case 5:
            std::cout << "troll ";
            break;
        case 6:
            std::cout << "vampire ";
            break;
        case 7:
            std::cout << "zombie ";
            break;
        default:
            break;
        }
        std::cout << "has " << m_health << " hit points "
            << "and says " << m_roar << '\n';
    }
};

class MonsterGenerator
{
private:
    static constexpr std::array m_names
    {
        "Struzz",
        "Lurk",
        "Raazusb",
        "Urvuk",
        "Krizer",
        "Kibs"
    };
    static constexpr std::array m_roars
    {
        "*rrrr*",
        "*ooar*",
        "*fui*",
        "*oak*",
        "*unun*",
        "*mooo*"
    };
public:
    static int getRandomNumber(int min, int max)
    {
        static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
        return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
    }
    static Monster generateMonster()
    {
        return { 
            static_cast<Monster::Type>(
                getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_types) - 1)),
            m_names[ static_cast<size_t>(getRandomNumber(0, m_names.size() - 1)) ],
            m_roars[ static_cast<size_t>(getRandomNumber(0, m_roars.size() - 1)) ],
            getRandomNumber(0, 100)
        };
    }
};

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Monster m{ MonsterGenerator::generateMonster() };
    m.print();

    return 0;
}
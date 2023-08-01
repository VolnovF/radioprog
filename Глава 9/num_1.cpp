#include <iostream>
#include <string>

enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giantSpider,
    slime
};

struct Monster
{
    std::string name;
    MonsterType type;
    int health;
};

std::string getTypeMonster(Monster monster)
{
    switch (static_cast<int>(monster.type))
    {
    case 0:
        return "Ogre";
    case 1:
        return "Dragon";
    case 2:
        return "Orc";
    case 3:
        return "giant Spyder";
    case 4:
        return "Slime";
    default:
        return "";
    };
}

// This Ogre is named Torg and has 145 health.

void printMonster(Monster monster)
{
    std::cout << "This " << getTypeMonster(monster) << " is named " << monster.name
        << " and has " << monster.health << " health.\n";
}

int main()
{
    Monster firstEnemy{ "Torg", MonsterType::ogre, 145 };
    Monster secondEnemy{ "Blurp", MonsterType::slime, 23 };
    
    printMonster(firstEnemy);
    printMonster(secondEnemy);
}
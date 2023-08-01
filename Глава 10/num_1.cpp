#include <iostream>
#include <array>
#include <numeric>  

enum Item
{
    healthPotion,
    torch,
    arrow
};

int countTotalItems(std::array<int, 3> inventory)
{
    return std::reduce(inventory.begin(), inventory.end());
}

int main()
{
    std::array playerInventory{ 2, 5, 10 };
    std::cout << "Player has " << countTotalItems(playerInventory) << " items in inventory\n";
    std::cout << "He has " << playerInventory[torch] << " torches\n";

    return 0;
}
#include <cstdint>
#include <iostream>
 
int main()
{
  std::cout << "How old are you?\n";
 
  std::uint8_t age{}; // Ошибка 1
  std::cin >> age;
 
  std::cout << "Allowed to drive a car in Texas [";
 
  if (age >= 16) // Ошибка 2
    std::cout << "x"; // Ошибка 3
  else
    std::cout << " "; // Ошибка 3
 
  std::cout << "]\n";
 
  return 0;
}
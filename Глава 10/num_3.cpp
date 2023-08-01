#include <iostream>

void swap(int& a, int& b)
{
    int bCopy = b;
    b = a;
    a = bCopy;
}

int main()
{
    int a{ 4 }, b{ 7 };
    swap(a, b);
    std::cout << "Swap " << (a == 7 && b == 4 ? "successful" : "failed") << '\n';

    return 0;
}
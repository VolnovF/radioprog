#include <iostream>

void printCString(char* string)
{
    bool stringIsPrinted{ false };
    while (!stringIsPrinted)
    {
        if ( *string == 0 )
        {
            stringIsPrinted = true;
        }
        else
        {
            std::cout << *string;
            ++string;
        }
    }
    ;
}

int main()
{
    char string[]{ "Hello, world!" };
    printCString(string);

    return 0;
}
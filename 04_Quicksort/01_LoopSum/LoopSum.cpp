// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>

int Sum(const int numbers[], int arrLength);

void Wait();

int main()
{
    const int myNumbers[]{ 1, 2, 3, 4 };
    const int size{ sizeof(myNumbers) / sizeof(myNumbers[0]) };
    std::cout << Sum(myNumbers, size) << '\n';

    Wait();
}

int Sum(const int numbers[], int arrLength)
{
    int total{ 0 };
    for (int index{ 0 }; index < arrLength; ++index)
    {
        total += numbers[index];
    }
    return total;
}

void Wait()
{
    std::cout << "\nPress ENTER to quit\n";
    std::cin.get();
}

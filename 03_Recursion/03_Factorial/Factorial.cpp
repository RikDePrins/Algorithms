// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>

int Factorial(int number);

void Wait();

int main()
{
    const int myNumber{ 5 };
    std::cout << Factorial(myNumber) << '\n';

    Wait();
}

int Factorial(int number)
{
    switch (number)
    {
    // base case
    case 1:
    {
        return 1;
    }
    // recursive case
    default:
    {
        return number * Factorial(number - 1);
    }
    }
}

void Wait()
{
    std::cout << "\nPress ENTER to quit\n";
    std::cin.get();
}

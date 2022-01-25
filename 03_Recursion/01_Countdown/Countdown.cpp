// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>

void Countdown(int number);

void Wait();

int main()
{
    const int myNumber{ 5 };
    Countdown(myNumber);

    Wait();
}

void Countdown(int number)
{
    std::cout << number << '\n';
    // base case
    if (number <= 0)
    {
        return;
    }
    // recursive case
    else
    {
        Countdown(number - 1);
    }
}

void Wait()
{
    std::cout << "\nPress ENTER to quit\n";
    std::cin.get();
}

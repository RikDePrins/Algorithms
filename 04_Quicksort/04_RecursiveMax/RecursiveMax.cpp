// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>
#include <vector>

int Max(const std::vector<int>& numbers);

void Wait();

int main()
{
    const std::vector<int> myNumbers{ 1, 2, 3, 4 };
    std::cout << Max(myNumbers) << '\n';

    Wait();
}

int Max(const std::vector<int>& numbers)
{
    switch (numbers.size())
    {
    case 2:
    {
        return (numbers[0] > numbers[1]) ? numbers[0] : numbers[1];
    }
    default:
    {
        const int subMax{ Max(std::vector<int>{ numbers.begin() + 1, numbers.end() }) };
        return (numbers[0] > subMax) ? numbers[0] : subMax;
    }
    }
}

void Wait()
{
    std::cout << "\nPress ENTER to quit\n";
    std::cin.get();
}

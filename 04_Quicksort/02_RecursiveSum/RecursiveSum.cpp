// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>
#include <vector>

void Wait();

int Sum(const std::vector<int>& numbers);

int main()
{
    const std::vector<int> myNumbers{ 1, 2, 3, 4 };
    std::cout << Sum(myNumbers) << '\n';

    Wait();
}

int Sum(const std::vector<int>& numbers)
{
    if (numbers.empty())
    {
        return 0;
    }
    else
    {
        const int subSum{ Sum(std::vector<int>{ numbers.begin() + 1, numbers.end() }) };
        return numbers[0] + subSum;
    }
}

void Wait()
{
    std::cout << "\nPress ENTER to quit\n";
    std::cin.get();
}

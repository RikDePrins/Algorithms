// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>
#include <vector>

int Count(const std::vector<int>& vector);

void Wait();

int main()
{
    const std::vector<int> myVector{ 1, 3, 5, 7, 9 };
    std::cout << Count(myVector) << '\n';

    Wait();
}

int Count(const std::vector<int>& vector)
{
    if (vector.empty())
    {
        return 0;
    }
    else
    {
        const int subCount{ Count(std::vector<int>{ vector.begin() + 1, vector.end() }) };
        return 1 + subCount;
    }
}

void Wait()
{
    std::cout << "\nPress ENTER to quit\n";
    std::cin.get();
}

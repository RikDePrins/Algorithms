// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>
#include <map>

void Print(const std::map<std::string, float>& map);
void Wait();

int main()
{
    std::map<std::string, float> book{};
    // An apple costs 67 cents.
    book["apple"] = .67f;
    // Milk costs $1.49.
    book["milk"] = 1.49f;
    book["avocado"] = 1.49f;
    Print(book);

    Wait();
}

void Print(const std::map<std::string, float>& map)
{
    std::cout << '{';
    for (auto iterator{ map.begin() }; iterator != map.end(); ++iterator)
    {
        std::cout << iterator->first << ": " << iterator->second;
        if (iterator->first != map.rbegin()->first)
        {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
}

void Wait()
{
    std::cout << "\nPress ENTER to quit\n";
    std::cin.get();
}

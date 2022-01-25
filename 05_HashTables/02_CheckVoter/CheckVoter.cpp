// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>
#include <map>

void CheckVoter(const std::string& name);

void Wait();

int main()
{
    std::string myName{ "Tom" };
    CheckVoter(myName);
    myName = "Mike";
    CheckVoter(myName);
    CheckVoter(myName);

    Wait();
}

void CheckVoter(const std::string& name)
{
    static std::map<std::string, bool> voted{};
    if (voted[name])
    {
        std::cout << "Kick them out!\n";
    }
    else
    {
        voted[name] = true;
        std::cout << "Let them vote!\n";
    }
}

void Wait()
{
    std::cout << "\nPress ENTER to quit\n";
    std::cin.get();
}

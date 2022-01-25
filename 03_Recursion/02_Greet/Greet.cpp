// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>

void Greet(const std::string& name);
void Greet2(const std::string& name);
void SayBye();

void Wait();

int main()
{
    const std::string myName{ "Adit" };
    Greet(myName);

    Wait();
}

void Greet(const std::string& name)
{
    std::cout << "Hello, " << name << "!\n";
    Greet2(name);
    std::cout << "Getting ready to say bye...\n";
    SayBye();
}

void Greet2(const std::string& name)
{
    std::cout << "How are you, " << name << "?\n";
}

void SayBye()
{
    std::cout << "Okay, bye!\n";
}

void Wait()
{
    std::cout << "\nPress ENTER to quit\n";
    std::cin.get();
}

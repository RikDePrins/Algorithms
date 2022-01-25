// De Prins, Rik - 1DAE10

#include "pch.h"
#include <deque>
#include <iostream>
#include <map>
#include <vector>

bool Search(const std::string& name);
bool IsPersonSeller(const std::string& name);

void Wait();

int main()
{
    Search("You");

    Wait();
}

bool Search(const std::string& name)
{
    std::map<std::string, std::deque<std::string>> graph{};
    graph["You"] = std::deque<std::string>{ "Alice", "Bob", "Claire" };
    graph["Bob"] = std::deque<std::string>{ "Anuj", "Peggy" };
    graph["Claire"] = std::deque<std::string>{ "Thom", "Jonny" };
    graph["Alice"] = std::deque<std::string>{ "Peggy" };
    graph["Anuj"] = std::deque<std::string>{};
    graph["Peggy"] = std::deque<std::string>{};
    graph["Thom"] = std::deque<std::string>{};
    graph["Jonny"] = std::deque<std::string>{};

    std::deque<std::deque<std::string>> searchQue{};
    searchQue.push_back(graph[name]);

    // This list is how you keep track of which people you've searched before.
    std::vector<std::string> searched{};

    while (!searchQue.empty())
    {
        const std::string person{ searchQue[0][0] };
        switch (searchQue[0].size())
        {
        case 1:
        {
            searchQue.pop_front();
            break;
        }
        default:
        {
            searchQue[0].pop_front();
            break;
        }
        }
        
        // Only search this person if you haven't already searched them.
        if (!(std::count(searched.begin(), searched.end(), person)))
        {
            if (IsPersonSeller(person))
            {
                std::cout << person << " is a mango seller!\n";
                return true;
            }
            else
            {
                if (graph[person].size() > 1)
                {
                    searchQue.push_back(graph[person]);
                }

                // Mark this person as searched
                searched.push_back(person);
            }
        }
    }
    return false;
}

bool IsPersonSeller(const std::string& name)
{
    return name[name.length() - 1] == 'm';
}

void Wait()
{
    std::cout << "\nPress ENTER to quit\n";
    std::cin.get();
}

// De Prins, Rik - 1DAE10

#include "pch.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

void Print(const std::vector<std::string>& vector);
void Wait();

int main()
{
    std::vector<std::string> statesNeeded{ "mt", "wa", "or", "id", "nv", "ut", "ca", "az" };

    std::map<std::string, std::vector<std::string>> stations{};
    stations["kone"] = std::vector<std::string>{ "id", "nv", "ut" };
    stations["ktwo"] = std::vector<std::string>{ "wa", "id", "mt" };
    stations["kthree"] = std::vector<std::string>{ "or", "nv", "ca" };
    stations["kfour"] = std::vector<std::string>{ "nv", "ut" };
    stations["kfive"] = std::vector<std::string>{ "ca", "az" };

    std::vector<std::string> finalStations{};

    while (!statesNeeded.empty())
    {
        // Sort states needed
        std::sort(statesNeeded.begin(), statesNeeded.end());

        std::string bestStation{};
        std::vector<std::string> statesCovered{};
        
        for (auto iterator{ stations.begin() }; iterator != stations.end(); ++iterator)
        {
            // Sort states in station
            std::sort(iterator->second.begin(), iterator->second.end());

            std::vector<std::string> covered{};

            // Append intersection of states needed and states in station to covered
            std::set_intersection(statesNeeded.begin(), statesNeeded.end(),
                                  iterator->second.begin(), iterator->second.end(), 
                                  std::back_inserter(covered));

            if (covered.size() > statesCovered.size())
            {
                bestStation = iterator->first;
                statesCovered = covered;
            }
        }

        for (unsigned int index{ 0 }; index < statesCovered.size(); ++index)
        {
            auto iterator{ std::find(statesNeeded.begin(), statesNeeded.end(), statesCovered[index]) };
            statesNeeded.erase(iterator);
        }

        finalStations.push_back(bestStation);
    }

    Print(finalStations);

    Wait();
}

void Print(const std::vector<std::string>& vector)
{
    std::cout << '{';
    for (unsigned int index{ 0 }; index < vector.size(); ++index)
    {
        std::cout << '"' << vector[index] << '"';
        if (index != vector.size() - 1)
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

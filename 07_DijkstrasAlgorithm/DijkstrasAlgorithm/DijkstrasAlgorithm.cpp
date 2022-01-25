// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>
#include <map>
#include <vector>

std::string FindLowestCostNode(std::map<std::string, int>& costs, const std::vector<std::string>& processed);

void Print(const std::map<std::string, int>& map);
void Wait();

int main()
{
    // graph
    std::map<std::string, std::map<std::string, int>> graph{};

    graph["start"] = {};
    graph["start"]["a"] = 6;
    graph["start"]["b"] = 2;

    graph["a"] = {};
    graph["a"]["finish"] = 1;

    graph["b"] = {};
    graph["b"]["a"] = 3;
    graph["b"]["finish"] = 5;

    graph["finish"] = {};

    // costs table
    const int infinity{ INT_MAX };
    std::map<std::string, int> costs{};
    costs["a"] = 6;
    costs["b"] = 2;
    costs["finish"] = infinity;

    // parents table
    std::map<std::string, std::string> parents{};
    parents["a"] = "start";
    parents["b"] = "start";
    parents["finish"] = {};

    std::vector<std::string> processed{};

    // Find the lowest - cost node that you haven't processed yet.
    std::string node{ FindLowestCostNode(costs, processed) };
    // If you've processed all the nodes, this while loop is done.
    while (!node.empty())
    {
        int cost{ costs[node] };

        // Go through all the neighbors of this node.
        std::map<std::string, int> neighbors{ graph[node] };

        for (auto iterator{ neighbors.begin() }; iterator != neighbors.end(); ++iterator)
        {
            int newCost{ cost + neighbors[iterator->first] };

            // If it's cheaper to get to this neighbor by going through this node...
            if (costs[iterator->first] > newCost)
            {
                // ... update the cost for this node.
                costs[iterator->first] = newCost;
                // This node becomes the new parent for this neighbor.
                parents[iterator->first] = node;
            }
        }
                
        // Mark the node as processed.
        processed.push_back(node);
        // Find the next node to process, and loop.
        node = FindLowestCostNode(costs, processed);
    }

    std::cout << "Cost from the start to each node:\n";
    Print(costs);

    Wait();
}

std::string FindLowestCostNode(std::map<std::string, int>& costs, const std::vector<std::string>& processed)
{
    int lowestCost{ INT_MAX };
    std::string lowestCostNode{};
    // Go through each node.
    for (auto nodeIterator{ costs.begin() }; nodeIterator != costs.end(); ++nodeIterator)
    {
        int cost{ costs[nodeIterator->first] };
        // If it's the lowest cost so far and hasn't been processed yet...
        if (cost < lowestCost && !(std::count(processed.begin(), processed.end(), nodeIterator->first)))
        {
            // ... set it as the new lowest-cost node.
            lowestCost = cost;
            lowestCostNode = nodeIterator->first;
        }
    }
    return lowestCostNode;
}

void Print(const std::map<std::string, int>& map)
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

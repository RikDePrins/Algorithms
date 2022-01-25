// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>
#include <vector>

std::vector<int> SelectionSort(std::vector<int>& vector);
int FindSmallest(const std::vector<int>& vector);

void Print(const std::vector<int>& vector);
void Wait();

int main()
{
    std::vector<int> myVector{ 5, 3, 6, 2, 10 };
    const std::vector<int> myNewVector{ SelectionSort(myVector) };
    Print(myNewVector);

    Wait();
}

// Sort array
std::vector<int> SelectionSort(std::vector<int>& vector)
{
    std::vector<int> newVector{};
    for (unsigned int index{ 0 }; index < vector.size(); ++index)
    {
        // Find smallest element in array and add it to new array
        const int smallest{ FindSmallest(vector) };
        newVector.push_back(vector[smallest]);
        vector.erase(vector.begin() + smallest);
    }
    return newVector;
}

// Find smallest value in array
int FindSmallest(const std::vector<int>& vector)
{
    // Store smallest value
    int smallest{ vector[0] };
    // Store index of smallest value
    int smallestIndex{ 0 };

    for (unsigned int index{ 1 }; index < vector.size(); ++index)
    {
        if (vector[index] < smallest)
        {
            smallest = vector[index];
            smallestIndex = index;
        }
    }
    return smallestIndex;
}

void Print(const std::vector<int>& vector)
{
    std::cout << '[';
    for (unsigned int index{ 0 }; index < vector.size(); ++index)
    {
        std::cout << vector[index];
        if (index != vector.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

void Wait()
{
    std::cout << "\nPress ENTER to quit\n";
    std::cin.get();
}

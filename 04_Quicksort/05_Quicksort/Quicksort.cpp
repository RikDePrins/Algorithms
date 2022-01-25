// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>

void Quicksort(int numbers[], int low, int high);
int Partition(int numbers[], int low, int high);

void Swap(int* number1, int* number2);
void Print(int arr[], int arrLength);
void Wait();

int main()
{
    int myNumbers[]{ 10, 5, 2, 3 };
    const int size{ sizeof(myNumbers) / sizeof(myNumbers[0]) };
    Quicksort(myNumbers, 0, size - 1);
    Print(myNumbers, size);

    Wait();
}

void Quicksort(int numbers[], int low, int high)
{
    if (low < high)
    {
        // Pivot is in the middle after partitioning.
        int pivot{ Partition(numbers, low, high) };

        // Separately sort elements before and after pivot.
        Quicksort(numbers, low, pivot - 1);
        Quicksort(numbers, pivot + 1, high);
    }
}

int Partition(int numbers[], int low, int high)
{
    int pivot{ numbers[high] };
    int i{ low - 1 }; // index of smaller element
    for (int j{ low }; j < high; ++j)
    {
        // If current element is smaller than or equal to pivot ...
        if (numbers[j] <= pivot)
        {
            ++i; // ... increment index of smaller element
            Swap(&numbers[i], &numbers[j]);
        }
    }
    ++i;
    Swap(&numbers[i], &numbers[high]);
    return i;
}

void Swap(int* number1, int* number2)
{
    int temp{ *number1 };
    *number1 = *number2;
    *number2 = temp;
}

void Print(int arr[], int arrLength)
{
    std::cout << "[";
    for (int index{ 0 }; index < arrLength; ++index)
    {
        std::cout << arr[index];
        if (index != arrLength - 1)
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

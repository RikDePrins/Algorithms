// De Prins, Rik - 1DAE10

#include "pch.h"
#include <iostream>

int BinarySearch(const int arr[], int arrLength, int item);

void Wait();

int main()
{
    const int myArr[]{ 1, 3, 5, 7, 9 };
    const int size{ sizeof(myArr) / sizeof(myArr[0]) };
    int myItem{ 3 };
    std::cout << BinarySearch(myArr, size, myItem) << '\n'; // => 1

    myItem = -1;
    // We use -1 to indicate that the item wasn't found.
    std::cout << BinarySearch(myArr, size, myItem) << '\n'; // => -1

    Wait();
}

int BinarySearch(const int arr[], int arrLength, int item)
{
    // Low and high keep track of which part of the array you'll search in.
    int low{ 0 };
    int high{ arrLength };

    // While you haven't narrowed it down to one element ...
    while (low <= high)
    {
        // ... check the middle element.
        int mid{ (low + high) / 2 };
        int guess{ arr[mid] };

        // Found the item
        if (guess == item)
        {
            return mid;
        }
        // The guess was too high.
        if (guess > item)
        {
            high = mid - 1;
        }
        // The guess was too low.
        else
        {
            low = mid + 1;
        }
    }

    // Item doesn't exist.
    return -1;
}

void Wait()
{
    std::cout << "\nPress ENTER to quit\n";
    std::cin.get();
}

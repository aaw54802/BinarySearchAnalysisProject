#include <iostream>
#include <vector>
#include <algorithm>
#include "searchAlgorithms.h"

int main() {
    // Define and sort the vector
    std::vector<int> vec = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    std::sort(vec.begin(), vec.end());

    int target1 = 7;  // In the list
    int target2 = 10; // Not in the list

    // Recursive Binary Search
    int index = recursiveBinarySearch(vec, target1, 0, vec.size() - 1);
    std::cout << "Target " << target1 << " found at location " << index << '\n';

    index = recursiveBinarySearch(vec, target2, 0, vec.size() - 1);
    std::cout << "Target " << target2 << " was not found, return value is " << index << '\n';

    // Iterative Binary Search
    index = iterativeBinarySearch(vec, target1);
    std::cout << "Target " << target1 << " found at location " << index << '\n';

    index = iterativeBinarySearch(vec, target2);
    std::cout << "Target " << target2 << " was not found, return value is " << index << '\n';

    // Sequential Search
    index = sequentialSearch(vec, target1);
    std::cout << "Target " << target1 << " found at location " << index << '\n';

    index = sequentialSearch(vec, target2);
    std::cout << "Target " << target2 << " was not found, return value is " << index << '\n';

    return 0;
}

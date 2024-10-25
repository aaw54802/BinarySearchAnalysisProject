#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "searchAlgorithms.h"

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    // Generate vector with random values
    std::vector<int> vec;
    for (int i = 0; i < 20; ++i) {  // You can adjust the size as needed
        vec.push_back(1 + std::rand() % 100);  // Random numbers in range 1 to 100
    }

    // Sort the vector for binary search
    std::sort(vec.begin(), vec.end());

    // Random target value
    int target = 1 + std::rand() % 100;

    // Output the contents of the vector
    std::cout << "Vector contents: ";
    for (int num : vec) std::cout << num << " ";
    std::cout << "\nTarget: " << target << "\n";

    // Recursive Binary Search
    int index = recursiveBinarySearch(vec, target, 0, vec.size() - 1);
    if (index >= 0)
        std::cout << "Recursive Binary Search: Target " << target << " found at location " << index << '\n';
    else
        std::cout << "Recursive Binary Search: Target " << target << " was not found\n";

    // Iterative Binary Search
    index = iterativeBinarySearch(vec, target);
    if (index >= 0)
        std::cout << "Iterative Binary Search: Target " << target << " found at location " << index << '\n';
    else
        std::cout << "Iterative Binary Search: Target " << target << " was not found\n";

    // Sequential Search
    index = sequentialSearch(vec, target);
    if (index >= 0)
        std::cout << "Sequential Search: Target " << target << " found at location " << index << '\n';
    else
        std::cout << "Sequential Search: Target " << target << " was not found\n";

    return 0;
}

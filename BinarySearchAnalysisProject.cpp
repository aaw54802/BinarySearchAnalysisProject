#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "searchAlgorithms.h"

int main() {
    // Define vector sizes for performance analysis
    std::vector<int> testSizes = { 5000, 50000, 100000, 150000, 200000 };

    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    for (int N : testSizes) {
        double sumRBS = 0.0;   // Accumulator for recursive binary search times
        double sumIBS = 0.0;   // Accumulator for iterative binary search times
        double sumSeqS = 0.0;  // Accumulator for sequential search times

        // Run the search and timing 10 times for each size N
        for (int i = 0; i < 10; ++i) {
            // Generate vector with N random values in range [1, 100]
            std::vector<int> vec;
            for (int j = 0; j < N; ++j) {
                vec.push_back(1 + std::rand() % 100);
            }

            // Sort the vector for binary search algorithms
            std::sort(vec.begin(), vec.end());

            // Generate a random target
            int target = 1 + std::rand() % 100;

            // Timing Recursive Binary Search
            auto start = std::chrono::high_resolution_clock::now();
            recursiveBinarySearch(vec, target, 0, vec.size() - 1);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::micro> duration = end - start;
            sumRBS += static_cast<double>(duration.count());

            // Timing Iterative Binary Search
            start = std::chrono::high_resolution_clock::now();
            iterativeBinarySearch(vec, target);
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            sumIBS += static_cast<double>(duration.count());

            // Timing Sequential Search
            start = std::chrono::high_resolution_clock::now();
            sequentialSearch(vec, target);
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            sumSeqS += static_cast<double>(duration.count());
        }

        // Calculate and output average running times
        std::cout << "For N = " << N << ":\n";
        std::cout << "Average Running Time for Recursive Binary Search (microseconds): " << sumRBS / 10 << '\n';
        std::cout << "Average Running Time for Iterative Binary Search (microseconds): " << sumIBS / 10 << '\n';
        std::cout << "Average Running Time for Sequential Search (microseconds): " << sumSeqS / 10 << '\n';
        std::cout << "-----------------------------------------\n";
    }

    return 0;
}

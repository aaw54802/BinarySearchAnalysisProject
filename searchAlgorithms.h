#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include <vector>

// Recursive Binary Search
int recursiveBinarySearch(const std::vector<int>& vec, int target, int low, int high);

// Iterative Binary Search
int iterativeBinarySearch(const std::vector<int>& vec, int target);

// Sequential Search
int sequentialSearch(const std::vector<int>& vec, int target);

#endif



#include "searchAlgorithms.h"

// Recursive Binary Search
int recursiveBinarySearch(const std::vector<int>& vec, int target, int low, int high) {
    if (low > high) return -1;  // Base case: not found

    int mid = low + (high - low) / 2;
    if (vec[mid] == target)
        return mid;
    else if (vec[mid] > target)
        return recursiveBinarySearch(vec, target, low, mid - 1);
    else
        return recursiveBinarySearch(vec, target, mid + 1, high);
}

// Iterative Binary Search
int iterativeBinarySearch(const std::vector<int>& vec, int target) {
    int low = 0, high = vec.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (vec[mid] == target)
            return mid;
        else if (vec[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;  // Not found
}

// Sequential Search
int sequentialSearch(const std::vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) return i;
    }
    return -1;  // Not found
}

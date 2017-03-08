#include "binarySearch.h"

// customized binary search
// you can change inner binarySearch.cpp file functor F, for any purposes
// current finds index of min an in array a = [a0 > a1 > .. > an < b1 < b2 < .. < bm]
const auto F = [](const auto& ar, int midIdx) {

    // Check for range constraints
    if (midIdx == ar.size() - 1 || midIdx == 0) {
        return -1;
    }

    if (ar[midIdx - 1] > ar[midIdx] && ar[midIdx] > ar[midIdx+1]) {
        return -1;
    } else if (ar[midIdx - 1] < ar[midIdx] && ar[midIdx] < ar[midIdx + 1]) {
        return 1;
    }
    return 0;
};

int binarySearch(const vector<int>& ar) {
    auto lo = 0;
    auto high = ar.size() - 1;

    while (lo <= high) {
        const auto mid = lo + (high - lo) / 2;
        const auto res = F(ar, mid);

        if (res < 0) {
            lo = mid + 1;
        } else if (res > 0) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

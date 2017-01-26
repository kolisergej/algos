#include "binarySearch.h"

int binarySearch(const vector<int>& ar) {
    int lo = 0;
    int high = ar.size() - 1;
    if (lo > high) {
	return -1;
    }

    const auto F = [](int a, int b, int val) {
	if (a > val && val > b) {
	    return -1;
	} else if (a < val && val < b) {
	    return 1;
	}
	return 0;
    };

    while (lo <= high) {
	const int mid = lo + (high - lo) / 2;
	const int res = F(ar[mid - 1], ar[mid + 1], ar[mid]);
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

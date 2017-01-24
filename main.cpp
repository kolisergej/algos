#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <unordered_set>

using namespace std;

// 2 sum
bool hasPairSumOf(const vector<int>& vec, int sum) {
    unordered_set<int> processedValues;
    for (int i = 0; i < vec.size(); ++i) {
        if (processedValues.count(sum - vec[i])) {
            return true;
        } else {
            processedValues.insert(vec[i]);
        }
    }
    return false;
}


// customized binary search
// you can change functor F, for any purposes
// current finds index of min an in array a = [a0 > a1 > .. > an < b1 < b2 < .. < bm]
int binarySearch(const vector<int>& ar, int lo, int high) {
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



int main() {
    const vector<int> ar = {10,9,8,7,5,4,3,2,1,2,6,10};
    cout << binarySearch(ar, 0, ar.size()) << endl;
    return 0;
}


#include "threeSumProblem.h"


vector<vector<int>> threeSumSolve(vector<int>&& vec) {
    sort(vec.begin(), vec.end());

    vector<vector<int>> result;
    for (size_t i = 0; i < vec.size(); i++) {
        size_t low = i + 1;
        size_t high = vec.size() - 1;
        while (low < high) {
            const int sum = vec[i] + vec[low] + vec[high];
            if (sum > 0) {
                --high;
            } else if (sum < 0) {
                ++low;
            } else {
                vector<int> trio;
                trio.push_back(vec[i]);
                trio.push_back(vec[low]);
                trio.push_back(vec[high]);
                result.push_back(trio);

                while(low < high && trio[1] == vec[low]) {
                    ++low;
                }

                while(low < high && trio[2] == vec[high]) {
                    --high;
                }
            }
        }

        while(i + 1 < vec.size() && vec[i] == vec[i+1]) {
            ++i;
        }
    }
    return result;
}


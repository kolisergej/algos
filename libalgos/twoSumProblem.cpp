#include "twoSumProblem.h"

#include <unordered_set>

bool hasPairSumOf(const vector<int>& vec, int sum){
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


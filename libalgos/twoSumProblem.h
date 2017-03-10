#ifndef SUMPROBLEM
#define SUMPROBLEM

#include <vector>

using namespace std;

/// @brief Decision for 2 sum problem
/// There are different solutions, lots of them for sorted vector
/// Complexity O(n) - for hash table
/// @param[in] vec - input digit array
/// @param[in] sum - target sum of two elements
/// @return mark does input array has sum of two elements equal to "sum"
bool hasPairSumOf(const vector<int>& vec, int sum);

#endif // SUMPROBLEM


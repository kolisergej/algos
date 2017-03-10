#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <vector>

using namespace std;

/// @brief Binary search algorithm with custom functor inside
/// @param[in] ar - input array
/// @return Position of interested by custom functor element
///         -1 - if not such element
int binarySearch(const vector<int>& ar);

#endif // BINARYSEARCH_H

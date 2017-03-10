#ifndef REVERSELIST_H
#define REVERSELIST_H

struct Node {
    int val;
    Node* pNext;
};

/// @brief reverse one-forward linked list
/// @param[in] head - head of list
/// @return pHead of new list. Need to be freed
Node* reverseList(Node* pHead);

/// @brief show list elements
/// param[in] pHead - head of list
void showList(Node* pHead);

/// @brief Delete list elements
/// param[in] pHead - head of list
void freeList(Node* pHead);

#endif // REVERSELIST_H

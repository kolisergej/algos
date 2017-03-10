#include <iostream>

#include "reverseList.h"

using namespace std;

void showList(Node* pHead) {
    Node* curr = pHead;
    while (curr) {
        cout << curr->val << endl;
        curr = curr->pNext;
    }
}

void freeList(Node* pHead) {
    Node* curr = pHead;
    while (curr) {
        Node* tmp = curr->pNext;
        delete curr;
        curr = tmp;
    }
}

Node* reverseList(Node* pHead) {
    Node* curr = pHead;
    Node* prev = 0;
    while (curr != nullptr) {
        // Remember next
        Node* next = curr->pNext;

        // Swap pointers
        curr->pNext = prev;
        prev = curr;

        // Set up next
        curr = next;
    }
    // Set up head to last prev pointer
    pHead = prev;
    return pHead;
}

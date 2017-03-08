#include <iostream>

#include "reverseList.h"

using namespace std;

void show(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->val << endl;
        curr = curr->next;
    }
}

void reverse() {
    Node a;
    Node b;
    Node c;
    Node d;
    a.val = 1;
    a.next = &b;
    b.val = 2;
    b.next = &c;
    c.val = 3;
    c.next = &d;
    d.val = 4;
    d.next = nullptr;

    List l{&a};

    show(l.head);

    Node* curr = l.head;
    Node* prev = 0;
    while (curr != nullptr) {
        // Remember next
        Node* next = curr->next;

        // Swap pointers
        curr->next = prev;
        prev = curr;

        // Set up next
        curr = next;
    }
    // Set up head to last prev pointer
    l.head = prev;

    show(l.head);
}

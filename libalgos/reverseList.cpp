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
        Node* next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l.head = prev;

    show(l.head);
}

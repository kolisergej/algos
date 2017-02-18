#ifndef REVERSELIST_H
#define REVERSELIST_H

// reverse one-forward linked list
struct Node {
    int val;
    Node* next;
};

struct List {
    Node* head;
};

void show(Node* head);

void reverse();

#endif // REVERSELIST_H

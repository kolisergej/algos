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


// reverse one-forward linked list
struct Node {
    int val;
    Node* next;
};

struct List {
    Node* head;
};

void show(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->val << endl;
        curr = curr->next;
    }
}

void reverse() {
    List l;
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
    l.head = &a;

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

int main() {
    reverse();
    return 0;
}


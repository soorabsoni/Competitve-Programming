#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int data) : val(data), next(NULL) {}
    ListNode(int data, ListNode *node) : val(data), next(node) {}
};

int main() {
    ListNode *head = new ListNode(1, new ListNode(2));
    return 1;
}

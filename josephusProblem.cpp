#include<bits/stdc++.h>
using namespace std;

class ListNode {
	public:
		int val;
		ListNode *next;
		ListNode(int data) : val(data), next(NULL) {}
		
};

void josephusProblem(ListNode *head) {
	while (head->next != head) {
//		cout << head->val << " kills " << head->next->val << endl;
		head->next = head->next->next;
		head = head->next;
	}
	cout << head->val << endl;
}

void execute(int n) {
	ListNode *head = new ListNode(1), *curr = NULL;
	curr = head;
	for (int i = 2; i <= n; i++) {
		head->next = new ListNode(i);
		head = head->next;
	}
	head->next = curr;
	josephusProblem(curr);
}

int main() {
	while (true) {
		int x;
		cin >> x;
		if (x == -1) break;
		execute(x);
	}
	
	return 1;
}

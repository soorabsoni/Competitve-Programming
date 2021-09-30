#include<bits/stdc++.h>
using namespace std;

class ListNode {
	public:
		int val;
		ListNode *next;
		
		ListNode(int data) : val(data), next(NULL) {}
};

void deathGame(ListNode *head, int k) {
	while (head->next != head) {
		int count = 1;
		while (count+1 != k and head->next != head) {
			head = head->next;
			count++;
		}
		if (head == head->next) break;
		head->next = head->next->next;
		head = head->next;
	}
	
	cout << head->val << endl;
}

void execute(int n, int k) {
	ListNode *head = new ListNode(1), *curr = NULL;
	curr = head;
	
	for (int i = 2; i <= n; i++) {
		head->next = new ListNode(i);
		head = head->next;
	}	
	head->next = curr;
	
	deathGame(curr, k);
}

int main() {
	execute(2, 2);
	execute(5, 2);
	execute(10, 2);
	execute(32, 2);
	
}

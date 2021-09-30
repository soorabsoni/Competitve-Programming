#include<bits/stdc++.h>
using namespace std;

class ListNode {
	public:
		int val;
		ListNode *next;
		ListNode(int data) : val(data), next(NULL) {}
		
};

ListNode *createList(vector<int> &v) {
	ListNode *head = new ListNode(v[0]);
	ListNode *curr = head;
	
	for (int i = 1; i < v.size(); i++) {
		curr->next = new ListNode(v[i]);
		curr = curr->next;
	}
	return head;
}

void printList(ListNode *head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

ListNode *slim(ListNode *head, unordered_map<int, int> &um) {
	if (!head) return NULL;
	
	if (um[head->val] == 1) {
		head->next = slim(head->next, um);
		return head;
	}
	return slim(head->next, um);
}

void removeDuplicates(ListNode *head) {
	ListNode *curr = head;
	unordered_map<int, int> um;
	
	while (curr) {
		if (um.count(curr->val)) {
			um[curr->val] += 1;
		} else {
			um[curr->val] = 1;
		}
		curr = curr->next;
	}
	
	ListNode *result = slim(head, um);
	printList(result);
}

pair<ListNode*, bool> withoutBuffer(ListNode *head, int k) {
	if (!head) return {NULL, false};
	
	if (head->val == k) {
		return {withoutBuffer(head->next, k).first, true};
	}
	
	pair<ListNode *, bool> p = withoutBuffer(head->next, k);
	head->next = p.first;
	
	return {head, p.second} ;
}

void bufferKiller(ListNode *head) {
	ListNode *curr = head, *prev = NULL;
	while (head) {
		cout << "XOXO  " << head->val << endl;
		pair<ListNode *, bool> p = withoutBuffer(head->next, head->val);
		if (p.second) {
			if (prev) {
				prev->next = p.first;
			} else {
				curr = p.first;
			}
			head = p.first;
			
		} else {
			prev = head;
			head = head->next;
		}
		printList(curr);	
	}
	
	printList(curr);
}

void withoutBuffer2(ListNode *head) {
	ListNode *curr = head, *prev = NULL;
		
	while (curr) {
		int k = curr->val;
		bool found = false;
		ListNode *temp = curr->next;
		cout << "LULL " << curr->val << "  ";
		if (prev) cout << prev->val;
		cout << endl;
		while (temp) {
			if (temp->val == k) {
				found = true;
				if (temp->next) {
					*(temp) = *(temp->next);
				}
				else {
					prev->next = NULL;
					break;
				}
			} else {
				prev = temp;
				temp = temp->next;
			}
		}
		
		if (found) {
			if (curr == head) {
				*(curr) = *(curr->next);
				head = curr;
			} else {
				*(curr) = *(curr->next);
			}
		} else {
			prev = curr;
			curr = curr->next;
		}
		printList(head);
	}
	
	printList(head);
}

int main() {
	vector<int> v = {1, 1, 2, 3, 2, 4, 9, 2, 5, 5, 6, 6, 4, 11, 3};
	ListNode *head = createList(v);
	
	printList(head);
//	removeDuplicates(head);
	bufferKiller(head);
}

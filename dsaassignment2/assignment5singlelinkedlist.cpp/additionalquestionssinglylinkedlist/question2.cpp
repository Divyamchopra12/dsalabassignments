#include<iostream>
using namespace std;

class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};

ListNode* reverseLinkedListKGroup(ListNode* head, int k) {
	ListNode* currentNode = head;
	int totalNodes = 0;
	while (currentNode != NULL && totalNodes < k) {
		currentNode = currentNode->next;
		totalNodes++;
	}
	if (totalNodes < k) {
		return head;
	}
	currentNode = head;
	ListNode* prevNode = NULL;
	ListNode* nextNode;
	int nodeCount = 0;
	while (nodeCount < k) {
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
		nodeCount++;
	}
	head->next = reverseLinkedListKGroup(nextNode, k);
	return prevNode;	
}
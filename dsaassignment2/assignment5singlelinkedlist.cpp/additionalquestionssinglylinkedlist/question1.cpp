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

ListNode* findIntersectionNode (ListNode *A, ListNode *B, int difference) {
	while(difference > 0) {
		A = A->next;
		difference--;
	}
	while (A != NULL && B!= NULL) {
		if (A==B) {
			return A;
		}
		A = A->next;
		B = B->next;
	}
	return NULL;
}
ListNode* getIntersectionNode(ListNode *A, ListNode *B) {
    int firstLength = 0;
	ListNode* firstCurrNode = A;
	while (firstCurrNode != NULL) {
		firstLength++;
		firstCurrNode = firstCurrNode->next;
	}
	int secondLength = 0;
	ListNode* secondCurrNode = B;
	while (secondCurrNode != NULL) {
		secondLength++;
		secondCurrNode = secondCurrNode->next;
	}
	if (firstLength < secondLength) {
		return findIntersectionNode (B, A, secondLength - firstLength);
	} else {
		return findIntersectionNode (A, B, firstLength - secondLength);
	}
}
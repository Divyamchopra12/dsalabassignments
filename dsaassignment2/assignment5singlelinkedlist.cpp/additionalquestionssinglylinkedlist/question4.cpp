#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};


Node* rotateLinkedList(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    
    Node* tail = head;
    int len = 1;
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    
    k = k % len;
    if (k == 0) return head;

    
    tail->next = head;

    
    int steps = len - k;
    Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    
    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}


void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    int k = 2;
    head = rotateLinkedList(head, k);

    cout << "Rotated List by " << k << " places: ";
    printList(head);

    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

int sizeOfDoublyLinkedList(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int sizeOfCircularLinkedList(Node* head) {
    if (head == NULL)
        return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    Node* head1 = new Node(10);
    Node* second1 = new Node(20);
    Node* third1 = new Node(30);
    head1->next = second1;
    second1->prev = head1;
    second1->next = third1;
    third1->prev = second1;
    cout << "Size of Doubly Linked List: " << sizeOfDoublyLinkedList(head1) << endl;

    Node* head2 = new Node(5);
    Node* second2 = new Node(15);
    Node* third2 = new Node(25);
    head2->next = second2;
    second2->next = third2;
    third2->next = head2;
    cout << "Size of Circular Linked List: " << sizeOfCircularLinkedList(head2) << endl;

    return 0;
}

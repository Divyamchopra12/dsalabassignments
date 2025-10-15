#include <iostream>
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

// Insert at end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        head->next = head; // points to itself
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Insert at beginning
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// Delete a specific node by value
void deleteNode(Node*& head, int key) {
    if (head == NULL)
        return;

    Node *curr = head, *prev = NULL;

    // Case 1: Only one node
    if (head->data == key && head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    // Case 2: Head node to be deleted
    if (head->data == key) {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = head->next;
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }

    // Case 3: Any middle or last node
    while (curr->next != head && curr->data != key) {
        prev = curr; 
        curr = curr->next; 
    }

    if (curr->data == key) {
        prev->next = curr->next;
        delete curr;
    }
}

// Display the circular linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n";
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Circular Linked List: ";
    display(head);

    insertAtBeginning(head, 5);
    cout << "After inserting 5 at beginning: ";
    display(head);

    deleteNode(head, 30);
    cout << "After deleting 30: ";
    display(head);

    return 0;
}

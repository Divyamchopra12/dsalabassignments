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

void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAfterValue(Node*& head, int val, int key) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) return;
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning(Node*& head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteSpecific(Node*& head, int key) {
    if (head == NULL) return;
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;
    if (temp->next == NULL) return;
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
}

void searchNode(Node* head, int key) {
    int pos = 1;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found" << endl;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int choice, val, key;
    do {
        cout << "\n1.Insert at beginning\n2.Insert at end\n3.Insert after value\n4.Delete from beginning\n5.Delete from end\n6.Delete specific node\n7.Search\n8.Display\n9.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: cin >> val; insertAtBeginning(head, val); break;
        case 2: cin >> val; insertAtEnd(head, val); break;
        case 3: cin >> val >> key; insertAfterValue(head, val, key); break;
        case 4: deleteFromBeginning(head); break;
        case 5: deleteFromEnd(head); break;
        case 6: cin >> key; deleteSpecific(head, key); break;
        case 7: cin >> key; searchNode(head, key); break;
        case 8: display(head); break;
        }
    } while (choice != 9);
    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

Node* addPolynomial(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* tail = NULL;

    while (head1 && head2) {
        Node* temp = NULL;
        if (head1->pow == head2->pow) {
            temp = new Node(head1->coeff + head2->coeff, head1->pow);
            head1 = head1->next;
            head2 = head2->next;
        } 
        else if (head1->pow > head2->pow) {
            temp = new Node(head1->coeff, head1->pow);
            head1 = head1->next;
        } 
        else {
            temp = new Node(head2->coeff, head2->pow);
            head2 = head2->next;
        }

        if (!result) {
            result = temp;
            tail = temp;
        } else {
            tail->n

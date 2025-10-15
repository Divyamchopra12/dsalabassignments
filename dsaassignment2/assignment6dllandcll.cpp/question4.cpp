#include<iostream>
using namespace std;
class node{
public:
int data;
node* next;
node* prev;
public:
node(int val){
    data=val;
    next = NULL;
    prev=NULL;
}



};
bool  ispalindrome(node* head){
    if(head!=NULL|| head->next==NULL){
        return true;
    }
    node* start=head;
    node* end =head;
    while(end->next!=NULL){
        end=end->next;
    }
    while(start!=end&& end->next!=start){
        if(start->data!=end->data){
            return false;
        }
        start=start->next;
        end=end->prev;
    }
    return true;
}
int main(){
    node* head=new node('l');
    node* second=new node('e');
    node* third=new node('v');
    node* fourth=new node('e');
    node* fifth=new node('l');

    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    third->next=fourth;
    fourth->next=fifth;
    fifth->prev=fourth;
    if (ispalindrome(head))
        cout << "The doubly linked list is a palindrome." << endl;
    else
        cout << "The doubly linked list is not a palindrome." << endl;

    return 0;


}
#include <iostream>
using namespace std;

// Define the structure of a BST Node 
struct Node { 
    int data; 
    Node* left; 
    Node* right; 
    Node(int val) { 
        data = val; 
        left = right = nullptr;  
    } 
}; 

// Function to insert a new node into BST 
Node* insert(Node* root, int val) { 
    if (root == nullptr) 
        return new Node(val); 
    if (val < root->data) 
        root->left = insert(root->left, val); 
    else if (val > root->data) 
        root->right = insert(root->right, val); 
    return root;
}

// (a) Search (Recursive)
bool searchRecursive(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// (a) Search (Non-Recursive)
bool searchIterative(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data)
            return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

// (b) Find Maximum element in BST
Node* findMax(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

// (c) Find Minimum element in BST
Node* findMin(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// (d) Inorder Successor of a given node
Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != nullptr)
        return findMin(node->right); 

    Node* successor = nullptr; 
    while (root != nullptr) { 
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (node->data > root->data)
            root = root->right;
        else
            break;
    }
    return successor; 
} 

// (e) Inorder Predecessor of a given node
Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != nullptr)
        return findMax(node->left);

    Node* predecessor = nullptr; 
    while (root != nullptr) {  
        if (node->data > root->data) { 
            predecessor = root; 
            root = root->right; 
        }
        else if (node->data < root->data) 
            root = root->left;
        else
            break; 
    }
    return predecessor; 
}

// Inorder Traversal (for verification)
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    // (a) Search
    int key = 40;
    cout << "Recursive Search for " << key << ": "
         << (searchRecursive(root, key) ? "Found" : "Not Found") << endl;
    cout << "Iterative Search for " << key << ": "
         << (searchIterative(root, key) ? "Found" : "Not Found") << endl;

    // (b) Maximum element
    cout << "Maximum element: " << findMax(root)->data << endl;

    // (c) Minimum element
    cout << "Minimum element: " << findMin(root)->data << endl;

    // (d) Inorder Successor and (e) Predecessor
    Node* node = root->left; // node with value 30
    Node* successor = inorderSuccessor(root, node);
    Node* predecessor = inorderPredecessor(root, node);

    cout << "Inorder Successor of " << node->data << ": "
         << (successor ? to_string(successor->data) : "None") << endl;
    cout << "Inorder Predecessor of " << node->data << ": "
         << (predecessor ? to_string(predecessor->data) : "None") << endl;

    return 0;
}

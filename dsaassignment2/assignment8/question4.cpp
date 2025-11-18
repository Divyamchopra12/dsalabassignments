#include <bits/stdc++.h>
using namespace std;

// Define a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Helper function to check BST property
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;

    // Check if node violates min/max constraints
    if (root->data <= minVal || root->data >= maxVal)
        return false;

    // Recursively check left and right subtrees
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

// Main function
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Helper to build and test tree
int main() {
   

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    if (isBST(root))
        cout << "The given binary tree is a BST.";
    else
        cout << "The given binary tree is NOT a BST.";

    return 0;
}

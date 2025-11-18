#include <iostream>
#include <algorithm> 
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr; 
    } 
};


Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        cout << "Duplicate value " << val << " ignored." << endl; // no duplicates

    return root;
}

// Helper function to find minimum value node (used in deletion)
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

// (b) Delete a node
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        // Case 1: Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;  // copy inorder successor value
        root->right = deleteNode(root->right, temp->data); // delete successor
    }
    return root;
}

// (c) Maximum depth of BST
int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// (d) Minimum depth of BST
int minDepth(Node* root) {
    if (root == nullptr)
        return 0;

    // If one of the subtrees is empty, return depth of the other
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);

    // If both children exist
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Inorder Traversal (for checking)
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    // Insert nodes into BST
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

    // Delete some elements
    cout << "\nDeleting 20...\n";
    root = deleteNode(root, 20);
    cout << "After Deletion (Inorder): ";
    inorder(root);
    cout << endl;

    cout << "\nDeleting 30...\n";
    root = deleteNode(root, 30);
    cout << "After Deletion (Inorder): ";
    inorder(root);
    cout << endl;

    cout << "\nDeleting 50...\n";
    root = deleteNode(root, 50);
    cout << "After Deletion (Inorder): ";
    inorder(root);
    cout << endl;

    // Depth calculations
    cout << "\nMaximum Depth of BST: " << maxDepth(root) << endl;
    cout << "Minimum Depth of BST: " << minDepth(root) << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check sum of left leaves
int dfs(TreeNode* node) {
    if (node == NULL) return 0;

    int sum = 0;

    // Check if the left child is a leaf
    if (node->left != NULL &&
        node->left->left == NULL &&
        node->left->right == NULL) 
    {
        sum += node->left->val;
    }

    // Visit left and right subtrees
    sum += dfs(node->left);
    sum += dfs(node->right);

    return sum;
}

int sumOfLeftLeaves(TreeNode* root) {
    return dfs(root);
} 

int main() {
 

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int result = sumOfLeftLeaves(root);
    cout << "Sum of left leaves = " << result << endl;

    return 0;
}


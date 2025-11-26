#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to generate all BSTs with values between start and end
vector<TreeNode*> generate(int start, int end) {
    vector<TreeNode*> result;

    // Base case: if start > end, return list containing NULL
    if (start > end) {
        result.push_back(NULL);
        return result;
    }

    // Choose a root from start to end
    for (int i = start; i <= end; i++) {

        // Generate all possible left subtrees with numbers < i
        vector<TreeNode*> leftTrees = generate(start, i - 1);

        // Generate all possible right subtrees with numbers > i
        vector<TreeNode*> rightTrees = generate(i + 1, end);

        // Combine left and right trees with i as root
        for (auto left : leftTrees) {
            for (auto right : rightTrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generate(1, n);
}

// Helper function to print trees as level order arrays
void printTree(TreeNode* root) {
    if (!root) { 
        cout << "null"; 
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null ";
        }
    }
}

int main() {
    int n = 3;

    vector<TreeNode*> result = generateTrees(n);

    cout << "Total trees for n = " << n << " : " << result.size() << endl;

    int idx = 1;
    for (auto tree : result) {
        cout << "Tree " << idx++ << ": ";
        printTree(tree);
        cout << endl;
    }

    return 0;
}

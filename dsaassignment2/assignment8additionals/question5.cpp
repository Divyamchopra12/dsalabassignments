#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
    int data; 
    Node* left; 
    Node* right; 
    Node(int val) { 
        data = val; 
        left = right = NULL; 
    } 
}; 

Node* buildTreePreIn(vector<int>& preorder, vector<int>& inorder, 
                     int inStart, int inEnd, int &preIndex, unordered_map<int,int>& mp) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    int pos = mp[rootVal]; // find root in inorder

    root->left = buildTreePreIn(preorder, inorder, inStart, pos-1, preIndex, mp);
    root->right = buildTreePreIn(preorder, inorder, pos+1, inEnd, preIndex, mp);

    return root;
}

Node* buildTreeFromPreIn(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> mp;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;

    int preIndex = 0;
    return buildTreePreIn(preorder, inorder, 0, inorder.size()-1, preIndex, mp);
}

//PRINTING TREE IN LEVEL ORDER
void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n), inorder(n);

    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    Node* root = buildTreeFromPreIn(preorder, inorder);

    printLevelOrder(root);
    return 0;
}

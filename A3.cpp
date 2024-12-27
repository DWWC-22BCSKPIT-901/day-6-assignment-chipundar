#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int searchValue(vector<int>& in, int value, int s, int e) {
    
    for (int i=s; i<=e; i++) {
        if (in[i] == value)
            return i;
    }
    return -1;
}

Node* buildTreeRecur(vector<int>& in, vector<int>& pre, 
                     int &preIndex, int s, int e) {

    if (s > e) return nullptr;
    Node* root = new Node(pre[preIndex]);
    preIndex++;
    
    int index = searchValue(in, pre[preIndex-1], s, e);
    
    root->left = buildTreeRecur(in, pre, preIndex, s, index-1);
    root->right = buildTreeRecur(in, pre, preIndex, index+1, e);
    
    return root;
}

Node* buildTree(vector<int>& in, vector<int>& pre) {
    
      int n = pre.size();
    int preIndex = 0;
    Node* root = buildTreeRecur(in, pre, preIndex, 0, n-1);
    
    return root;
}
void printPostorder(Node* root) {
    if (root == nullptr)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}
                                  //medium
int main() {
    vector<int> in = {3, 1, 4, 0, 5, 2};
    vector<int> pre = {0, 1, 3, 4, 2, 5};
    Node* root = buildTree(in, pre);

    printPostorder(root);

    return 0;
}



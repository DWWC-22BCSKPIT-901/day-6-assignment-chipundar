#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int x) {
            data = x;
            left = nullptr;
            right = nullptr;
        }
};
vector<int> zigZagTraversal(Node* root) {
    
    vector<int> ans;

    if (root == nullptr)
        return ans;

    stack<Node*> currentLevel;
    stack<Node*> nextLevel;

    currentLevel.push(root);

    bool leftToRight = true;
    while (!currentLevel.empty()) {
        
        int size = currentLevel.size();
        
        while (size--) {
          
            struct Node* curr = currentLevel.top();
            currentLevel.pop();
    
            ans.push_back(curr->data);
    
            if (leftToRight) {
                if (curr->left)
                    nextLevel.push(curr->left);
                if (curr->right)
                    nextLevel.push(curr->right);
            }
            else {
                if (curr->right)
                    nextLevel.push(curr->right);
                if (curr->left)
                    nextLevel.push(curr->left);
            }
        }

        leftToRight = !leftToRight;
        swap(currentLevel, nextLevel);
    }
    
    return ans;
}
void printList(vector<int> v) {
    int n = v.size();
    for (int i=0; i<n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
                              //hard
int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->right->right = new Node(11);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    
    vector<int> ans = zigZagTraversal(root);
    printList(ans);

    return 0;
}




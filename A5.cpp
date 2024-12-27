#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dfs(int node, vector<vector<int>>& tree, string& s, int& maxPath) {
    int longest = 0, secondLongest = 0;

    for (int child : tree[node]) {
        int childPath = dfs(child, tree, s, maxPath);

        if (s[node] != s[child]) {
            if (childPath > longest) {
                secondLongest = longest;
                longest = childPath;
            } else if (childPath > secondLongest) {
                secondLongest = childPath;
            }
        }
    }
    maxPath = max(maxPath, longest + secondLongest + 1);
    return longest + 1;
}

int longestPath(vector<int>& parent, string s) {
    int n = parent.size();
    vector<vector<int>> tree(n);

    for (int i = 1; i < n; ++i) {
        tree[parent[i]].push_back(i);
    }

    int maxPath = 0;
    dfs(0, tree, s, maxPath);

    return maxPath;
}
int main() {
    vector<int> parent = {-1, 0, 0, 1, 1, 2};
    string s = "abacbe";

    cout << "Longest path length: " << longestPath(parent, s) << endl;

    return 0;
}
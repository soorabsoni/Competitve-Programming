#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    vector<TreeNode*> children;
    
    TreeNode(int data) : val(data) {}
};

int main() {
    TreeNode *node = new TreeNode(1);
    node->children.push_back(new TreeNode(2));
    return 1;
}

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        if(!root)return 0;
        if(root->left == nullptr && root->right==nullptr)return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
};
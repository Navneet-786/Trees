/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int  solve(Node* root, bool &ans){
        if(!root)return 0;
        
        int leftHeight = solve(root->left, ans);
        int rightHeight = solve(root->right, ans);
        
        if(abs(leftHeight - rightHeight)>1){
            ans  = false;
        }
        
        return  1 + max(leftHeight, rightHeight);
        
        
    }
  

    bool isBalanced(Node* root) {
        bool ans = true;
        solve(root,ans);
       return ans;
    }
};
/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirror(Node* root) {
        // code here
        if(!root)return;
        if(root->left==NULL && root->right==NULL)return;
        
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        if(root->left){
            mirror(root->left);
        }
        if(root->right){
            mirror(root->right);
        }
    }
};
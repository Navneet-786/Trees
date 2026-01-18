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
  void leftSubtree(Node* root, vector<int>&ans){
      if(!root)return;
      
      if(root->left==NULL && root->right==NULL)return;
      
      ans.push_back(root->data);
      
      
      if(root->left){
        leftSubtree(root->left, ans);
      }
      else{
         leftSubtree(root->right, ans);
      }
  }
  void leafNodePrint(Node* root, vector<int>&ans){
      if(!root)return;
      if(root->left==NULL && root->right==NULL){
          ans.push_back(root->data);
          
          return;
      }
      
      leafNodePrint(root->left, ans);
      leafNodePrint(root->right, ans);
  }
  
  void rightSubtree(Node* root, vector<int>&ans){
      if(!root)return;
      if(root->left==NULL && root->right==NULL)return;
      
      
      if(root->right){
          rightSubtree(root->right,ans);
      }
      else{
          rightSubtree(root->left, ans);
      }
       ans.push_back(root->data);
    
  }
 
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        ans.push_back(root->data);
        
        //left subtree ko traverse kro
        leftSubtree(root->left, ans);
        
        //leaf node ko print kro
        if(root->left || root->right){
            leafNodePrint(root, ans);
        }
      //right subtree ko print pro
      rightSubtree(root->right, ans);
      
      return ans;
    }
};
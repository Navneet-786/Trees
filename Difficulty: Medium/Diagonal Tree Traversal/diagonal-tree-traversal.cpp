/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  void solve(Node* root, int l, vector<int>arr[]){
      if(!root)return;
      
      arr[l].push_back(root->data);
      
      solve(root->left, l+1, arr);
      solve(root->right, l, arr);
  }
  void findLeftMost(Node* root, int l, int &lm){
      if(!root)return;
      
      lm = max(lm,l);
      
      findLeftMost(root->left,l+1,lm);
      findLeftMost(root->right, l, lm);
  }
 
    vector<int> diagonal(Node *root) {
        int l = 0;
        int lm = INT_MIN;
        findLeftMost(root, l, lm);
        
        vector<int>ans[lm+1];
        solve(root,0,ans);
        
        vector<int>vec;
        for(int i = 0;i< lm+1;i++){
            for(auto it:ans[i]){
                vec.push_back(it);
            }
        }
        
        return vec;
    }
};
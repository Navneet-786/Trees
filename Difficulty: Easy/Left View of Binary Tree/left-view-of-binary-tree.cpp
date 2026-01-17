/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  void solve(Node* root, int level, vector<int>&vec){
      
      if(!root)return;
      if(level == vec.size()){
          vec.push_back(root->data);
      }
      
      solve(root->left, level+1, vec);
      solve(root->right, level+1, vec);
  }
    vector<int> leftView(Node *root) {
      int level = 0;
      vector<int>ans;
      solve(root,level,ans);
      return ans;
    }
};
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
      if(!root)return ;
      
      if(level == vec.size()){
          vec.push_back(root->data);
      }
      
      solve(root->right, level+1, vec);
      solve(root->left, level+1, vec);
  }
    vector<int> rightView(Node *root) {
        //  code here
        vector<int>vec;
        solve(root, 0, vec);
        return vec;
    }
};
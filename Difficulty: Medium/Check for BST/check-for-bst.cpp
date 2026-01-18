/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  void inorder(Node* root, vector<int>&vec){
      stack<pair<Node*, int>>st;
      st.push({root,0});
      while(!st.empty()){
          Node* currNode = st.top().first;
          int count = st.top().second;
          
          st.pop();
          
          if(count==1){
              vec.push_back(currNode->data);
          }
          else{
              if(currNode->right){
                  st.push({currNode->right,0});
              }
              st.push({currNode,1});
              if(currNode->left){
                  st.push({currNode->left, 0});
              }
          }
          
      }
  }
    bool isBST(Node* root) {
        // code here
        vector<int>vec;
        inorder(root,vec);
        
        
        for(int i = 1;i<vec.size();i++){
            if(vec[i]< vec[i-1]){
                return false;
            }
        }
        return true;
    }
};
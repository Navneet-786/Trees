/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
       if(!root)return {};
       if(!root->left && !root->right)return {root->data};
       
       map<int,int>mpp;
       queue<pair<Node*,int>>q;
       q.push({root, 0});
       
       while(!q.empty()){
           int currSize = q.size();
           while(currSize--){
               auto [node, index] = q.front();
               q.pop();
               
               mpp[index] = node->data;
               
               if(node->left){
                   q.push({node->left, index-1});
               }
               if(node->right){
                   q.push({node->right, index+1});
               }
           }
       }
       vector<int>vec;
       for(auto it:mpp){
           vec.push_back(it.second);
       }
       
       return vec;
    }
};
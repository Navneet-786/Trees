/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void findExtreme(Node* root, int &leftMost, int &rightMost, int pos){
      if(!root)return;
      
      leftMost = min(pos, leftMost);
      rightMost = max(pos, rightMost);
      
      findExtreme(root->left, leftMost, rightMost, pos-1);
      findExtreme(root->right, leftMost, rightMost, pos+1);
  }
  void solve(Node* root,vector<int>negative[], vector<int>positive[], int pos){
     if(!root)return;
     queue<pair<Node*,int>>q; //{node, pos}
     q.push({root, pos});
     
     while(!q.empty()){
         Node* currNode = q.front().first;
         int currPos = q.front().second;
         
         q.pop();
         
         if(currPos < 0){
             //negative
             negative[abs(currPos)].push_back(currNode->data);
         }
         else{
             //positve
             positive[currPos].push_back(currNode->data);
         }
         
         if(currNode->left){
             q.push({currNode->left, currPos-1});
         }
         if(currNode->right){
             q.push({currNode->right, currPos+1});
         }
     }
  }
  
    vector<vector<int>> verticalOrder(Node *root) {
       
       int leftMost = 0, rightMost = 0;
       findExtreme(root, leftMost, rightMost, 0);
       
       vector<int>negative[abs(leftMost)+1];
       vector<int>positive[rightMost +1];
       
       solve(root, negative, positive, 0);
       
       vector<vector<int>>vec;
       
       for(int i = abs(leftMost);i>0;i--){
           vector<int>temp;
           for(auto it: negative[i]){
               temp.push_back(it);
           }
           vec.push_back(temp);
       }
       
       for(int i = 0;i<= rightMost;i++){
           vector<int>temp;
           for(auto it:positive[i]){
               temp.push_back(it);
           }
           vec.push_back(temp);
       }
       
       return vec;
        
    }
};
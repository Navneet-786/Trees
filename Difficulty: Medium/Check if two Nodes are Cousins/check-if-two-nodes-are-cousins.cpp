/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
 
    bool isCousins(Node* root, int a, int b) {
    if(!root)return false;
    if(!root->left  && !root->right)return false;
    
      queue<pair<Node*, int>>q;
      q.push({root, -1});
      int parentA = -1, parentB = -1;
      
      while(!q.empty()){
          int size = q.size();
          bool findFirst = false, findSecond = false;
          while(size--){
              Node* currNode = q.front().first;
              int parent = q.front().second;
              q.pop();
              
              if(currNode->data == a){
                  parentA = parent;
                  findFirst = true;
              }
              
              if(currNode->data == b){
                  parentB = parent;
                  findSecond = true;
              }
              
              if(currNode->left){
                  q.push({currNode->left, currNode->data});
              }
              if(currNode->right){
                  q.push({currNode->right, currNode->data});
              }
          }
          
          if((findFirst && !findSecond)||(!findFirst && findSecond))
            return false;
        
            if(findFirst && findSecond){
                if(parentA == parentB)return false;
                else return true;
            }
      }
      if(!parentA && !parentB)return false;
      return false;
      
    }
};
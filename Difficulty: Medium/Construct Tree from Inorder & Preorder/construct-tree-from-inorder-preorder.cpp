/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  int findPos(vector<int>&inorder, int start, int end, int &target){
      for(int i = 0;i<inorder.size();i++){
          if(inorder[i] == target){
              return i;
          }
      }
      return 0;
  }
  Node* createTree(vector<int> &inorder, vector<int> &preOrder,
        int start, int end, int &index){
            if(start > end)return nullptr;
            
            //create node
            Node* node = new Node(preOrder[index]);
            
            //find the pos of node in inorder
            int pos = findPos(inorder, start, end, preOrder[index]);
            index++;
            
            //call for left 
            node->left = createTree(inorder, preOrder, start, pos-1,index);
            //call for right
            node->right = createTree(inorder, preOrder, pos+1, end , index);
            
            return node;
        }
 
  
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
      //inorder -> LNR
      //preOrder->NLR
      int start = 0, end = inorder.size()-1;
      int index = 0;
      return createTree(inorder, preorder, start, end, index);
    }
};
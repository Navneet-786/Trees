/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
 int findPos(vector<int>&inorder, int start, int end, int &target){
     for(int i = 0;i<inorder.size();i++){
         if(target == inorder[i])return i;
     }
     return 0;
 }
 Node* createTree(vector<int> &inorder, vector<int> &postorder,
    int start, int end, int &index){
        if(start > end)return nullptr;
        
        Node* node =new Node(postorder[index]);
        int pos = findPos(inorder, start, end,postorder[index]);
        index--;
        node->right = createTree(inorder, postorder, pos+1, end,index);
        node->left = createTree(inorder, postorder, start, pos-1, index);
        return node;
    }
 
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
      int start = 0, end = inorder.size()-1;
      int index = postorder.size()-1;
      return createTree(inorder, postorder, start, end,index );
    }
};
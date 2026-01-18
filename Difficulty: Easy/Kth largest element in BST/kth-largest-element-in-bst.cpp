/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
  void solve(Node* root, int &ans, int &k){
    //   if(k==0|| !root)return;
      
    //   solve(root->right, ans, k);
    //   if(k==0)return;
    //   k--;
    //   ans = root->data;
    //   solve(root->left, ans, k);
    
    if(k==0){
        return;
    }
    if(!root)return;
    
    solve(root->right, ans, k);
    k--;
    if(k==0){
        ans = root->data;
        return;
    }
    
    solve(root->left, ans, k);
      
  }
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans = -1;
        solve(root, ans, k);
        return ans;
    }
};
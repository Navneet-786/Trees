// User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
void solve(Node* root, int &sum , int &k){
    if(k==0)return;
    if(!root)return;
    
    
    solve(root->left, sum,k);
    if(k==0)return;
    sum+=root->data;
    k--;
    
    solve(root->right, sum,k);
}

int sum(Node* root, int k) {

    // Your code here
    int ans = 0;
    solve(root,ans,k);
    return ans;
}

class Solution {
  public:
   
    vector<int> topView(Node *root) {
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
                
                if(!mpp.count(index)){
                    mpp[index] = node->data;
                }
                
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
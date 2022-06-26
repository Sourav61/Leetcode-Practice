/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void binaryPath(TreeNode* root, vector<string>& res, string ans){
        if(!root->left && !root->right){
            res.push_back(ans);
            return;
        }
        
        if(root->left)
            binaryPath(root->left, res, ans + "->" + to_string(root->left->val));
        if(root->right)
            binaryPath(root->right, res, ans + "->" + to_string(root->right->val));
    };
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root)
            return res;
        
        binaryPath(root,res,to_string(root->val));
        return res;
    };
};
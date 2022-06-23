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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string a, b;
        DFS(root1, a);
        DFS(root2, b);
        return a==b;
    }
    
    void DFS(TreeNode* root, string& s) {
        if(root==NULL) 
            return;
        if(root->left==NULL && root->right==NULL) 
            s+=to_string(root->val)+"#";
        DFS(root->left, s);
        DFS(root->right, s);
    }
};
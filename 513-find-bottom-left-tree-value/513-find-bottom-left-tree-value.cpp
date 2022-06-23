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
    int maxlevel = 0;
    void find(TreeNode* root, int level,int &res){
        if(root == NULL)
            return;

        if(root->left == NULL && root->right == NULL){
            // cout<<level<<" "<<maxlevel<<" "<<root->val<<endl;
            if(level > maxlevel)
                res = root->val;
                maxlevel = max(maxlevel, level);
            level = 0;
        }

        if(root->left)
            find(root->left, level+1,res);
        if(root->right)
            find(root->right, level+1,res);
    }

    int findBottomLeftValue(TreeNode* root) {
        if(!root->left and !root->right)
            return root->val;
        int res = 0;
        int level = 0;
        find(root, level,res);
        return res;
    }
};
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
    bool balance(TreeNode* root, int *height){
        if(root == NULL){
            return true;
        }

        int lh=0, rh=0;

        if(balance(root->left, &lh) == false){
            return false;
        }

        if(balance(root->right, &rh) == false){
            return false;
        }

        *height = max(lh,rh) + 1;

        if(abs(lh-rh) <= 1){
            return true;
        }else{
            return false;
        }
    }
    
    bool isBalanced(TreeNode *root)
    {
        int height = 0;
        bool res = balance(root, &height);

        return res;
    }
};
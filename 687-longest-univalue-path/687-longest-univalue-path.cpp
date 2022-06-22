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
     int longestUnivaluePath(TreeNode* root) {
        int maxi = 0;
        if(root)
            maxCount(root, maxi);
        return maxi;
    }
    
    int maxCount(TreeNode* node, int& maxi){
        int l = node->left ? maxCount(node->left, maxi) : 0;
        int r = node->right ? maxCount(node->right, maxi) : 0;

        int resl = node->left && node->left->val == node->val ? l + 1 : 0;
        int resr = node->right && node->right->val == node->val ? r + 1 : 0;

        maxi = max(maxi, resl + resr);

        return max(resl, resr);
    }
};
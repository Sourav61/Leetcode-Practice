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
    int minDepth(TreeNode* root) {
//         if(root == NULL){
//             return 0;
//         }

//         int lHeight = minDepth(root->left);
//         int rHeight = minDepth(root->right);

//         if(lHeight==0 || rHeight==0){
//             return max(lHeight, rHeight) + 1;
//         }
        
//         return min(lHeight, rHeight) + 1;
        
        if (!root) return 0;
        int L = minDepth(root->left);
        int R = minDepth(root->right);
        return 1 + (min(L, R) ? min(L, R) : max(L, R));

    }
};
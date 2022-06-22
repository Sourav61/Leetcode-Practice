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
    int sumNumbers(TreeNode* root) {
        string sum = to_string(root->val);
        int ans = 0;
        sumNum(root, sum, ans);
        return ans;
    }

    void sumNum(TreeNode* root, string sum, int &ans){
        if(root->left == NULL && root->right == NULL){
            ans+=stoi(sum);
            return;
        }
        
        if(root->left != NULL)
            sumNum(root->left, sum+to_string(root->left->val),ans);
        if(root->right != NULL)
            sumNum(root->right, sum+to_string(root->right->val),ans);
    }
};
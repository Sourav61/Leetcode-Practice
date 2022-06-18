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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> ans;
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node != NULL){
                ans.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }else{
                res.push_back(ans);
                if(q.size()>0)
                    q.push(NULL);
                ans.clear();
            }
        }

        return res;
    }
};
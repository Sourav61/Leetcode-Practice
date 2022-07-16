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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;

        if(root == NULL)
            return res;

        queue<TreeNode*> q;
        
        q.push(root);
        q.push(NULL);

        vector<int> ans;
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr != NULL){
                ans.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }else{
                res.push_back(ans);
                if(q.size() > 0)
                    q.push(NULL);
                ans.clear();
            }
        }

        reverse(res.begin(),res.end());
        
        return res;
    }
};
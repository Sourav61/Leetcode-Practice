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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;

        if(root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        double sum = 0, cnt = 0;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr != NULL){
                sum += curr->val;
                cnt++;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }else{
                if(cnt == 0)
                    res.push_back(sum);
                else
                    res.push_back(double(sum)/double(cnt));
                if(q.size() > 0)
                    q.push(NULL);
                sum = 0;
                cnt = 0;
            }
        }

        return res;
    }
};
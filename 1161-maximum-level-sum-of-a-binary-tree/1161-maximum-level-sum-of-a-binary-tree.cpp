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
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> q{root};
        int level = 0, maxLevel = 0, maxSum = INT_MIN;
        while (!q.empty()) {
            vector<TreeNode*> q1;
            int sum = 0;
            ++level;
            for (auto n : q) {
                sum += n->val;
                if (n->left) 
                    q1.push_back(n->left);
                if (n->right) 
                    q1.push_back(n->right);
            }
            maxLevel = sum > maxSum ? level : maxLevel;
            maxSum = max(sum, maxSum);
            swap(q, q1);
        }
        return maxLevel;
    }
};
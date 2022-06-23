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
   vector<vector<int>> verticalTraversal(TreeNode* root){
        map<int, map<int, multiset<int>>> nodes;
        traverse(root, 0,0, nodes);

        vector<vector<int>> res;

        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second)
                col.insert(col.end(), q.second.begin(), q.second.end());

            res.push_back(col);
        }
        return res;
    }

    void traverse(TreeNode* root, int x ,int y, map<int, map<int, multiset<int>>> &nodes){
        if(root){
            nodes[x][y].insert(root->val);
            traverse(root->left, x-1, y+1, nodes);
            traverse(root->right, x+1, y+1, nodes);
        }
    }
};
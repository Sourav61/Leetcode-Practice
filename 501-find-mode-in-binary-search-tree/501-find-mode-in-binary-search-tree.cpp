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
    int max_count = INT_MIN;
    int curr_count = 0;
    TreeNode* prev = NULL;
    vector<int> ans;

    void inorder(TreeNode* root, bool getlist){
        if(!root)
            return;

        inorder(root->left, getlist);
        if(prev)
            cout<<prev->val;
        cout<<" "<<root->val<<endl;

        if(prev && prev->val == root->val)
            curr_count++;
        else
            curr_count = 1;

        if(!getlist)
            max_count = max(max_count, curr_count);
        else if(curr_count == max_count)
            ans.push_back(root->val);

        prev = root;
        inorder(root->right, getlist);
    }

    vector<int> findMode(TreeNode* root) {
        if(!root)
            return ans;

        inorder(root, false);

        prev = NULL;
        curr_count = 0;
        inorder(root, true);

        return ans;
    }
};
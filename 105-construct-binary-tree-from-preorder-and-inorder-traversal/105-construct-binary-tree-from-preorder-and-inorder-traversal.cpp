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
public:TreeNode* Tree(vector<int> &preorder, vector<int> &inorder, int &idx,int start, int n)
    {
        if(start > n){
            return NULL;
        }
        int pos = start;

        while(inorder[pos] != preorder[idx]){
            pos++;
        }

        idx++;
        TreeNode* node = new TreeNode(inorder[pos]);    
        if(start == n){
            return node;
        }

        node->left = Tree(preorder,inorder,idx, start,pos-1);
        node->right = Tree(preorder, inorder,idx, pos+1,n);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        TreeNode* ans = Tree(preorder, inorder, idx, 0, inorder.size()-1);

        return ans;
    }
};
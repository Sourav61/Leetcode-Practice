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
    TreeNode* Tree(vector<int>& inorder,vector<int>& postorder,int start,int end,int& postIdx){
        if(postIdx < 0){
            return NULL;
        }
        int pos = start;
        
        if(start > end){
            return NULL;
        }

        int curr = postorder[postIdx];
        postIdx--;
        TreeNode* node = new TreeNode(curr);

        while(inorder[pos] != curr){
            pos++;
        }

        node->right = Tree(inorder,postorder,pos+1,end,postIdx);
        node->left = Tree(inorder,postorder,start,pos-1,postIdx);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postIdx = n-1;
        TreeNode* res = Tree(inorder,postorder,0,n-1,postIdx);

        return res;
    }
};
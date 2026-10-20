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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root = build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
    TreeNode* build(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int inorderstart,int inorderend,map<int,int>&mpp){
        if(prestart>preend ||inorderstart>inorderend)return nullptr;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inorderroot = mpp[root->val];
        int numsleft = inorderroot - inorderstart;
        root->left = build(preorder,prestart+1,prestart+numsleft,inorder,inorderstart,inorderroot-1,mpp);
        root->right = build(preorder,prestart+numsleft+1,preend,inorder,inorderroot+1,inorderend,mpp);
        return root;
    }
};

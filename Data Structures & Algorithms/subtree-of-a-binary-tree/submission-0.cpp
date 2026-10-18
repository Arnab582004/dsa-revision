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
    bool isSametree(TreeNode* root , TreeNode* subRoot){
        //if(root==nullptr && subRoot==nullptr)return true;
        if(root==nullptr && subRoot==nullptr)return true;
        //if(root->val == subRoot->val)return true;
        if(root && subRoot && root->val ==subRoot->val){
            return isSametree(root->left,subRoot->left) && isSametree(root->right,subRoot->right);
        }
        
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr)return true;
        if(root==nullptr)return false;
        if(isSametree(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};

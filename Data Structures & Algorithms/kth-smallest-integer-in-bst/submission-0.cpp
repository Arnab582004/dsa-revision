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
    vector<int>traversal(TreeNode* root){
        vector<int>result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        return result;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        ans=traversal(root);
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int num:ans){
            pq.push(num);
        }
         for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }
        return pq.top();
    }
};

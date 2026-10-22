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

class Codec {
    void serializeHelper(TreeNode* root , string&data){
        if(root==nullptr){
            data+="#,";
            return;
        }
        data+=to_string(root->val)+',';
        serializeHelper(root->left,data);
        serializeHelper(root->right,data);
    }
    TreeNode* deserializehelper(vector<string>&tokens,int &index){
        if(tokens[index]=="#"){
            index++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(tokens[index++]));
        //index++;
        root->left = deserializehelper(tokens,index);
        root->right = deserializehelper(tokens,index);
        return root;

    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string data;
       serializeHelper(root,data);
       return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>tokens;
        string token;
        stringstream ss(data);
        while(getline(ss,token,',')){
            tokens.push_back(token);
        }
        int index=0;
        return deserializehelper(tokens,index);
    }
};

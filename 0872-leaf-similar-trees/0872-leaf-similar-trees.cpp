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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string r1,r2;
        DFS(root1,r1);
        DFS(root2,r2);
        if(r1==r2)
            return true;
        else return false;
    }
    void DFS(TreeNode* root, string &s)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
            s+=to_string(root->val)+" ";
        DFS(root->left,s);
        DFS(root->right,s);
        
    }
};

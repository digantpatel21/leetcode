/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<int>> path;
    vector<int> pathVector;
public:
    void dfsr(TreeNode* root, int prefixSum, int targetSum, vector<int> pathVector)
    {
        if(!root)
        {
            pathVector.clear();
            return;
        }
        
        pathVector.push_back(root->val);
        if(!root->left && !root->right && (root->val+prefixSum)== targetSum)
        {
            path.push_back(pathVector);
        }
        
        dfsr(root->left, root->val+prefixSum, targetSum, pathVector);
        dfsr(root->right, root->val+prefixSum, targetSum, pathVector);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfsr(root, 0, sum, pathVector);
        
        return path;
    }
};
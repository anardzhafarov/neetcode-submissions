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
    optional<int> help(TreeNode* root, int k, int& curr){
        if(root == nullptr){
            return nullopt;
        }
        
        optional<int> left = help(root->left, k, curr);
        if (left)
            return left.value();
        
        curr += 1;
        if (curr == k)
            return root->val;
        
        optional<int> right= help(root->right, k, curr);
        return right;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int curr = 0;
        return help(root, k, curr).value();
    }
};

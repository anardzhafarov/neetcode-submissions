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
    bool help(TreeNode* root, int lower_bound, int upper_bound){
        if (root->left == nullptr && root->right == nullptr){
            return root->val > lower_bound && root->val < upper_bound;
        }
        else if (root->left == nullptr && root->right != nullptr){
            if(root->right->val > root->val && root->val > lower_bound && root->val < upper_bound)
                return help(root->right, root->val, upper_bound);
            else 
                return false;
        } else if (root->right == nullptr && root->left != nullptr){
            if(root->left->val < root->val && root->val < upper_bound && root->val > lower_bound)
                return help(root->left, lower_bound, root->val);
            else 
                return false;
        } else
            if(root->val > lower_bound && root->val < upper_bound)
                return help(root->left, lower_bound, root->val) && help(root->right, root->val, upper_bound);
            else
                return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return help(root, INT_MIN, INT_MAX) && help(root, INT_MIN, INT_MAX);
    }
};

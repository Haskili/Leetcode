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

bool isPath(TreeNode* node, int target) {

    // Base Case: Return false if node doesn't exist
    if (node == nullptr)
        return false;

    // Base Case: Return expression evaluation of asking
    //            whether this leaf-node has the last value
    //            required to reach the 'target' amount
    if (node->left == nullptr && node->right == nullptr)
        return (node->val == target);

    // Return conditionally after children's evaluation;
    // e.g. if either are true then return true
    return (isPath(node->left, target - node->val) 
        || isPath(node->right, target - node->val))? true : false;

}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        return isPath(root, target);
    }
};
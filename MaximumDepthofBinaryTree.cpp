/*
    The following is a simple recursive solution to find
    the maximum depth. It is worth noting that I was able
    to repurpose the original function 'maxDepth' by altering
    the arguments list to include a 'depth' argument with a default
    value of '0' that gets incremented with each recursive call.

    Runtime: 3ms (Beats 93.07% of users with C++)
    Memory: 17.46mb (Beats 44.70% of users with C++)
*/
class Solution {
public:
    int maxDepth(TreeNode* root, int depth = 0) {
        if (!root)
            return depth;

        return max(maxDepth(root->left, depth + 1), 
                    maxDepth(root->right, depth + 1));
    }
};

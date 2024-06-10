/*
    The following is simple recursive solution that utilizes a 'current' vector
    over the course of the iteration through the tree. At any point, if we find
    that the 'target' value is satisfied, we push back the state of 'current'
    into 'answer'.

    Runtime: 4ms (Beats 89.87% of users with C++)
    Memory: 18.58mb (Beats 98.97% of users with C++)
*/
void search(TreeNode* node, int target, vector<int>& current, vector<vector<int>>& answer) {

    // Handle basecases of no current node,
    // overshooting the target, etc.
    if (!node)
        return;

    // Push the current node's value to 'current'
    current.push_back(node->val);

    // If no left and right children,
    // we're at a leaf node; Check to
    // see if we need to push current
    // path to 'answer'
    if (!node->left && !node->right) {
        if (target - node->val == 0)
            answer.push_back(current);
    }

    // If we're not at a leaf node,
    // search left and right
    else {
        search(node->left, (target - node->val), current, answer);
        search(node->right, (target - node->val), current, answer);
    }

    // Take off the current node from 'current'
    current.pop_back();
}

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer;
        vector<int> current;
        search(root, targetSum, current, answer);
        return answer;
    }
};

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
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Define a lambda function for depth-first search
        // Note: The return type should be bool, not int
        function<bool(TreeNode*, int)> dfs = [&](TreeNode* node, int currentSum) -> bool {
            // Base case: if node is null, no path exists
            if (!node) {
                return false;
            }
          
            // Add current node's value to the running sum
            currentSum += node->val;
          
            // Check if we've reached a leaf node with the target sum
            if (!node->left && !node->right && currentSum == targetSum) {
                return true;
            }
          
            // Recursively check left and right subtrees
            // Return true if either subtree has a valid path
            return dfs(node->left, currentSum) || dfs(node->right, currentSum);
        };
      
        // Start DFS from root with initial sum of 0
        return dfs(root, 0);
    }
};

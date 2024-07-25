/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 /*
Time complexity:o(n)
Space complexity:o(n)
 *?
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        TreeNode* current = root;
        while(current != NULL || !stack.empty()){
            // Reach the left most Node of the current Node
            while (current != NULL) {
                stack.push(current);  // place pointer to a tree node on the stack before traversing the node's left subtree
                current = current->left;
            }
             // Current must be NULL at this point
            current = stack.top();
            stack.pop();
            result.push_back(current->val);  // Add the node value to result
            // We have visited the node and its left subtree. Now, it's right subtree's turn
            current = current->right;
        }
        return result;
    }
};

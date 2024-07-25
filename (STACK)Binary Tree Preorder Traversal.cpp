/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

 
Time complexity: o(n)
Space complexity: o(n)
 
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            result.push_back(node->val);
                  if (node->right != NULL) {
                stack.push(node->right);
            }
            // Since the stack is LIFO, if you push the left child onto the stack first and then the right child, 
            // the right child would be the first to be popped off and processed.
            //  This would lead to visiting the right subtree before the left subtree,
            //   which is not the desired order for preorder traversal.  that is why we pushing right first 
            if (node->left != NULL) {
                stack.push(node->left);
            }
            
        }

        return result;
    }
};

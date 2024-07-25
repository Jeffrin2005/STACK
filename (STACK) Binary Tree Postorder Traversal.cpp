/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;


 
 Time complexity:o(n)
Space complexity:o(n)


 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        if (root==NULL) return result;
        stack<TreeNode*> stack;
        TreeNode* lastVisited = NULL;
        while (!stack.empty() || root != NULL){
            if (root != NULL) {
                stack.push(root);
                root = root->left;
            } else {
                TreeNode* peekNode = stack.top();// current top node 
                // If right child exists and traversing node from left child, then move right
                if (peekNode->right != NULL && lastVisited != peekNode->right){
                    root = peekNode->right;
                }
                // (lastvisited = NULL , Peek->right = NULL , so find the last root so pushing into result ) 
                else{
                    stack.pop();
                    result.push_back(peekNode->val);
                    lastVisited = peekNode;
                }
            }
        }

        return result;
    }
};

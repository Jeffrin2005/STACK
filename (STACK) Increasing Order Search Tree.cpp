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
Time complexity:o(n)
Space complexity:o(h)
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root==NULL) return NULL;
        stack<TreeNode*> stk;
        TreeNode* current = root;
        TreeNode* newRoot = NULL;
        TreeNode* prev = NULL;
       
        while (!stk.empty() || current != NULL){
            while(current != NULL){// pushing 5 4 3 2 1 into stack 
                stk.push(current);
                current = current->left;
            }
            // current == null 
            current = stk.top();
            stk.pop();

          // from here going to make in-order 
            if(newRoot == NULL){
                newRoot = current; // The first node in in-order becomes the new root
                prev = newRoot;
            }else{
                // going above 
                prev->right = current;
                prev = current;
            }
            current->left = NULL; // Ensure no left child
            current = current->right;// going to the right child
        }

        return newRoot;
    }
};

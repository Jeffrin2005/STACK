// TIME COMP = o(n) , SPACE COMP =O(n)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
         stack<TreeNode*>stk;
        for(auto&num : nums){
            TreeNode* curr = new TreeNode(num);
            /*
While the stack is not empty and the value at the top of the stack is less than the current number, 
pop the stack and set the popped node as the left child of the current node.
 This step ensures that the last smaller node (if any) becomes the left child of the current node, 
which is the next greater node.
            */
            while(!stk.empty() && stk.top()->val < num){ 
                curr->left = stk.top();
                stk.pop();
            }
            /* [3, 2, 1, 6, 0, 5]
Push 3: Stack = [3]
Push 2: Stack = [3, 2] (since 2 < 3)
3. Push 1: Stack = [3, 2, 1] (since 1 < 2)
4. Process 6:
Pop 1, set as left child of 6
Pop 2, set as left child of 3
Pop 3, set as left child of 6
Push 6: Stack = [6]
5. Push 0: Stack = [6, 0] (since 0 < 6)
6. Process 5:
Pop 0, set as left child of 5
Push 5: Stack = [6, 5] (since 5 < 6)
            */
            if (!stk.empty()) {
                stk.top()->right = curr;
            }
            stk.push(curr);
        }
// find the root node 
        TreeNode* root = NULL;
        while (!stk.empty()){
            root = stk.top();
            stk.pop();
        }
        return root;
    }
};

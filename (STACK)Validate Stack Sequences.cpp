
/*
Time complexity:o(n)
Space complexity:o(n)
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
     stack<int> stack;
        int j = 0; // Index for popped array
        for (int num : pushed) {
            stack.push(num); // Push the current number onto the stack
            // Check if the current top of the stack matches the current element in popped
            while (!stack.empty() && stack.top() == popped[j]) {
                stack.pop(); // Pop from stack if it matches
                j++; // Move to the next element in popped
            }
        }

        return stack.empty(); // If stack is empty, all elements were matched correctly
    }
};

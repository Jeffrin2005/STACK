class Solution {
public:
// time comp = O(n) space comp = O(n)
    int minLength(string s) {
     stack<char> stack;
    for(auto&c : s){
        if(!stack.empty() && ((stack.top() == 'A' && c == 'B') || (stack.top() == 'C' && c == 'D'))) {
            stack.pop(); // Remove the top element if it forms "AB" or "CD" with c
        }else{
            stack.push(c); // Otherwise, push the current character onto the stack
        }
    }
    return stack.size(); // The size of the stack is the length of the reduced string
    }
};

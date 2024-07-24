class Solution {
public:
// time comp = o(n) space comp = O(n)
    string removeDuplicates(string s) {
       stack<char>stk;
        for(auto&c : s){
            if(!stk.empty() && stk.top() == c) {
                stk.pop(); // Remove the top element if it's the same as the current character
            }else{
                stk.push(c); // Push the current character onto the stack
            }
        }
        // Reconstruct the string from the stack
        string result = "";
        while(!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};

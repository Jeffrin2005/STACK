#define ll long long 
class Solution {
public:
/*
Time complexity:o(n)
Space complexity:o(n)
*/
    string makeGood(string s) {
        stack<char> stk;
        for(auto&c : s){
// stk.top() == c + 32: This checks if the character at the top of the stack is the uppercase version of the current lowercase character c.
//stk.top() == c - 32: This checks if the character at the top of the stack is the lowercase version of the current uppercase character c
            if(!stk.empty() && ((stk.top() == c + 32) || (stk.top() == c - 32))) {
                stk.pop(); // Remove the last character if it forms a bad pair with current
            } else {
                stk.push(c); // Push current character to stack if no bad pair is formed
            }
        }
        // cout << stk.size();
        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result; 
            stk.pop();
        }
        
        return result;
    }
};

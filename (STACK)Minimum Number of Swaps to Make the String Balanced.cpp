
/*
Time complexity:o(n)
Space complexity:o(n)
  */
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(auto&c : s){
            if(c == '['){
                // Push opening brackets onto the stack
                st.push(c);
            }else{ // c == ']'
                if(!st.empty() && st.top() == '[') {
                    // If there's a matching opening bracket on the stack, pop it
                    st.pop();
                }else{
                    // Otherwise, push the closing bracket onto the stack
                    st.push(c);
                }
            }
        }
        // The stack now contains unmatched brackets
        // Half of the stack size (rounded up) will be the number of swaps needed
        int unmatched = st.size();
        return (unmatched / 2 + 1) / 2;
    }
};

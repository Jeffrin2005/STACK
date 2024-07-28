#include <bits/stdc++.h>
#define ll long long 
#define nl '\n'
class Solution {
public:
// time comp = o(n) space comp = o(n)
    bool isValid(string s){
        stack<char>st;
        for(auto&c : s){
            if(c == 'c'){
                // Check if the top of the stack has 'b' and 'a' before 'c'
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a'){
                        st.pop();
                    }else{
                        // If 'a' is not before 'b', push 'b' back and add 'c'
                        st.push('b');
                        st.push(c);
                    }
                }else{
                    // If 'b' is not on top, just push 'c'
                    st.push(c);
                }
            }else{
                // Push 'a' or 'b' onto the stack
                st.push(c);
            }
        }
        // cout << st.size() << nl;
        // If the stack is empty, all characters formed valid "abc" sequences
        return st.empty();
    }
};

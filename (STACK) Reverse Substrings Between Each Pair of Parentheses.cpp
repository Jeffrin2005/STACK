class Solution {
public:
/*
Time complexity:O(n)
Space complexity:o(n)
*/
    void reverseString(string &s, int i, int j){
        while(i < j){
            if(s[i] == '(') i++;
            if(s[j] == ')') j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string reverseParentheses(string s){
        stack<int>st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(') st.push(i);
            if(s[i] == ')'){
                reverseString(s, st.top(), i);
                st.pop();
            }
        }

        string ans;
        for(auto&ch : s) if(isalpha(ch)) ans +=ch;
        return ans;
    }
};

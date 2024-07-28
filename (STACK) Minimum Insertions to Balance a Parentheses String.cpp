class Solution {
public:
// time comp = o(n) space comp = o(n)
    int minInsertions(string s){
        int insertions = 0;
       stack<char> stk;
        for (int i = 0; i < s.size();i++){
            if(s[i] == '('){
                stk.push(s[i]);
            }else{// s[i] = ) , s[i+1] = )
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    // Found a pair "))"
                    if (!stk.empty()){
                        stk.pop(); // match found, pop the '('
                    }else{
                        insertions++; // need an extra '(' before this pair
                    }
                    i++; // skip the next ')'
                }else{
                    // Found a single ')', need one more to balance
                    if (!stk.empty()) {
                        stk.pop(); // use one of the open '('
                        insertions++; // insert one more ')' to make a pair
                    }else{
                        insertions += 2; // insert '(' at the beginning and ')' to make it a pair
                    }
                }
            }
        }
        // If there are any unmatched '(' left, each needs two ')' to be balanced
        while (!stk.empty()){
            stk.pop();
            insertions += 2;
        }
        return insertions;
    }
};

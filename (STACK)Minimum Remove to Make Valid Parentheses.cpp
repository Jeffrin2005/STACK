
/*
Time complexity:O(n)
Space complexity:o(n)
  */
class Solution {
public:
    string minRemoveToMakeValid(string s){
       stack<int> stk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                stk.push(i);
            }else if (s[i] == ')'){
                if(!stk.empty() && s[stk.top()] == '('){
                    stk.pop();
                }else{
                    stk.push(i);
                }
            }
        }

        // To remove all indices we have in the stack
        while (!stk.empty()) {
            s.erase(stk.top(), 1);
            stk.pop();
        }

        return s;
    }
};

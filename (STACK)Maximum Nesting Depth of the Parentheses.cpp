// time comp = o(n) space comp = o(n)
class Solution {
public:
    int maxDepth(string s) {
        stack<char>stack;
        int currentDepth = 0;
        int maxDepth = 0;
        for(auto&c : s){
            if(c == '('){
                stack.push(c);
                currentDepth++;
                maxDepth = max(maxDepth, currentDepth);
            }else if(c == ')'){
               
                    stack.pop();
                    currentDepth--;
                
            }
        }
        return maxDepth;
    }
};

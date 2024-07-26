class Solution {
public:
/*
Time complexity:O(N)
Space complexity:O(N)
*/
    string removeStars(string s) {
        stack<char> stk;
        for(auto&c : s){
            if(c == '*'){
                if(!stk.empty()){// remvoing the left character 
                    stk.pop();  // Remove the closest non-star character
                }
            }else{
                stk.push(c);  // Push non-star characters onto the stack
            }
        }
        string result;
        while(!stk.empty()){
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());  // The result needs to be reversed
        return result;
    }
};

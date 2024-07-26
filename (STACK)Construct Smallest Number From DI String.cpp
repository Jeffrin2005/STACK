

class Solution {
/*
Time complexity:o(N)
Space complexity:o(N)
*/
public:
   string smallestNumber(string pattern) {
       string result;
       stack<int> stk;
        // Dry run explanation for pattern "IIIDIDDD":
        // i=0, 'I': stack = [1], -> result = "1"
        // i=1, 'I': stack = [2], -> result = "12"
        // i=2, 'I': stack = [3],  -> result = "123".. till here we poped the elements 
        // i=3, 'D': stack = [4, 5], continue
        // i=4, 'I': stack = [4, 5, 6], pop all -> result = "123654"
        // i=5, 'D': stack = [7, 8], continue
        // i=6, 'D': stack = [7, 8, 9], continue
        // i=7, 'D': stack = [7, 8, 9], continue
        // End:  -> result = "123654987"
        
        int n = pattern.size();
        for(int i = 0; i <= n; i++){
            // Push the current index + 1 to stack
            stk.push(i + 1);
            // i==patter.size() 
          //  In the case of the pattern "DDD", the loop iterates from i = 0 to i = 4 to accommodate the final processing of the stack. At i = 4, which is beyond the pattern's length, 
           // the condition i == pattern.size() leading to the complete emptying of the stack.
           // This results in appending the numbers in reverse order to the result, producing the sequence "4321".(bcoz DDD decresing format)
            if(i == pattern.size() || pattern[i] == 'I'){
                // Pop all elements from the stack and add to result
                while(!stk.empty()){
                    result+='0' +stk.top();
                    stk.pop();
                }
            }
        }

        return result;
    }
};

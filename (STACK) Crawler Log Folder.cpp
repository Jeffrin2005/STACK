

class Solution {
public:
/*
Time complexity:O(N)
Space complexity:o(N)
*/
    int minOperations(vector<string>& logs){
       stack<string>folderStack;
        for(auto&log : logs){
            if(log == "../") {
                if (!folderStack.empty()) {
                    folderStack.pop();
                }
            } else if (log == "./") {
                // Do nothing
            }else{
                folderStack.push(log);
            }
        }
        return folderStack.size(); // The size of the stack is the number of operations needed to return to the main folder
    }
};

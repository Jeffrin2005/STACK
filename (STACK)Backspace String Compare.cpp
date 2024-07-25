class Solution {
    private:
// time comp = O(n+m) space comp = o(max(n,m))
    string processString( string& str){
        stack<char>editor;
        for(auto&c : str){
            if(c != '#'){
                editor.push(c);
            }else if (!editor.empty()){// c=='#' so we are removing the letter bcoz backspace
                editor.pop();
            }
        }
        string result;
        while(!editor.empty()){
            result += editor.top();
            editor.pop();
        }
        reverse(result.begin(), result.end()); // Reverse the result string
        return result;
    }
public:
    bool backspaceCompare(string s, string t) {
        return processString(s) == processString(t);
    }
};

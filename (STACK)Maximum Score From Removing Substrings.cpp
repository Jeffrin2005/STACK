
class Solution {
public:
/*
Time complexity:O(n)
Space complexity:O(n)
*/
    int process(string &s, char first, char second, int points){
      stack<char> stk;
        int score = 0;
        for(auto&c : s){
            if(!stk.empty() && stk.top() == first && c == second){
                // Remove the pair and add points
                stk.pop();
                score+=points;
            }else{
                stk.push(c);
            }
        }
        s.clear();
        while(!stk.empty()){
            s.push_back(stk.top());
            stk.pop();
        }
       reverse(s.begin(), s.end());// if we are starting with 'a b' we need to find out for 'b a' so reverse it for the next iteration
        return score;
    }

    int maximumGain(string s, int x, int y){
        int totalScore = 0;
        if (x >= y) {
            totalScore+=process(s, 'a', 'b', x);
            totalScore+=process(s, 'b', 'a', y);
        }else{
            totalScore+=process(s, 'b', 'a', y);
            totalScore+=process(s, 'a', 'b', x);
        }
        return totalScore;
    }
};


class Solution {
public:
// Time complexity:o(n)
//Space complexity:o(n)
    int calPoints(vector<string>& ops){
       stack<int> scores;
        for(auto&op : ops){
            if (op == "+"){
                //  a new score that is the sum of the previous two scores
               int top = scores.top();  // Get the top element of the stack
             scores.pop();     // Remove the top element
             int newTop = top + scores.top();  // Sum the new top (after pop) with the old top
             scores.push(top);        // Push the previous top back onto the stack
             scores.push(newTop);     // Push the new score (sum of the top two previous scores)
            }else if (op == "D"){
                // Record a new score that is double the previous score
                scores.push(2 * scores.top());
            }else if (op == "C"){
                // Invalidate the previous score, removing it from the record
                scores.pop();
            }else{// numbers 5, 4.. 
                // Record a new score of x (convert string to integer)
                scores.push(std::stoi(op));
            }
        }
        int sum = 0;
        while(!scores.empty()){
            sum += scores.top();
            // cout << sum <<"\n"; return;
            scores.pop();
        }
        return sum;
    }
};

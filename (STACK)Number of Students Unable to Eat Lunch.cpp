
class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
       stack<int>sandwichStack;
        // Fill the stack with sandwiches, the last sandwich on top
        for(int i = sandwiches.size()-1; i>=0;i--){
            sandwichStack.push(sandwiches[i]);
        }
// time comp = O(n) space comp = o(n)
        int count = 0;
        while(!students.empty()){
            if(students.front() == sandwichStack.top()){ 
                // The student takes the sandwich and leaves
                sandwichStack.pop();
                students.erase(students.begin());
                count = 0; // Reset the count since a student took a sandwich
            }else{
                // Move the student to the end of the queue
                students.push_back(students.front());
                students.erase(students.begin());
                count++;
                if(count == students.size()){
                   // Example of count == students.size()
// students = [1, 1, 1]
// sandwiches = [0, 0, 0]
// Process:
// All students prefer 1, but the top sandwich is 0.
// Each student cycles through without taking a sandwich, incrementing count each time.
// When count reaches 3 (the size of students), the loop breaks, indicating a deadlock.
                    break;
                }
            }
        }

        return students.size(); // Remaining students who can't get their preferred sandwich
    }
};

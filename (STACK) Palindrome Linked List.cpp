
class Solution {
public:
/*
Time complexity:o(n)
Space complexity:o(n)
*/
    bool isPalindrome(ListNode* head) {
     stack<int> s;
        ListNode* temp = head;
        // Push all elements of the list to the stack
        while (temp != NULL){
            s.push(temp->val);
            temp = temp->next;
        }
        // Traverse the list again and compare with stack
        temp = head;
        // since in the stack it is bottom to top 
        // so we are checking from the above means from the front of the linked list(head),
        // and comparing with stack top ( elements from the back) so we can check whether it is palindrome or not
        while(temp != NULL){
            int top = s.top();
            s.pop();
            if(top != temp->val){
                return false;
            }
            temp = temp->next;
        }

        return true;
    }
};

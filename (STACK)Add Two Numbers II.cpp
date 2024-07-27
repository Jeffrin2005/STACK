class Solution {
// TIME COMP =   O(N+M) SPACE COMP = O(N+M)
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* result = NULL;
        int carry = 0;
        while (!s1.empty() or !s2.empty() or carry != 0){
            int sum = carry;
            if(!s1.empty()){
                sum+=s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum+=s2.top();
                s2.pop();
            }
            carry = sum / 10;
            sum = sum % 10;
            ListNode* node = new ListNode(sum);
            node->next = result;
            result = node;
        }
        return result;
    }
};

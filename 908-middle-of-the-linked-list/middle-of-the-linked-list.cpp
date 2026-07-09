class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //we will use fast and slow pointer method
        //according to this method, when fast is at end of ll, slow is at middle

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        } 
        return slow;     
    }
};
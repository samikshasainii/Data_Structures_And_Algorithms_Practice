class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevnode  = &dummy;
        ListNode* current = head;
        int i = 1;
        while(i<left){
            prevnode = prevnode->next;
            current = current->next;
            i++;
        } 
        //now current is at the element of reversal and prevnode is at left list tail
        ListNode* reversedTail = current;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        int j = 0;
        while(current!=nullptr && j<right-left+1){
            next = current->next;
            current->next = prev;
            //prev will become head of this reversed list
            prev = current;
            current = next;
            j++;
        }
        prevnode->next = prev;
        reversedTail->next = current;
        return dummy.next;
    }
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;

        ListNode* previous = dummy;

        while (true) {

            ListNode* m = previous;
            for (int i = 0; i < k; i++) {
                m = m->next;
                if (m == NULL) return dummy->next;
            }

            ListNode* nextt = m->next;

            ListNode* start = previous->next;
            ListNode* end = nextt;

            ListNode* current = start;
            ListNode* prev = end;

            while (current != nextt) {
                ListNode* temp1 = current->next;
                current->next = prev;
                prev = current;
                current = temp1;
            }

            ListNode* temp2 = previous->next;
            previous -> next = m;
            previous = temp2;
        }
    }
};
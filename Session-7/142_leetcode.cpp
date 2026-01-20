#include <unordered_set>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*> mapp;

        ListNode* slow = head;

        while (slow) {
            if (mapp.count(slow)) return slow;

            mapp.insert(slow);
            slow = slow -> next;
        }

        return NULL;
    }
};
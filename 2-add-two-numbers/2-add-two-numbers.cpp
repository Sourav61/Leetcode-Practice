/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ans = 0;
        ListNode newhead(0);
        ListNode *t = &newhead;

        while(ans || l1 || l2){
            ans += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            t->next = new ListNode(ans%10);
            t = t->next;
            ans/=10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }

        return newhead.next;
    }
};
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* node=head;
        for(;node != NULL;)
        {
            for(ListNode* pre=head;pre != node ; pre=pre->next)
            {
                if(node->val < pre->val)
                {
                    swap(node->val,pre->val);
                }
            }
            node=node->next;
        }
        return head;
    }
    
};
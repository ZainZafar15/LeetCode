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
    ListNode* mergeTwoLists(ListNode* List1, ListNode* List2 ){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(List1 != nullptr && List2 != nullptr)
        {
            if (List1->val <= List2->val)
            {
                curr->next = List1;
                List1 = List1->next;
            }
            else
            {
                curr->next = List2;
                List2 = List2->next;
            }
            curr = curr->next;
        }
        if (List1 != nullptr)
        {
            curr->next = List1;
        }
        else
        {
            curr->next = List2;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = nullptr;
        for (int i = 0; i < lists.size(); i++)
        {
            result = mergeTwoLists(result, lists[i]);
        }
        return result;
    }
};
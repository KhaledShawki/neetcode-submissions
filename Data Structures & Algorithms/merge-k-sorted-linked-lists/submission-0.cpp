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

class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode dummy;
        ListNode* result = &dummy;
        vector<int> values;
        for(ListNode* list : lists)
        {
            do
            {
                values.push_back(list->val);
                list = list->next;
            }
            while(list);
        }
        sort(values.begin(), values.end());
        for(int val : values)
        {
            result->next = new ListNode(val);
            result = result->next;
        }
        return dummy.next;
    }
};

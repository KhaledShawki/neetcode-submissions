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
        if(lists.empty())
        {
            return nullptr;
        }

        while(lists.size() > 1)
        {
            vector<ListNode*> mergedList;
            for(int i = 0; i < lists.size(); i += 2)
            {
                ListNode* left = lists[i];
                ListNode* right = i + 1 < lists.size() ? lists[i + 1] : nullptr;

                mergedList.push_back(mergeList(left, right));
            }
            lists = mergedList;
        }

        return lists[0];
    }

private: 
    ListNode* mergeList(ListNode* left, ListNode* right)
    {

        ListNode dummy;
        ListNode* tail = &dummy;
        
        while(left && right)
        {
            if(left->val < right->val)
            {
                tail->next = left;
                left = left->next; 
            }
            else
            {
                tail->next = right;
                right = right->next; 
            }

            tail = tail->next;
        }
        
        if(left)
        {
            tail->next = left;
        }

        if(right)
        {
            tail->next = right;
        }

        return dummy.next;
    }
};

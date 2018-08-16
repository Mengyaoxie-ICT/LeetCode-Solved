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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag=0;
        int i=0;
        
        
        ListNode* end;
        end = (ListNode*)malloc(sizeof(ListNode));
        end->next = NULL;
        
        ListNode* temp;
        temp = end;
        
        while (l1 || l2)
        {
            i = 0;
            ListNode * p = (ListNode*)malloc(sizeof(ListNode));

            if(!l1)
            {
                i = l2->val;
                l2 = l2->next;
            }    
            else if(!l2)
            {
                i = l1->val;
                l1 = l1->next;
            }    
            else
            {
                i = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }    
            
            if(i + flag >= 10)
            {
                p->val = i + flag - 10;
                flag = 1;
            }
            else
            {
                p->val = i + flag;
                flag = 0;
            }
            
            temp->next = p;
            temp = p;
        }
        if(flag == 1) //处理最高位进位的情况
        {
            ListNode * p = (ListNode*)malloc(sizeof(ListNode));
            p->val = 1;
            temp -> next = p;
            temp = p;
        }   
        temp -> next = NULL;
        end = end->next;
        return end;
    }
};

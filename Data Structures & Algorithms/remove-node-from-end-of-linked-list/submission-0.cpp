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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0 ;
        ListNode* prev = nullptr;
        while(temp){
            count++;
            temp=temp->next;
        }
        ListNode* temp1=head;
        for(int i=0;i<count-n;i++){
            prev=temp1;
            temp1=temp1->next;
        }
        if(count==n){
            return head->next;
        }
        prev->next = temp1->next;
        return head;
    }
};

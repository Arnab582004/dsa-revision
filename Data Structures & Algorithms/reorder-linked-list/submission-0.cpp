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
    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverselist(ListNode* node){
        ListNode* prev=nullptr;
        ListNode* curr = node;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* m = findMiddle(head);
        ListNode* second = m->next;
        m->next = nullptr;
        second = reverselist(second);
        ListNode* first = head;

        while(second != nullptr) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;

            first->next = second;
            second->next = nextFirst;

            first = nextFirst;
            second = nextSecond;
        }
    }
};

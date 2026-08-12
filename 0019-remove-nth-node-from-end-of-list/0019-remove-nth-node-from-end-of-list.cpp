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
    int getLengthOfLinkedList(ListNode* head){
        int L = 0;
        while(head != NULL){
            L++;
            head = head->next;
        }
        return L;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int L = getLengthOfLinkedList(head);
        if(L == n){
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }
        if(n > L){
            return NULL;
        }
        int i = L-n;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(i != 0){
            prev = temp;
            temp = temp->next;
            i--;
        }
        prev->next = temp->next;
        delete(temp);
        return head;
        
    }
};
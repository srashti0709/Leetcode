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
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* point = head;
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        while(fast != NULL && fast->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }

        }
        if(slow != fast){
            return NULL;
        }
        
        while(point != slow){
            point = point->next;
            slow = slow->next;
        }
        
        return point;
  
    }
};
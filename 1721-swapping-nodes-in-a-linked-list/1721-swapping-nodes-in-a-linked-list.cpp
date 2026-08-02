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
    int findLength(ListNode* head){
        int n = 0;
        while(head != NULL){
            head = head->next;
            n++;
        }
        return n;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n = findLength(head);
        int lastK = n-k+1;
        ListNode* Node1 = head;
        ListNode* Node2 = head;
        while(k>1){
            Node1 = Node1->next;
            k--;
        }
        while(lastK > 1){
            Node2 = Node2->next;
            lastK--;

        }
        swap(Node1->val,Node2->val);
        return head;

    }
};
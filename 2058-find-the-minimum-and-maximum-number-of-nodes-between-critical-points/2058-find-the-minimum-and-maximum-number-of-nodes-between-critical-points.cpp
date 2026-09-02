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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* Prev = head;
        ListNode* Curr = head->next;
        int i = 1;
        int firstcp = 0;
        int prevcp = 0;
        int mindis = INT_MAX;


        while(Curr->next != NULL){
            if((Curr->val < Prev->val && Curr->val < Curr->next->val) || (Curr->val > Prev->val && Curr->val > Curr->next->val)){
                if(prevcp == 0){
                    prevcp = i;
                    firstcp = i;
                }
                else{
                    mindis = min(mindis, i-prevcp);
                    prevcp = i;
                }

            }
            i++;
            Prev = Curr;
            Curr = Curr->next;
        }
        if(mindis == INT_MAX){
            return{-1,-1};
        }
        return {mindis, prevcp-firstcp};
    }
};
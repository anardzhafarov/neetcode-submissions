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
        ListNode* prev = nullptr;
        ListNode* nex;
        ListNode* curr = head;
        while(curr != nullptr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        
        ListNode* del = prev;
        ListNode* del_prev = nullptr;
        for(int i = 1; i < n; i++){
            del_prev = del;
            del = del->next;
        }
        if(del_prev != nullptr){
            del_prev->next = del->next;
            del->next = nullptr;
        } else {
            prev = del->next;
            del->next = nullptr;
        }

        ListNode* previ = nullptr;
        ListNode* ne;
        while(prev != nullptr){
            ne = prev->next;
            prev->next = previ;
            previ = prev;
            prev = ne;
        }
        return previ;
    }
};

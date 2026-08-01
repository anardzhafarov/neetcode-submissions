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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return {};
        vector<ListNode*> nodes; 
        while(head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }
        for(int i = nodes.size() - 1; i >= 0; i--){
            if (i > 0){
                nodes[i]->next = nodes[i-1];
            } else {
                nodes[i]->next = nullptr;
            }
        }
        return nodes[nodes.size()-1];
    }
};

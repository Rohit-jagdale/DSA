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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode{0, nullptr}; 
        ListNode* c = l3;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val+carry;
            carry = sum/10;
            c->val = sum%10;
            l1=l1->next;
            l2=l2->next;
            if(l1==nullptr && l2==nullptr){
                if(carry!=0){
                    c->next = new ListNode(carry);
                }
                return l3;
            }
            c->next = new ListNode(); 
            c = c->next;
        }
        while(l1 != nullptr){
            int sum = l1->val+carry;
            carry = sum/10;
            c->val = sum%10;
            l1=l1->next;
            if(l1==nullptr){
                if(carry!=0){
                    c->next = new ListNode(carry);
                }
                return l3;
            }
            c->next = new ListNode(); 
            c = c->next;
        }
        while(l2 != nullptr){
             int sum = l2->val+carry;
            carry = sum/10;
            c->val = sum%10;
            l2=l2->next;
            if(l2==nullptr){
                if(carry!=0){
                    c->next = new ListNode(carry);
                }
                return l3;
            }
            c->next = new ListNode(); 
            c = c->next;
        }
        return l3;
    }
};

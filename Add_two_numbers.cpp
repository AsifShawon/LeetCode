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
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        int carry = 0;
        int add, a, b;
        while (list1 != nullptr and list2 != nullptr) {
            a = list1->val;
            b = list2->val;
            // cout << a << " " << b << "\n";
            add = a + b + carry;
            carry = 0;
            if(add > 9){
                add = add - 10;
                carry = 1;
            }
            ListNode* newNode = new ListNode(add);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }

            list1 = list1->next;
            list2 = list2->next;
        }

        ListNode* left;
        if(list1==nullptr){
            left = list2;
        }
        else {
            left = list1;
        }

        while(left != nullptr){
            a = left->val;
            add = a + carry;
            carry = 0;
            if(add > 9){
                add = add - 10;
                carry = 1;
            }
            ListNode* newNode = new ListNode(add);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }

            left = left->next;
        }
        if(carry > 0){
            ListNode* newNode = new ListNode(carry);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        return head;
    }
};

// https://leetcode.com/problems/add-two-numbers/

// 3 ms
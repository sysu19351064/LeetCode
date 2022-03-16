#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* re = head;
        ListNode* temp = head;
        while(--n){
            temp = temp->next;
        }
        ListNode* temp2 = temp;
        temp = head;
        ListNode* former = temp;
        while(temp2->next){
            temp2 = temp2->next;
            former = temp;
            temp = temp->next;
        }
        if(head == temp){
            head = head->next;
        }
        else{
            former->next = temp->next;
        }
        return head;
    }
};



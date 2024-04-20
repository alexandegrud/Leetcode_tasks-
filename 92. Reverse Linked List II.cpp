/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
*/

#include <iostream>
using namespace std;


 struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL) {
            return head; 
        }
        ListNode* answer = new ListNode();
        answer->next = head; 

        ListNode* prev = answer;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
        ListNode* current = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* next = current->next;
            current->next = next->next;
            next->next = prev->next; 
            prev->next = next; 
        }
        return answer->next;
    }
};


int main() {
    size_t count = 0;
    int left = 0;
    int right = 0;
    cin >> count;
    int value = 0;
    ListNode* head = nullptr;
    if (count > 0) {
        cin >> value;
        head = new ListNode(value);
    }
    ListNode* current = head;
    for (size_t i = 1; i < count; i++) {
        cin >> value;
        ListNode* nextnode = new ListNode(value);
        current->next = nextnode;
        current = nextnode;
    }
    cin >> left;
    cin >> right;

    Solution Solution;
    ListNode* result = Solution.reverseBetween(head, left, right);
    while (result != NULL) {
        cout << result->val;
        result = result->next;
    }
}
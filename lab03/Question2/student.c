// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    while (prev->next != NULL && prev->next->next != NULL) {
        struct ListNode* a = prev->next;
        struct ListNode* b = a->next;
        a->next = b->next;
        b->next = a;
        prev->next = b;
        prev = a;
    }
    return dummy.next;
}
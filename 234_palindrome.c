#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h> 

struct ListNode {
  int val;
  struct ListNode *next;
};

void printList(struct ListNode* head) {
  struct ListNode *temp = head;
  while (temp) {
    printf("%d\t", temp->val);
    temp = temp->next;
  }
  printf("\n");
}

bool isPalindrome(struct ListNode *head) {
  /* 0 or 1 */
  if (!head || !head->next) {
    return true;
  }

  /* find middle and reverse left list */
  struct ListNode *fast = head;
  struct ListNode *slow = head;
  struct ListNode *prev = NULL;
  struct ListNode *lhead;
  while (fast && fast->next) {
    lhead = slow;
    slow = slow->next;
    fast = fast->next->next;

    lhead->next = prev;
    prev = lhead;
  }

  /* list count is odd, move forward */
  if (fast) {
    slow = slow->next;
  }

  /* compare two list */
  while (lhead) {
    if (lhead->val != slow->val) {
      return false;
    }
    
    lhead = lhead->next;
    slow = slow->next;
  }

  return true;
}

int
main(int argc, char *argv[]) {
  struct ListNode a, b, c, d;
  a.val = 1;
  b.val = 2;
  c.val = 2;
  d.val = 1;
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = NULL;

  struct ListNode *head = &a;
  printf("%s\n", isPalindrome(head) == true ? "true" : "false");
  
  return 0;
}

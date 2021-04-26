#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* detectCycle(struct ListNode *head) {
  struct ListNode *fast = head;
  struct ListNode *slow = head;

  if (!fast || !fast->next) {
    return NULL;
  }

  do {
    fast = fast->next->next;
    /* list is end */
    if (!fast) {
      return NULL;
    }
    slow = slow->next;
  } while(fast != slow);

  fast = head;
  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }

  return fast;
}

int
main(int argc, char *argv[]) {
  struct ListNode a, b, c, d;
  a.val = 3;
  b.val = 2;
  c.val = 0;
  d.val = -4;

  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &b;

  struct ListNode *head = &a;
  struct ListNode *start = detectCycle(head);
  if (start) {
    printf("%d\n", start->val);
  } else {
    printf("NULL\n");
  }
  
  return 0;
}

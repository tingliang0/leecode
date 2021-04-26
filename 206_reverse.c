#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* reverse(struct ListNode *head) {
  struct ListNode *prev = NULL;
  struct ListNode *next;

  while (head) {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }

  return prev;
}

void printList(struct ListNode* head) {
  struct ListNode *temp = head;
  while (temp) {
    printf("%d\n", temp->val);
    temp = temp->next;
  }
}

int
main(int argc, char *argv[]) {
  struct ListNode a, b, c, d, e;
  a.val = 1;
  b.val = 2;
  c.val = 3;
  d.val = 4;
  e.val = 5;

  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = NULL;

  struct ListNode* head = &a;
  printList(head);
  printf("-------------\n");
  head = reverse(head);
  printList(head);
  
  return 0;
}


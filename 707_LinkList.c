#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode {
    int val;
    struct LinkedNode *next;
} LinkedNode;

typedef struct {
    int size;
    LinkedNode *head;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *list = malloc(sizeof(MyLinkedList));
    if (!list) {
        return NULL;
    }
    list->size = 0;
    list->head = malloc(sizeof(LinkedNode)); /* 增加一个头简单能简化插入和删除逻辑 */
    list->head->val = -1;
    list->head->next = NULL;
    return list;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return -1;
    }

    struct LinkedNode *cur = obj->head;
    for (int i = 0; i < index+1; i++) {
        cur = cur->next;
    }
    return cur->val;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) {
        return;
    }
    LinkedNode *curr = obj->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    LinkedNode *node = malloc(sizeof(LinkedNode));
    node->val = val;
    node->next = curr->next;
    curr->next = node;
    obj->size++;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, obj->size, val);
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return;
    }
    LinkedNode *prev = obj->head;
    for (int i = 0; i < index; i++) {
        prev = prev->next;
    }
    LinkedNode *temp = prev->next;
    prev->next = prev->next->next;
    obj->size--;
    free(temp);
}

void myLinkedListFree(MyLinkedList* obj) {
    LinkedNode *temp;
    while (obj->head) {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }

    obj->head = NULL;
    free(obj);
}

void printLinkedList(MyLinkedList *obj) {
    LinkedNode *temp = obj->head;
    while (temp) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf(" size = %d\n", obj->size);
}

int
main(int argc, char *argv[]) {
    MyLinkedList *list = myLinkedListCreate();
    myLinkedListAddAtHead(list, 1);
    myLinkedListAddAtTail(list, 3);
    myLinkedListAddAtIndex(list, 1, 2);
    printLinkedList(list);
    myLinkedListGet(list, 1);
    myLinkedListDeleteAtIndex(list, 1);
    printLinkedList(list);
    myLinkedListGet(list, 1);
    myLinkedListFree(list);
    return 0;
}

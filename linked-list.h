#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
    int length;
    size_t size;
    struct Node* start;
    struct Node* end;
} LinkedList;

typedef struct Node {
    void* data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef void NodePrintFunction(Node*);

LinkedList* linkedListNew(size_t size);


void* linkedListPush(LinkedList* linkedList);

void linkedListPop(LinkedList* linkedList);

void* linkedListGetByIndex(LinkedList* linkedList, int number);

void linkedListRemove(
    LinkedList* linkedList,
    Node* address
);

void linkedListPrint(
    LinkedList* linkedList,
    NodePrintFunction* callback
);

void linkedListFree(LinkedList* linkedList);

#endif /* LINKEDLIST_H */
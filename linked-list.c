#include "linked-list.h"

void nodeFree(Node* n){
    if (n == NULL) {
        printf("Can't free NULL");
	return;
    }

    void* data = (*n).data;
    if (data == NULL) printf("Can't free data of address %p", n);
    else free(data);
    free(n);
}

LinkedList* linkedListNew(size_t size) {
    LinkedList* linkedList = (LinkedList*) malloc(sizeof(LinkedList));
    (*linkedList).start = NULL;
    (*linkedList).end = NULL;
    (*linkedList).length = 0;
    (*linkedList).size = size;
    return linkedList;
}

void* linkedListPush(LinkedList* linkedList) {
    void* data = malloc((*linkedList).size);
    Node* nNew = malloc(sizeof(Node));
    (*nNew).data = data;
    (*nNew).next = NULL;
    (*nNew).prev = NULL;

    if ((*linkedList).start == NULL) {
        (*linkedList).start = nNew;
        (*linkedList).end = nNew;
        (*linkedList).length = 1;
        return data;
    }

    Node* n = (*linkedList).start;
    while (n != NULL) {
        if ((*n).next != NULL) {
            n = (*n).next;
            continue;
        }

        (*n).next = nNew;
        (*nNew).prev = n;
        (*linkedList).end = nNew;
        (*linkedList).length += 1;
        break;
    }


    return data;
}

void linkedListPop(LinkedList* linkedList) {
    Node* n = (*linkedList).end;
    if (n == NULL) return;

    Node* nNext = (*n).next;
    Node* nPrev = (*n).prev;
    
    (*linkedList).end = nPrev;

    if (nPrev != NULL) {
        (*nPrev).next = NULL;
    }
    (*linkedList).length -= 1;

    free((*n).data);
    free(n);
}

void linkedListRemove(LinkedList* linkedList, Node* address) {
    Node* n = (*linkedList).start;
    int acc = 0;

    while(n != NULL && acc < (*linkedList).length) {

        if (address != n) {
            acc += 1;
            n = (*n).next;
            continue;
        }

        Node* nNext = (*n).next;
        Node* nPrev = (*n).prev;
        free((*n).data);
        free(n);
        (*linkedList).length -= 1;
        
        if (nNext != NULL) (*nNext).prev = nPrev;
        else {
            (*linkedList).end = nPrev;
        }


        if (nPrev != NULL) (*nPrev).next = nNext;
        else {
            (*linkedList).start = nNext;
        }

        return;
    }

    if (acc >= (*linkedList).length) printf("Address not found %p\n", address);
}

void linkedListPrint(LinkedList* linkedList, NodePrintFunction* callback) {
    printf("START : %p\n", (*linkedList).start);
    printf("END   : %p\n", (*linkedList).end);
    printf("LENGTH: %i\n", (*linkedList).length);

    Node* n = (*linkedList).start;
    while (n != NULL) {
        printf("-------------\n");
        printf("current:%p data:%p - prev: %p - next: %p\n", n, (*n).data, (*n).prev, (*n).next);
        if (callback != NULL) callback(n);
        else printf("DATA BLOCK\n");
        //printf("value: %i current:%p - prev: %p - next: %p\n", (*n).number, n, (*n).prev, (*n).next);
        n = (*n).next;
    }
    printf("....................\n");
}


void linkedListFree(LinkedList* linkedList) {
    Node* n = (*linkedList).start;
    while (n != NULL) {
        Node* nTemp = (*n).next;
        free((*n).data);
        free(n);
        n = nTemp;
    }

    (*linkedList).start = NULL;
    (*linkedList).end = NULL;
    (*linkedList).length = 0;
    free(linkedList);
}

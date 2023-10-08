#include <stdio.h>
#include "linked-list.h"

void printInt(Node* n){
    int *number = (*n).data;
    printf("%n\n", *number);
}

int main(void) {
    LinkedList* list = linkedListNew(sizeof(int));
    linkedListPrint(list, printInt);
    linkedListFree(list);
    return 0;
}

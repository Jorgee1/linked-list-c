#include <stdio.h>
#include "linked-list.h"

void printInt(Node* n){
    int* data = (*n).data;
    printf("%i", *data);
}

int main(void){
    LinkedList *list = linkedListNew(sizeof(int));
    for (int i = 0; i < 10; i++){
        *((int*)linkedListPush(list)) = i;
    }
    linkedListPrint(list, printInt);
    linkedListFree(list);
}

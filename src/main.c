#include <stdio.h>
#include "linkedListQueue.h"

void printQueue(int pInt[], int size) {
    printf("Enqueue List: \n");

    for (int i = 0; i < size; ++i) {
        printf("[%d] %d \n", i, pInt[i]);
        enqueue(pInt[i]);
    }

    printf("\nDequeue List: \n");

    for (int j = 0; j <= size; ++j) {
        printf("[%d] %d \n", j, dequeue());
    }
}

void testQueue() {
    int q[] = {0, 51, 100, 50, -1, 120, 111, 2, 113, 51 , 89, 3 ,9};
    int size = 13;

    printQueue(q, size);
}

int main() {
    testQueue();

    return 0;
}
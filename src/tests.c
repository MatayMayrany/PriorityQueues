//
// Created by Louis on 2019-01-30.
//
#include "tests.h"

void testListReadyQueue() {
    int q[] = {0, 51, 100, 50, -1, 120, 111, 2, 113, 51 , 89, 3 ,9};
    int size = 13;

    printf("Enqueue List: \n");

    for (int i = 0; i < size; ++i) {
        printf("[%d] %d \n", i, q[i]);
        enqueueList(q[i]);
    }

    printf("\nDequeue List: \n");

    for (int j = 0; j <= size; ++j) {
        printf("[%d] %d \n", j, dequeueList());
    }
}

void testHeapReadyQueue() {
    initHeap(100);
    int q[] = {100, 21, 30, 10, 3, 1, 150};
    int size = 7;

    printf("Enqueue Heap: \n");

    for (int i = 0; i < size; ++i) {
        printf("[%d] %d \n", i, q[i]);
        enqueueHeap(q[i]);
    }

    printHeap();

    printf("DEQUEUE = %d \n", dequeueHeap());

    printHeap();

    printf("DEQUEUE = %d \n", dequeueHeap());

    printHeap();

    printf("DEQUEUE = %d \n", dequeueHeap());

    printHeap();
}

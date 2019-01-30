//
// Created by Louis on 2019-01-30.
//
#include <sys/time.h>
#include "tests.h"

int *generateArray (int size) {
    srand(time(NULL));

    int *array = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }

    return &array[0];
}

void testListReadyQueue() {
    int size = 13;
    int *q = generateArray(size);

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
    printf("\n - START -\n\n");

    int size = 100;
    int *q = generateArray(size);

    initHeap(size);

    printf("Enqueue Heap: \n\n");

    for (int i = 0; i < size; ++i) {
        printf("| %d ", q[i]);
        enqueueHeap(q[i]);
    }

    printf("\n\nDequeue Heap: \n\n");

    for (int j = 0; j < size; ++j) {
        printf("| %d ", dequeueHeap());
    }

    printf("\n\n - END - \n");
}


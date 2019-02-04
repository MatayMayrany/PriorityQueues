//
// Created by Louis on 2019-01-30.
//

/*Create fixed size queue from randomly generated array
 * We dont need to measure the time for this
 * only measuring for the accesses of the fixed size queue */

/* dequeue and element then enqueue an element directly after
 * maintain fixed size by doing this with randomly generated integers
 * measure Execution time of every enqueue and dequeue operation*/

#include <sys/time.h>
#include "tests.h"
#include "codes.h"
#include "linkedListQueue.h"
#include "heapReady.h"
#include "heapEvent.h"

float startEnqueueTime;
float endEnqueueTime;
float enqueueTime;
float startDequeueTime;
float endDequeueTime;
float dequeueTime;

void saveData(float enqueueTime, float dequeueTime);

int *generateArray (int size) {
    srand(time(NULL));

    int *array = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }

    return &array[0];
}

void saveData(float enqueueTime, float dequeueTime) {
    printf("Enqueue Time: %f   ", enqueueTime);
    printf("Dequeue Time: %f   ", dequeueTime);
    printf("Average Time: %f   \n", (dequeueTime + enqueueTime)/2);
}

void testSinglyLinkedListReady (int iterations, int size, int *q) {
    printf("Testing Singly Linked List Ready Queue: \n\n");

    printf("Unordered: ");
    for (int i = 0; i < size; ++i) {
        printf("| %d ", q[i]);
        enqueueList(q[i]);
    }

    printf("\n");

    printf("Ordered: ");
    for (int i = 0; i < size; ++i) {
        printf("| %d ", dequeueList());
    }

    //put back elements for timing
    for (int i = 0; i < size; ++i) {
        enqueueList(q[i]);
    }

    printf("\n\n");

    for (int j = 0; j < iterations; ++j) {
        startDequeueTime = (float) clock();
        int element = dequeueList();
        endDequeueTime = (float) clock();
        dequeueTime = (endDequeueTime - startDequeueTime) / CLOCKS_PER_SEC;

        startEnqueueTime = (float) clock();
        enqueueList(element);
        endEnqueueTime = (float) clock();
        enqueueTime = (endEnqueueTime - startEnqueueTime) / CLOCKS_PER_SEC;

        saveData(enqueueTime, dequeueTime);
    }
}

void testHeapReady(int iterations, int size, int *q) {
    initReadyHeap(size);
    printf("Testing Heap Ready Queue: \n\n");

    printf("Unordered list: ");
    for (int i = 0; i < size; ++i) {
        printf("| %d ", q[i]);
        enqueueReadyHeap(q[i]);
    }

    printf("\n");
    printf("Ordered list: ");
    for (int i = 0; i < size; ++i) {
        printf("| %d ", dequeueReadyHeap());
    }

    for (int i = 0; i < size; ++i) {
        enqueueReadyHeap(q[i]);
    }

    printf("\n\n");

    for (int j = 0; j < iterations; ++j) {
        startDequeueTime = (float) clock();
        int element = dequeueReadyHeap();
        endDequeueTime = (float) clock();
        dequeueTime = (endDequeueTime - startDequeueTime) / CLOCKS_PER_SEC;

        startEnqueueTime = (float) clock();
        enqueueReadyHeap(element);
        endEnqueueTime = (float) clock();
        enqueueTime = (endEnqueueTime - startEnqueueTime) / CLOCKS_PER_SEC;

        saveData(enqueueTime, dequeueTime);
    }

    killReadyHeap();
}

void testHeapEvent(int iterations, int size, int *q) {
    initEventHeap(size);

    printf("Testing Heap Event Queue: \n\n");

    printf("Unordered list: ");
    for (int i = 0; i < size; ++i) {
        printf("| %d ", q[i]);
        enqueueEventHeap(q[i]);
    }

    printf("\n");
    printf("Ordered list: ");
    for (int i = 0; i < size; ++i) {
        printf("| %d ", dequeueEventHeap());
    }

    for (int i = 0; i < size; ++i) {
        enqueueEventHeap(q[i]);
    }

    printf("\n\n");

    for (int j = 0; j < iterations; ++j) {
        startDequeueTime = (float) clock();
        int element = dequeueEventHeap();
        endDequeueTime = (float) clock();
        dequeueTime = (endDequeueTime - startDequeueTime) / CLOCKS_PER_SEC;

        startEnqueueTime = (float) clock();
        enqueueEventHeap(element);
        endEnqueueTime = (float) clock();
        enqueueTime = (endEnqueueTime - startEnqueueTime) / CLOCKS_PER_SEC;

        saveData(enqueueTime, dequeueTime);
    }

    killEventHeap();
}

void test(int iterations, int chooser, int size) {
    printf("- START - \n\n");

    int *q = generateArray(size);

    switch(chooser) {
        case LIST_READY_CODE :
            testSinglyLinkedListReady(iterations, size, q);
            break;
        case HEAP_READY_CODE :
            testHeapReady(iterations, size, q);
            break;
        case LIST_EVENT_CODE :
            break;
        case HEAP_EVENT_CODE :
            testHeapEvent(iterations, size, q);
            break;
        default:
            printf("ERROR: CODE INVALID");
            break;
    }

    printf("\n\n- END - ");
}
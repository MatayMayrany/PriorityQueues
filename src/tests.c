//
// Created by Louis on 2019-01-30.
//
#include <sys/time.h>
#include "tests.h"

float startEnqueueTime;
float endEnqueueTime;
float enqueueTime;
float startDequeueTime;
float endDequeueTime;
float dequeueTime;
int element;

void saveData(float enqueueTime, float dequeueTime);

int *generateArray (int size) {
    srand(time(NULL));

    int *array = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }

    return &array[0];
}

void testReadyQueue(int iterations, int chooser) {
    int size = 20;
    int *q = generateArray(size);

    /*Create fixed size queue from randomly generated array
     * We dont need to measure the time for this
     * only measuring for the accesses of the fixed size queue */
    printf("Creating Initial Queue: \n");
    if (chooser == 1){
        printf("List: \n\n");
        for (int i = 0; i < size; ++i){
            printf("[%d] %d \n", i, q[i]);
            enqueueList(q[i]);
        }
    }else{
        initHeap(size);
        printf("Heap: \n\n");
        for (int i = 0; i < size; ++i) {
            printf("| %d ", q[i]);
            enqueueHeap(element);
        }
    }


    /* dequeue and element then enqueue an element directly after
     * maintain fixed size by doing this with randomly generated integers
     * measure Execution time of every enqueue and dequeue operation*/
    printf("Testing: \n\n");
    for (int i = 0; i < iterations; i++) {
        if (chooser == 1) {
            testSinglyLinkedListReadyQueue();
        } else if (chooser == 2) {
            testHeapReadyQueue();
        }
    }

}

void saveData(float enqueueTime, float dequeueTime) {
    printf("Enqueue Time: %f   ", enqueueTime);
    printf("Dequeue Time: %f   ", dequeueTime);
    printf("Average Time: %f   \n\n", (dequeueTime + enqueueTime)/2);

}

void testSinglyLinkedListReadyQueue(){
    startDequeueTime = (float) clock();
    element = dequeueList();
    endDequeueTime = (float) clock();
    dequeueTime = (endDequeueTime - startDequeueTime)/CLOCKS_PER_SEC;

    startEnqueueTime = (float) clock();
    enqueueList(element);
    endEnqueueTime = (float) clock();
    enqueueTime = (endEnqueueTime - startEnqueueTime)/CLOCKS_PER_SEC;

    saveData(enqueueTime, dequeueTime);
}



void testHeapReadyQueue() {

    printf("Testing Heap Ready Queue...\n\n");
    startDequeueTime = (float) clock();
    dequeueHeap();
    endDequeueTime = (float) clock();
    dequeueTime = (endDequeueTime - startDequeueTime)/CLOCKS_PER_SEC;

    startEnqueueTime = (float) clock();
    enqueueList(element);
    endEnqueueTime = (float) clock();
    enqueueTime = (endEnqueueTime - startEnqueueTime)/CLOCKS_PER_SEC;

    saveData(enqueueTime, dequeueTime);

//    printf("\n - START -\n\n");
//
//    int size = 5000;
//    int *q = generateArray(size);
//
//    initHeap(size);
//
//    printf("Enqueue Heap: \n\n");
//
//    for (int i = 0; i < size; ++i) {
//        printf("| %d ", q[i]);
//
//
//        enqueueHeap(element);
//
//
//    }
//
//    printf("\n\nDequeue Heap: \n\n");
//
//    for (int j = 0; j < size; ++j) {
//        printf("| %d ", dequeueHeap());
//    }
//
//    printf("\n\n - END - \n");
}


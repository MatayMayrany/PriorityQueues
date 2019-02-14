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
#include "common.h"
#include "listReady.h"
#include "listEvent.h"
#include "heapReady.h"
#include "heapEvent.h"

float startEnqueueTime;
float endEnqueueTime;
float enqueueTime;
float startDequeueTime;
float endDequeueTime;
float dequeueTime;
FILE *f;
int SIZE_OF_RAND = 1000;

int *generateReadyArray (int size) {
    int *array = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i) {
        array[i] = arc4random_uniform((uint32_t) SIZE_OF_RAND);
    }

    return &array[0];
}

double *generateEventArray (int size) {
    double *array = (double*)malloc(sizeof(double) * size);
    srand48(time(0));

    for (int i = 0; i < size; ++i) {
        double r = drand48() * SIZE_OF_RAND;
        array[i] = r;
    }

    return &array[0];
}

int getRandInt () {
    return arc4random_uniform((uint32_t) SIZE_OF_RAND);;
}

void saveData(float enqueueTime, float dequeueTime) {
    fprintf(f, "%f, %f, %f, \n", enqueueTime, dequeueTime, (enqueueTime+dequeueTime));
}

double incrementTimeStamp(double element) {
    double r = drand48() * SIZE_OF_RAND;
    return element + r;
}

void testListReady(int iterations, int size) {
    printf("Testing Singly Linked List Ready Queue: \n\n");

    int *q = generateReadyArray(size);

    printf("Unordered: ");
    for (int i = 0; i < size; ++i) {
        printf("| %d ", q[i]);
        enqueueReadyList(q[i]);
    }

    printf("\n");

    printf("Ordered: ");
    for (int i = 0; i < size; ++i) {
        printf("| %d ", dequeueReadyList());
    }

    //put back elements for timing
    for (int i = 0; i < size; ++i) {
        enqueueReadyList(q[i]);
    }

    printf("\n\n");

    for (int j = 0; j < iterations; ++j) {
        int element = getRandInt();

        startDequeueTime = (float) clock();
        dequeueReadyList();
        endDequeueTime = (float) clock();
        dequeueTime = (endDequeueTime - startDequeueTime) / CLOCKS_PER_SEC;

        startEnqueueTime = (float) clock();
        enqueueReadyList(element);
        endEnqueueTime = (float) clock();
        enqueueTime = (endEnqueueTime - startEnqueueTime) / CLOCKS_PER_SEC;

        saveData(enqueueTime, dequeueTime);
    }
}

void testHeapReady(int iterations, int size) {
    initReadyHeap(size);
    printf("Testing Heap Ready Queue: \n\n");

    int *q = generateReadyArray(size);

    printf("Unordered: ");
    for (int i = 0; i < size; ++i) {
        printf("| %d ", q[i]);
        enqueueReadyHeap(q[i]);
    }

    printf("\n");
    printf("Ordered: ");
    for (int i = 0; i < size; ++i) {
        printf("| %d ", dequeueReadyHeap());
    }

    for (int i = 0; i < size; ++i) {
        enqueueReadyHeap(q[i]);
    }

    printf("\n\n");

    for (int j = 0; j < iterations; ++j) {
        int element = getRandInt();

        startDequeueTime = (float) clock();
        dequeueReadyHeap();
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

void testListEvent(int finalSize, int size) {
    printf("Testing Singly Linked List Event Queue: \n\n");

    double *q = generateEventArray(size);

    printf("Unordered: ");
    for (int i = 0; i < size; ++i) {
        printf("| %f ", q[i]);
        enqueueEventList(q[i]);
    }

    printf("\n");

    printf("Ordered: ");
    for (int i = 0; i < size; ++i) {
        printf("| %f ", dequeueEventList());
    }

    //put back elements for timing
    for (int i = 0; i < size; ++i) {
        enqueueEventList(q[i]);
    }

    printf("\n\n");

    for (int j = 0; j < finalSize; ++j) {
        startDequeueTime = (float) clock();
        double element = dequeueEventList();
        endDequeueTime = (float) clock();
        dequeueTime = (endDequeueTime - startDequeueTime) / CLOCKS_PER_SEC;

        double new1 = incrementTimeStamp(element);
        double new2 = incrementTimeStamp(element);

        printf("ELEMENT %f ELEMENT %f \n", new1, new2);

        startEnqueueTime = (float) clock();
        enqueueEventList(new1);
        enqueueEventList(new2);


        endEnqueueTime = (float) clock();
        enqueueTime = (endEnqueueTime - startEnqueueTime) / CLOCKS_PER_SEC;

        saveData(enqueueTime, dequeueTime);
    }
}

void testHeapEvent(int iterations, int size) {
    initEventHeap(size);

    printf("Testing Heap Event Queue: \n\n");

    double *q = generateEventArray(size);

    printf("Unordered list: ");
    for (int i = 0; i < size; ++i) {
        printf("| %f ", q[i]);
        enqueueEventHeap(q[i]);
    }

    printf("\n");
    printf("Ordered list: ");
    for (int i = 0; i < size; ++i) {
        printf("| %f ", dequeueEventHeap());
    }

    for (int i = 0; i < size; ++i) {
        enqueueEventHeap(q[i]);
    }

    printf("\n\n");

    for (int j = 0; j < iterations; ++j) {
        startDequeueTime = (float) clock();
        double element = dequeueEventHeap();
        endDequeueTime = (float) clock();
        dequeueTime = (endDequeueTime - startDequeueTime) / CLOCKS_PER_SEC;

        double new1 = incrementTimeStamp(element);
        double new2 = incrementTimeStamp(element);

        startEnqueueTime = (float) clock();
        enqueueEventList(new1);
        enqueueEventList(new2);
        endEnqueueTime = (float) clock();
        enqueueTime = (endEnqueueTime - startEnqueueTime) / CLOCKS_PER_SEC;

        saveData(enqueueTime, dequeueTime);
    }

    killEventHeap();
}

void test(int variable, int chooser, int size) {
    printf("- START - \n\n");
    f = fopen("../data.csv", "w");

    switch(chooser) {
        case LIST_READY_CODE :
            fprintf(f, "Enqueue Time, Dequeue Time, Sum, \n");
            testListReady(variable, size);
            break;
        case HEAP_READY_CODE :
            fprintf(f, "Enqueue Time, Dequeue Time, Sum, \n");
            testHeapReady(variable, size);
            break;
        case LIST_EVENT_CODE :
            fprintf(f, "Enqueue Time, Dequeue Time, Sum, \n");
            testListEvent(variable, size);
            break;
        case HEAP_EVENT_CODE :
            fprintf(f, "Enqueue Time, Dequeue Time, Sum, \n");
            testHeapEvent(variable, size);
            break;
        default:
            printf("ERROR: CODE INVALID");
            break;
    }

    fclose(f);

    printf("\n\n- END - ");
}
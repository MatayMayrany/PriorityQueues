//
// Created by Louis on 2019-02-04.
//

// double is the data type as we will use time stamps
// Heap will be minimum based as the lower the time stamp the higher the priority

#include <limits.h>
#include "heapEvent.h"

double *heap;
int end;

void initEventHeap(int maxSize) {
    heap = (double*)malloc(sizeof(double) * maxSize);

    //tell our program the heap is empty
    // 0 is empty
    // 1 is not
    heap[0] = -INT_MAX;
}

void killEventHeap() {
    free(heap);
}

void enqueueEventHeap(double priority) {
    end++;
    heap[end] = priority;
    int now = end;

    while (heap[now / 2] > priority) {
        heap[now] = heap[now / 2];
        now /= 2;
    }

    heap[now] = priority;
}

double dequeueEventHeap() {
    int  child, now;
    double minElement, lastElement;
    minElement = heap[1];

    lastElement = heap[end--];
    for (now = 1; now * 2 <= end; now = child) {
        child = now * 2;
        if (child != end && heap[child + 1] < heap[child]) {
            child++;
        }
        if (lastElement > heap[child]) {
            heap[now] = heap[child];
        } else {
            break;
        }
    }

    heap[now] = lastElement;
    return minElement;
}
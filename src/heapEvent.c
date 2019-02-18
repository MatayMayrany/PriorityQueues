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

int enqueueEventHeap(double priority) {
    end++;
    heap[end] = priority;
    int now = end;
    int enqCounter = 0;

    while (heap[now / 2] > priority) {
        enqCounter++;
        heap[now] = heap[now / 2];
        now /= 2;
    }

    heap[now] = priority;
    return enqCounter;
}

double dequeueEventHeap() {
    int child, now;
    deqCounterHeap = 0;
    double minElement, lastElement;
    minElement = heap[1];

    lastElement = heap[end--];
    for (now = 1; now * 2 <= end; now = child) {
        deqCounterHeap++;
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
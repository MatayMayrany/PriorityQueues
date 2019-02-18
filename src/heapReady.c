//
// Created by Louis on 2019-01-30.
//

#include <math.h>
#include<limits.h>
#include "heapReady.h"

int *heap;
int end;

void initReadyHeap(int maxSize) {
    heap = (int*)malloc(sizeof(int) * maxSize);

    heap[0] = INT_MAX;
}

void killReadyHeap() {
    free(heap);
}

int enqueueReadyHeap(int priority) {
    int enqCounter = 0;
    end++;
    heap[end] = priority;
    int now = end;
    while (heap[now / 2] < priority) {
        enqCounter++;
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = priority;
    return enqCounter;
}

int dequeueReadyHeap() {
    int maxElement, lastElement, child, now;
    int deqCounter = 0;
    maxElement = heap[1];
    lastElement = heap[end--];

    for (now = 1; now * 2 <= end; now = child) {
        deqCounter++;
        child = now * 2;
        if (child != end && heap[child + 1] > heap[child]) {
            child++;
        }

        if (lastElement < heap[child]) {
            heap[now] = heap[child];
        } else {
            break;
        }
    }

    heap[now] = lastElement;
    return deqCounter;
}
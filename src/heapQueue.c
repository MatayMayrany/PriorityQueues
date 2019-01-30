//
// Created by Louis on 2019-01-30.
//

#include "heapQueue.h"

int *heap;
int end;

int isHeapEmpty() {
    if (heap[0] == 0) {
        return 1;
    } else {
        return 0;
    }
}

void initHeap(int maxSize) {
    heap = (int*)malloc(sizeof(int) * maxSize);

    //tell our program the heap is empty
    // 0 is empty
    // 1 is not
    heap[0] = 0;
}

void enqueueHeap(int priority) {
    if (isHeapEmpty()) {
        //set heap is not empty
        heap[0] = 1;
        //set top of heap to our priority
        heap[1] = priority;
        //set the end of the array
        end = 1;
    } else {
        end++;
        heap[end] = priority;

        while (heap[end] > heap[end/2]) {
            heap[end] = heap[end/2];
            heap[end/2] = priority;
        }
    }
}

int dequeueHeap() {
    if (isHeapEmpty()) {
        printf("Can't dequeue from an empty queue... ");
        return 0;
    }

    //replace the value at root with value at the end of the heap
    int root = heap[1];
    heap[1] = heap[end];
    end--;

    int n = 1;

    //iterate through heap and reorder
    while ((heap[n] < heap[n*2] || heap[n] < heap[(n*2)+1]) && n < end) {
        //find largest child of our node
        int largestChild;

        //have to add extra condition to if to check that the second child exists
        if (heap[n*2] < heap[(n*2)+1] && (n*2)+1 < end +1) {
            largestChild = (n*2)+1;
        } else {
            largestChild = (n*2);
        }

        //replace our node with largest child
        int temp = heap[n];
        heap[n] = heap[largestChild];
        heap[largestChild] = temp;

        n = largestChild;
    }

    return root;
}

void printHeap() {
    if(isHeapEmpty()) {
        printf("Can't print heap as it is empty\n");
        return;
    }

    for (int i = 1; i < end+1; ++i) {
        printf("%d\n", heap[i]);
    }
}
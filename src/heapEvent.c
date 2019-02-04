//
// Created by Louis on 2019-02-04.
//

// double is the data type as we will use time stamps
// Heap will be minimum based as the lower the time stamp the higher the priority

#include "heapEvent.h"

int *heap;
int end;

void initEventHeap(int maxSize) {
    heap = (int*)malloc(sizeof(int) * maxSize);

    //tell our program the heap is empty
    // 0 is empty
    // 1 is not
    heap[0] = 0;
}

void killEventHeap() {
    free(heap);
}

int isEventHeapEmpty() {
    if (heap[0] == 0) {
        return 1;
    } else {
    return 0;
    }
}

void enqueueEventHeap(int priority) {
    if (isEventHeapEmpty()) {
        //set heap is not empty
        heap[0] = 1;
        //set top of heap to our priority
        heap[1] = priority;
        //set the end of the array
        end = 1;
    } else {
        end++;
        heap[end] = priority;
        int n = end;

        while (heap[n] < heap[n/2] && n > 1) {
            heap[n] = heap[n/2];
            heap[n/2] = priority;
            n = n/2;
        }
    }
}

int dequeueEventHeap() {
    if (isEventHeapEmpty()) {
        printf("Can't dequeue from an empty queue... ");
        return 0;
    }

    //replace the value at root with value at the end of the heap
    int root = heap[1];
    heap[1] = heap[end];
    end--;

    int n = 1;

    //iterate through heap and reorder
    while ((heap[n] > heap[n*2] || heap[n] > heap[(n*2)+1]) && n < end) {
        int smallestChild;

        //find smallest child of our node
        //have to add extra condition to check that the second child exists
        if (heap[(n*2)+1] < heap[n*2] && (n*2)+1 < end + 1) {
            smallestChild = (n*2)+1;
        } else {
            smallestChild = (n*2);
        }

        //replace our node with smallest child
        int temp = heap[n];
        heap[n] = heap[smallestChild];
        heap[smallestChild] = temp;

        n = smallestChild;
    }

    return root;
}

void printEventHeap() {
    if(isEventHeapEmpty()) {
        printf("Can't print heap as it is empty\n");
        return;
    }

    for (int i = 1; i < end+1; ++i) {
        printf("%d\n", heap[i]);
    }
}

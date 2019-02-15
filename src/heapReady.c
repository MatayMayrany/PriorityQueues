//
// Created by Louis on 2019-01-30.
//

#include "heapReady.h"

int *heap;
int end;

void initReadyHeap(int maxSize) {
    heap = (int*)malloc(sizeof(int) * maxSize);

    //tell our program the heap is empty
    // 0 is empty
    // 1 is not
    heap[0] = 0;
}

void killReadyHeap() {
    free(heap);
}

int isReadyHeapEmpty() {
    if (heap[0] == 0) {
        return 1;
    } else {
        return 0;
    }
}

void printReadyHeap() {
    if(isReadyHeapEmpty()) {
        printf("Can't print heap as it is empty\n");
        return;
    }
    printf("\n");
    for (int i = 1; i < end+1; ++i) {
        printf("[%d]-> %d", i, heap[i]);
    }
}

void enqueueReadyHeap(int priority) {
    if (isReadyHeapEmpty()) {
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
        while (heap[n] > heap[n/2] && n > 1) {
            heap[n] = heap[n/2];
            heap[n/2] = priority;
            n = n/2;
        }
    }
    //printReadyHeap();
}

void exchange(int i , int j) {
    int temp;
    temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

int dequeueReadyHeap() {
    //printReadyHeap();

    if (isReadyHeapEmpty()) {
        printf("Can't dequeue from an empty queue... ");
        return 0;
    }

    //replace the value at root with value at the end of the heap
    int root = heap[1];
    heap[1] = heap[end];

    end--;

    int parent = 1;
    int largestChild = 0;

    //iterate through heap and reorder
    while (parent*2 <= end) {
        //find largest child of our node
        //have to add extra condition to check that the second child exists
        if ((heap[parent*2] < heap[(parent*2)+1]) && (parent*2) < end) {
            largestChild = (parent*2)+1;
        } else {
            largestChild = parent*2;
        }

        if (heap[parent] >= heap[largestChild])
            break;

        //replace our node with largest child
        exchange(parent, largestChild);
        parent = largestChild;
    }

    return root;
}
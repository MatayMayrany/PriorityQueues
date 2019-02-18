//
// Created by Louis on 2019-01-30.
//

#include <math.h>
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

    int index = 1;
    int level = 0;
    int total = 50;
    while (index < end) {
        printf("\n");
        total/=2;

        while (index<pow(2, level+1) && index < end) {
            printf("%*c", total, ' ');
            printf(" [%d] ", heap[index]);
            index++;

        }

        level++;
    }
    printf("\n");

}

void enqueueReadyHeap(int priority) {
    end++;
    heap[end] = priority;
    int now = end;
    while (heap[now / 2] > priority) {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = priority;
}

void exchange(int i , int j) {
    int temp;
    temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

int dequeueReadyHeap() {
    if (isReadyHeapEmpty()) {
        printf("Can't dequeue from an empty queue... ");
        return 0;
    }

    //replace the value at root with value at the end of the heap
    int root = heap[1];
    heap[1] = heap[end];

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
    end--;

    return root;
}
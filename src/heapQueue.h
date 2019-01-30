//
// Created by Louis on 2019-01-30.
//

#ifndef SRC_HEAPQUEUE_H
#define SRC_HEAPQUEUE_H

#include <stdio.h>
#include <stdlib.h>

void initHeap(int maxSize);

void enqueueHeap(int priority);

int dequeueHeap();

void printHeap();

#endif //SRC_HEAPQUEUE_H
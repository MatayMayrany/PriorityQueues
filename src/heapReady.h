//
// Created by Louis on 2019-01-30.
//

#ifndef SRC_HEAPQUEUE_H
#define SRC_HEAPQUEUE_H

#include <stdio.h>
#include <stdlib.h>

void initReadyHeap(int maxSize);

void enqueueReadyHeap(int priority);

int dequeueReadyHeap();

#endif //SRC_HEAPQUEUE_H
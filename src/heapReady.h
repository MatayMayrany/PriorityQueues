//
// Created by Louis on 2019-01-30.
//

#ifndef SRC_HEAPREADY_H
#define SRC_HEAPREADY_H

#include <stdio.h>
#include <stdlib.h>

void initReadyHeap(int maxSize);

void killReadyHeap();

void enqueueReadyHeap(int priority);

int dequeueReadyHeap();

void printReadyHeap();

#endif //SRC_HEAPREADY_H
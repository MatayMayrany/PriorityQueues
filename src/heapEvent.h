//
// Created by Louis on 2019-02-04.
//

#ifndef SRC_HEAPEVENT_H
#define SRC_HEAPEVENT_H

#include <stdio.h>
#include <stdlib.h>

void initEventHeap(int maxSize);

void enqueueEventHeap(int priority);

int dequeueEventHeap();

#endif //SRC_HEAPEVENT_H

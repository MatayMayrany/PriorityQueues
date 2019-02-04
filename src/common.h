//
// Created by Louis on 2019-02-04.
//

#ifndef SRC_COMMON_H
#define SRC_COMMON_H

#include <stdio.h>
#include <stdlib.h>

//codes for testing
#define LIST_READY_CODE 1
#define HEAP_READY_CODE 2
#define LIST_EVENT_CODE 3
#define HEAP_EVENT_CODE 4

struct node {
    int priority;
    struct node* next;
};

#endif //SRC_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "common.h"

int main() {
    //First variable:
    //   For Ready testing is the number of times you want to test the enqueue dequeue operations
    //   For Event testing is the total size you want to the list to iterate
    printf("Priority Queue Experiments\n");
    int code;
    printf("Choose the type of priority queue implementation:\n 1 - List Ready\n 2 - Heap Ready\n 3 - List Event\n 4 - Heap Event\n ");
    scanf("%d",&code);
    int size;
    printf("Specify the size of the queue: ");
    scanf("%d",&size);
    int iterations;
    printf("Specify the number of iterations: ");
    scanf("%d",&iterations);

    test(iterations, code, size);

    return 0;
}


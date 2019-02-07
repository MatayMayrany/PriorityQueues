#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "common.h"

int main() {
    //First variable:
    //   For Ready testing is the number of times you want to test the enqueue dequeue operations
    //   For Event testing is the total size you want to the list to iterate'
    /*if you would like to test EVENT DRIVEN SIMLUATIONS insert the following:
     * (finalSize - initialSize, code, initialSize)
     * For READY QUEUES:
     * (iterations, code, initialSize)
     * */
    test(35, HEAP_READY_CODE, 10);

    return 0;
}


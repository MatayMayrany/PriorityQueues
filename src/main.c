#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "common.h"

int main() {
    //First variable:
    //   For Ready testing is the number of times you want to test the enqueue dequeue operations
    //   For Event testing is the total size you want to the list to iterate
    test(1100, HEAP_EVENT_CODE, 1000);

    return 0;
}


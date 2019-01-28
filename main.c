#include <stdio.h>
#include <slapi-plugin.h>
#include "linkedListQueue.h"

void testQueues() {
    enqueue(10);
    enqueue(20);
    enqueue(5);
    enqueue(10);

    int first = dequeue();
    int second = dequeue();
    int third = dequeue();
    int fourth = dequeue();

    printf("\n First %d Second %d Third %d Fourth %d ", first, second, third, fourth);
}

int main() {
    testQueues();
    printf("Heasdfasdfllo, World!\n");

    return 0;
}


//
// Created by Louis on 2019-02-05.
//

#include "listEvent.h"
#include "common.h"

struct node* head2 = NULL;

// create a new node to add to queue
struct node *makeEventNode(int priority) {
    struct node *new = malloc(sizeof(struct node));
    new->priority = priority;
    new->next = NULL;
    return new;
}

void enqueueEventList(double priority) {
    struct node *new = makeEventNode(priority);

    if (head2 == NULL) {
        head2 = new;
        return;
    }

    if (head2->priority > new->priority) {
        new->next = head2;
        head2 = new;
    } else {
        struct node *current = head2;

        while (current->next != NULL && current->next->priority <= new->priority)
            current = current->next;

        new->next = current->next;
        current->next = new;
    }
}

double dequeueEventList() {
    if (head2 == NULL) {
        printf("No elements in queue to pop");
        return 0;
    }

    struct node *current = head2;
    head2 = head2->next;
    free(current);

    return current->priority;
}

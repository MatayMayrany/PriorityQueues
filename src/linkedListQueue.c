#include <stdio.h>
#include <stdlib.h>


#include "linkedListQueue.h"

struct node* head = NULL;


// create a new node to add to queue
struct node *makeNode(int priority) {
    struct node *new = malloc(sizeof(struct node));
    new->priority = priority;
    new->next = NULL;
    return new;
}

void enqueue (int priority) {
    struct node *new = makeNode(priority);

    if (head == NULL) {
        head = new;
        return;
    }

    if (head->priority < new->priority) {
        new->next = head;
        head = new;
    } else {
        struct node *current = head;

        while (current->next != NULL && current->next->priority >= new->priority)
            current = current->next;

        new->next = current->next;
        current->next = new;
    }
}

// pop the head
int dequeue(){
    struct node* current = head;
    head = head->next;
    free(current);
    return current->priority;
}




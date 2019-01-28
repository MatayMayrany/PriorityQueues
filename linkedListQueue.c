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
        struct node *prev;

        while (current->next != NULL && current->next->priority >= new->priority) {
            prev = current;
            current = current->next;
        }

        prev->next = new;
        new->next = current;
    }

//    if (head == NULL) {
//        head = makeNode(priority);
//    } else {
//        struct node* current = head;
//        struct node* prev = current;
//
//        while(1) {
//            if (current->next == NULL) {
//                struct node *new = makeNode(priority);
//                prev->next = new;
//                new->next = current;
//                break;
//            } else if (current->priority < priority ){
//                struct node *new = makeNode(priority);
//                current->next = new;
//                break;
//            }
//
//            prev = current;
//            current = current->next;
//        }
//    }
}

// pop the head
int dequeue(){
    struct node* current = head;
    head = head->next;
    free(current);
    return current->priority;
}




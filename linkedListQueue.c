#include <stdio.h>
#include <stdlib.h>


#include "linkedListQueue.h"

struct node* head;

struct node *makeNode(int priority){
    struct node *new = malloc(sizeof(struct node));
    new->priority = priority;
    new->next = NULL;
    return new;
}

void insert(int priority){
    struct node *new = malloc(sizeof(struct node));
    new->priority = priority;
    new->next = NULL;
    return new;
}

void enqueue (int priority){
    if (head == NULL){
        head->priority = priority;
        head->next = NULL;
    }else{

        struct node* current = head;
        struct node* prev;
        
        while(current->next != NULL){
            if (current->priority >  priority){
                prev = current;
                current = current->next;
            }else{
                struct node *new = makeNode(priority);
                prev->next = new;
                new->next = current;
                //
            }
        }
    }
}


typedef struct singlyLinkedListQueue {
    struct node* head;
};

typedef struct node {
    int priority;
    struct node* next;
};

void enqueue(int priority);

int dequeue();

typedef struct singlyLinkedListQueue {
    struct node* head;
};

typedef struct node {
    int priority;
    struct node* next;
};

void enqueueList(int priority);


struct node* dequeueList();
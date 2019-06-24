#include "../chap2/list.h"

/* a struct that contains two stacks to simulate a queue FIFO*/
struct queue {
    Node *original;
    Node *reversecopy;
};

typedef struct queue queue;

/*create an empty queue*/
queue *create_queue(queue **pptrqueue) {
    queue *pnewqueue = malloc(sizeof(queue));
    pnewqueue -> original = 0;
    pnewqueue -> reversecopy = 0;
    *pptrqueue = pnewqueue;
    return pnewqueue;
}

/* delete a queue : note the reversed copy is 0 because is used 
 * just for pop operations and after every pop operation deleted*/
void delete_queue(queue **pptrqueue) {
    queue *ptrqueue = *pptrqueue;
    Node *original = ptrqueue -> original;
    /*Node *reversecopy = ptrqueue -> reversecopy;*/
    delete_list(&original);
    /*delete_list(&reversecopy);*/
    free(ptrqueue);
}

/* Returns the length of the queue */
size_t length_queue(queue *pqueue) {
    Node *original = pqueue -> original;
    return length_list(original);
}

/*Return 0 if and only if the queue is empty.*/
int queue_is_empty(queue *pqueue) {
    Node *original = pqueue -> original;
    if (original == 0) {
        return 1;
    }
    return 0 == length_queue(pqueue);
}

/* push the data to the original stack*/
void queue_add(queue *pqueue, int data) {
    if (0 == pqueue -> original) {
        create_list(&(pqueue -> original), &data, 1);
    } else {
        push(&(pqueue -> original), data);    
    }
}

/*to remove the first element from the original queue, 
 * create a reverse copy and pop the last element, after copy the
 * reversecopy stack in the original stack */
/*helper function to pass all elements from one stack to another*/
void move(Node **dest, Node **src) {
    size_t len = length_list(*src), i;
    int data;
    for (i = 0; i < len; ++i) {
        data = pop(src);
        push(dest, data);
    }
}

int queue_remove(queue *pqueue) {
    int first;
    if (!queue_is_empty(pqueue)) {
        first = pop(&(pqueue ->original));
        create_list(&(pqueue ->reversecopy), &first, 1);
        move(&(pqueue -> reversecopy), &(pqueue -> original));
        first = pop(&(pqueue ->reversecopy));
        move(&(pqueue ->original), &(pqueue ->reversecopy)); 
        return first;
    }
    printf("queue_remove error: empty queue");
    return -1;
}


int main() {
    queue *pqueue = 0;
    pqueue = create_queue(&pqueue);
    printf("queue is empty: %d\n", queue_is_empty(pqueue));
    queue_add(pqueue, 10);
    queue_add(pqueue, 20);
    queue_add(pqueue, 30);
    printf("FIFO : remove element %d\n", queue_remove(pqueue));
    printf("queue is empty: %d\n", queue_is_empty(pqueue));
    printf("FIFO : remove element %d\n", queue_remove(pqueue));
    printf("queue is empty: %d\n", queue_is_empty(pqueue));
    printf("FIFO : remove element %d\n", queue_remove(pqueue));
    printf("queue is empty: %d\n", queue_is_empty(pqueue));
    delete_queue(&pqueue);

    return 0;
}

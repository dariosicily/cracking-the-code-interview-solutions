#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node Node;

void push(Node **head, int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = *head;
    *head = new_node;
}

int pop(Node **head) {
    Node *next = (*head) -> next;
    int data = (*head) -> data;
    free(*head);
    *head = next;
    return data;
}

Node *create_list(Node **head, int data[], size_t size) {
    int i;
    for (i = size - 1; i >= 0; --i) 
        push(head, data[i]);
    return *head;
}

void delete_list(Node **head) {
    if (head) {
        for (; *head;) {
            pop(head);       
        }    
    }
}

void print_list(Node *head) {
    printf("[");
    if (head) {
        printf("%d", head -> data);
        head = head -> next;
    }
    for (; head; head = head -> next) {
        printf(",%d", head -> data);
    }
    printf("]");
}

size_t length_list(Node *head) {
    size_t len = 0;
    for (; head; head = head -> next, ++len) {}
    return len;
}

int is_empty_list(Node *head) {
    return 0 == length_list(head);
}
#endif


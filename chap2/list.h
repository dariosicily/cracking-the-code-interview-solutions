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
    Node *new_node = malloc(sizeof(Node));
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
    for (; *head;) {
        pop(head);       
    }
}

void print_list(Node* head) {
    printf("[");
    for (; head; head = head -> next) {
        printf("%d ", head -> data);
    }
    printf("]\n");
}

size_t length_list(Node* head) {
    size_t len = 0;
    for (; head; head = head -> next, ++len) {}
    return len;
}
#endif


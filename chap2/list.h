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

void create_list(Node **head, int data[], size_t size) {
    int i;
    for (i = size - 1; i >= 0; --i) 
        push(head, data[i]);
}

void delete_list(Node **head) {
    while (*head) pop(head);
}

void print_list(Node* head) {
    while (head) {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}



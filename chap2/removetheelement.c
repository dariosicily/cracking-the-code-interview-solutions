#include "list.h"

Node **remove_the_element(Node **pptr, Node *elem) {
    Node *head = *pptr, *prev = 0, *next;
    while (head != elem) {
        prev = head;
        head = head -> next;
    }
    next = head -> next;
    free(head);
    prev -> next = next;
    return pptr;
}

Node *find_the_nth_node(Node * head, int n) {
    int index = 0;
    while (index < n) {
        head = head -> next;
        ++index;
    }
    return head;
}

int main() {
    int data[] = {0, 2, 3, 2, 4, 4, 3, 3, 1};
    size_t size = sizeof(data) / sizeof(data[0]);
   Node *head = 0;
    create_list(&head, data, size);
    print_list(head);
    remove_the_element(&head, find_the_nth_node(head, 3));
    print_list(head);
    delete_list(&head);
    return 0;
}

#include "list.h"
#include <string.h>

void delete_the_nth_element(Node **phead, Node *deleted, int index) {
    int n = 0;
    Node *current = *phead;
    Node *prev = 0;
    Node *next = 0;
    while (current != 0 && n < index) {
        if (n == index) {
            next = current -> next;
            free(current);
            prev -> next = next;
            if (0 == deleted) {

            }
            break;
        }
        ++n;
        prev = current;
        current = current -> next;
    }
}

int main() {
    int data[] = {0, 2, 3, 2, 4, 4, 3, 3, 1};
    size_t size = sizeof(data) / sizeof(data[0]);
    Node *head = 0;
    Node *deleted = 0;
    create_list(&head, data, size);
    print_list(head);
    delete_the_nth_element(&head, deleted, 1);
    print_list(head);
    delete_list(&head);
    return 0;
}

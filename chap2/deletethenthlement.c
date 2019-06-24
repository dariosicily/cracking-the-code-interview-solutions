#include "list.h"
#include <string.h>

/*delete the element at the index*/
int delete_the_nth_element(Node **phead, int index) {
    int n = 0, data;
    Node *current = *phead;
    Node *prev = 0;
    Node *next = 0;

    /*check if the element to delete is the head */
    if (index == 0) {
        data = current -> data;
        next = current -> next;
        free(current);
        *phead = next;
        return data;
    }
 
    while (current) {
        if (n == index) {
            next = current -> next;
            data = current -> data;
            free(current);
            prev -> next = next;
            return data;
        }
        ++n;
        prev = current;
        current = current -> next;
    }
    printf("delete error: element does not exist\n");
    return -1;
}

int main() {
    int data[] = {0, 2, 3, 2, 4, 4, 3, 3, 1};
    size_t size = sizeof(data) / sizeof(data[0]);
    Node *head = 0;
    create_list(&head, data, size);
    print_list(head);
    printf("\n");
    delete_the_nth_element(&head, 0);
    print_list(head);
    delete_list(&head);
    return 0;
}

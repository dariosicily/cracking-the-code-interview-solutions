#include "list.h"

/* remove the Node elem from the list*/
Node **remove_the_element(Node **pptr, Node *elem) {
    if (elem) {
        Node *head = *pptr, *prev = 0, *next;
        while (head != elem) {
            prev = head;
            head = head -> next;
        }
        next = head -> next;
        free(head);
        prev -> next = next;
    }
    return pptr;
}

Node *find_the_nth_node(Node * head, int n) {
    int index;
    for (index = 0; head != 0 && index < n; ++index) {
        head = head -> next;
    }
    /*check if list has less than n - 1 elements and in that case return 0
     * thanks to https://www.reddit.com/user/valbaca */
    if (head == 0 && index < n - 1) return 0;
    return head;
}

int main() {
    int data[] = {0, 2, 3, 2, 4, 4, 3, 3, 1};
    size_t size = sizeof(data) / sizeof(data[0]);
    Node *head = 0;
    create_list(&head, data, size);
    print_list(head);
    printf("\n");
    remove_the_element(&head, find_the_nth_node(head, 3));
    print_list(head);
    delete_list(&head);
    return 0;
}

#include "list.h"

Node *find_nth_to_last_element(Node *head, int n) {
    int index = 0;
    while (index <  n) {
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
    print_list(find_nth_to_last_element(head, 2));
    print_list(head);
    delete_list(&head);
    return 0;
}

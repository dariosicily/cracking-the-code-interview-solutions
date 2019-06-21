#include "list.h"

/*return the sublist starting from nth element otherwise return 0*/
Node *find_nth_to_last_element(Node *head, int n) {
    int index;
    for (index = 0;head && index < n;head = head -> next, ++index) {}
    /*the list contains less than n - 1 elements*/
    if (head == 0 && index < n - 1) return 0;
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

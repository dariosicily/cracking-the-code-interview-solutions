#include "list.h"

/*without use of an auxiliary buffer the only option is a two nested loop
 * that compares every element of the list with the element on the right side until the end*/

Node **remove_duplicates(Node **pptr) {
    Node *ptr = *pptr;
    Node *prev = 0;
    Node *currenti, *currentj;
    for (currenti = ptr; currenti != 0; currenti = currenti -> next) {
        prev = currenti;
        for (currentj = currenti -> next; currentj != 0; currentj =
                currentj -> next) {
            if (currenti -> data == currentj -> data) {
                
                /*delete the element currentj and update the pointers*/
                prev -> next = currentj -> next;
                free(currentj);
                currentj = prev;
            }
            prev = currentj;
        }
    }
    return pptr;
}


int main() {
    int data[] = {0, 2, 3, 2, 4, 4, 3, 3, 1};
    size_t size = sizeof(data) / sizeof(data[0]);
    Node *head = 0;
    create_list(&head, data, size);
    print_list(head);
    printf("\n");
    remove_duplicates(&head);
    print_list(head);
    delete_list(&head);
    return 0;
}

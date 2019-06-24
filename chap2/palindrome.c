#include <stdio.h>

#include"list.h"

/*Assume to use a stack to memorize original list elements in reverse
 * order*/
int is_palindrome(Node* head) {
    int ret = 1;
    Node *reverse = 0;
    Node *copyreverse = 0;
    Node *copyhead = head;

    /* use a new list to copy the original list in reverse order */
    while (copyhead) {
        push(&reverse, copyhead -> data);
        copyhead = copyhead -> next;
    }
    
    copyreverse = reverse;
    
    /*check if the reverse and original have the same elements*/
    while (head) {
        if (head -> data != reverse -> data) {
            ret  = 0;
            break;
        }
        head = head -> next;
        reverse = reverse -> next;
    }

    delete_list(&copyreverse);
    return ret;
}

int main() {
    int data[] = {7, 2, 7};
    size_t size = sizeof(data) / sizeof(data[0]);
    Node *head = 0;
    create_list(&head, data, size);
    print_list(head);
    printf("\n");
    printf("%d\n", is_palindrome(head));
    delete_list(&head);
    return 0;
}

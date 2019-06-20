#include <stdio.h>
#include <string.h>
#include "list.h"

int list_to_int(Node * head) {
    int digits[20] = { 0 };
    int n = 0, i = 0, ndigits = 0;
    while (head) {
        digits[ndigits++] = head -> data;
        head = head -> next;
    }
    for(i = ndigits - 1; i >= 0; --i) {
        n = (n * 10) + digits[i];
    }
    return n;
}

int main() {
    int datafirst[] = {7, 1, 6};
    int datasecond[] = {5, 9, 2};
    size_t size = sizeof(datafirst) / sizeof(datafirst[0]);
    Node *first = 0;
    Node *second = 0;
    create_list(&first, datafirst, size);
    create_list(&second, datasecond, size);
    print_list(first);
    print_list(second);
    printf("The sum of the two lists is %d\n", 
            list_to_int(first) + list_to_int(second));
    delete_list(&first);
    delete_list(&second);
    return 0;
}

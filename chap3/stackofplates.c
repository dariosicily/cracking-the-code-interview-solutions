#include "../chap2/list.h"

/*a structure that can contain a variable number of stacks that will
 * contain a max of sz number of elements for stack  */
struct setofstacks {
    size_t sz;
    size_t nstacks;
    Node **stacks;
};

typedef struct setofstacks setofstacks;

/*function that creates an empty setofstacks */
setofstacks *create_setofstacks(setofstacks **ppset, size_t size) {
    setofstacks *pset;
    pset = malloc(sizeof(setofstacks));
    pset -> sz = size;
    pset -> nstacks = 0;
    pset -> stacks = 0;
    *ppset = pset;
    return pset;
}

/*a special type of push : the new element will be pushed in the last stack of the set that is not full or a new stack of the set will be created to 
 * contain it*/
void setofstacks_push(setofstacks *pset, int data) {
    size_t sz = pset -> sz;
    size_t nstacks = pset -> nstacks, i;
    int index = -1;
    Node **stacks = pset -> stacks;
    Node *newstack = 0;

    /* find a not empty stack or create a new one and store data in it*/
    for (i = 0; i < nstacks; ++i) {
        if (length_list(stacks[i]) < sz) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        
        /*create a new stack*/
        newstack = create_list(&newstack, &data, 1);
        index = nstacks;
        
        if (nstacks == 0) {
            pset -> stacks = (Node**)malloc(sizeof(Node*));
        } else {
            pset -> stacks = (Node**) realloc(pset -> stacks, 
                    sizeof(Node*) *(nstacks + 1));
        }
        (pset -> stacks)[index] = newstack;
        ++(pset -> nstacks);
    } else {
        push(&((pset -> stacks)[index]), data);
    }
}
/*
int setofstacks_pop() {

}

int popAt(size_t index) {

}*/

/* function that deletes all the stacks*/
void delete_setofstacks(setofstacks *set) {
    size_t nstacks = set -> nstacks, i;
    Node **stacks = set -> stacks;
    if (stacks) {
        for (i = 0; i < nstacks; ++i) {
            delete_list(&stacks[i]);
            free(stacks[i]);
        }
        free(stacks);
    }
    free(set);
}

/* print the nested list */
void print_setofstacks(setofstacks set) {
    Node **stacks = set.stacks;
    size_t nstacks = set.nstacks, i;

    printf("[");
    if (nstacks > 0) {
        print_list(stacks[0]);
    }
    for (i = 1; i < nstacks; ++i) {
        if (stacks[i]) {
            printf(",");
            print_list(stacks[i]);
        }
    }
    printf("]");

}

int main() {
    setofstacks *set;
    set = create_setofstacks(&set, 2);
    print_setofstacks(*set);
    printf("\n");
    setofstacks_push(set, 100);
    setofstacks_push(set, 200);
    setofstacks_push(set, 300);
    /*setofstacks_push(set, 300);*/
    print_setofstacks(*set);
    delete_setofstacks(set);
    return 0;
}

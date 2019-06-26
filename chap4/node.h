#ifndef NODE_H
#define NODE_H
typedef struct node node;
typedef struct tree tree;
typedef struct graph graph;

struct node {
    size_t name;
    node *children;
};

struct tree {
    node root;
};

/*The java structure used in the book for graph contains 
 * an array for nodes, I emulate that using a pointer 
 * for allocated structure and size_t for the number of nodes */
struct graph {
    size_t nnodes;
    node *nodes;
};
#endif



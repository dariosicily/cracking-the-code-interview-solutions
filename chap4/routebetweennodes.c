#include <stdio.h>
#include <stdlib.h>

#include "node.h"

/*Given a directed graph, design an algorithm to find out 
 * whether there is a route between two nodes. */


/*create an empty graph (no nodes, no edges) */
graph *create_graph(graph **ppgraph) {
    graph *pgraph = malloc(sizeof(graph));
    pgraph -> nodes = 0;
    pgraph -> nnodes = 0;
    *ppgraph = pgraph;
    return pgraph;
}


void add_node_to_graph(graph *pgraph, size_t name) {
    size_t nnodes;
    node *newnode;
    node *nodes = pgraph -> nodes;
    nnodes = pgraph -> nnodes;
    newnode = malloc(sizeof(node));
    newnode -> name = name;
    newnode -> children = 0;
    if (nodes == 0) {
        pgraph -> nodes = newnode;
        pgraph -> nnodes = 1;
    } else {
        pgraph -> nodes = (node*) realloc(pgraph -> nodes, 
                sizeof(node) * (nnodes + 1));
        (pgraph -> nodes)[nnodes] = *newnode;
        ++(pgraph -> nnodes);
        free(newnode);
    }
}

void print_graph(graph *pgraph) {
    size_t nnodes, i;
    node *nodes = pgraph -> nodes;
    nnodes = pgraph -> nnodes;
    printf("{");
    for (i = 0; i < nnodes; ++i) {
        printf("{");
        printf("%lu", nodes[i].name);
        printf("} ");
    }
    printf("}");
    
}



/* delete the graph */
void delete_graph(graph **ppgraph) {
    size_t i, nnodes;
    node *nodes;
    graph *pgraph = *ppgraph;
    nodes = pgraph -> nodes;
    nnodes = pgraph -> nnodes;
    for (i = 0; i < nnodes; ++i) {
        if (nodes[i].children)
            free(nodes[i].children);
    }
    free(pgraph -> nodes);
    free(pgraph);
    *ppgraph  = 0;
}

int main() {
    graph *pgraph = 0;
    create_graph(&pgraph);
    print_graph(pgraph);
    printf("\n");
    add_node_to_graph(pgraph, 0);
    add_node_to_graph(pgraph, 1);
    print_graph(pgraph);
    delete_graph(&pgraph);
    return 0;
}

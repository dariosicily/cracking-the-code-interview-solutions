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

/*helper function that add a new node to the array or create a new
 * one array in the case of the first node to insert*/
node **add_node_to_array(node **pnodes, size_t name, size_t nnodes) {
    node *newnode;
    node *nodes = *pnodes; 
    newnode = malloc(sizeof(node));
    newnode -> name = name;
    newnode -> nchildren = 0;
    newnode -> children = 0;
    if (0 == nodes) {
        nodes = newnode;
    } else {
        nodes = (node*) realloc(nodes, 
                sizeof(node) * (nnodes + 1));
        nodes[nnodes] = *newnode;
        free(newnode);
    }
    *pnodes = nodes;
    return pnodes;
}


void  add_node_to_graph(graph *pgraph, size_t name) {
    size_t nnodes;
    /*node *nodes = pgraph -> nodes;*/
    nnodes = pgraph -> nnodes;
    add_node_to_array(&pgraph -> nodes, name, nnodes);
    /*newnode = malloc(sizeof(node));
    newnode -> name = name;
    newnode -> children = 0;
    if (nodes == 0) {
        pgraph -> nodes = newnode;
        pgraph -> nnodes = 1;
    } else {
        pgraph -> nodes = (node*) realloc(pgraph -> nodes, 
                sizeof(node) * (nnodes + 1));
        (pgraph -> nodes)[nnodes] = *newnode;*/
        ++(pgraph -> nnodes);
        /*free(newnode);
    }*/
}

int graph_is_empty(graph *pgraph) {
    node *nodes = pgraph -> nodes;
    return 0 == nodes;
}

int graph_contains_node(graph *pgraph, size_t name) {
    size_t nnodes, i;
    node *nodes = pgraph -> nodes;
    nnodes = pgraph -> nnodes; 
    for (i = 0; i < nnodes; ++i) {
        if(nodes[i].name == name) return 1;
    }
    return 0;
}


void add_edge_to_graph(graph *pgraph, size_t startpoint, size_t endpoint) {
    size_t index;
    node *children; 
    
    if (graph_is_empty(pgraph) || 
    !graph_contains_node(pgraph, startpoint)) add_node_to_graph(pgraph, startpoint);
    if (!graph_contains_node(pgraph, endpoint)) add_node_to_graph(pgraph, endpoint);
   /* add node endpoint to the children of node startpoint */ 
    index = pgraph -> nnodes - 1;
    children = pgraph -> nodes[index].children;

    add_node_to_array(&(pgraph -> nodes[index].children), endpoint, 
            (pgraph- nodes[index]).nnodes);
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

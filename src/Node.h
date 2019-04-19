#include <stdlib.h>

#ifndef Node_class

#define Node_class
typedef struct _Node {
    /* class methods */
    struct _Node* (*destroy)(struct _Node *self);

    /* attributes */
    int data;
    struct _Node *prev;
    struct _Node *next;
} Node;

/* constructor */
Node* new_Node(int data);
/* public methods */
Node* ___destroy_node(Node *self);


Node* new_Node(int data) {
    Node *n =  (Node *) malloc (sizeof (Node) );

    /* Assigning attributes */
    n->data = data;
    /* Assigning methods */
    n->destroy = &___destroy_node;
    return n;
}

Node* ___destroy_node(Node *self) {
    Node *node_next = self->next;
    free(self);
    return node_next;
}

#endif
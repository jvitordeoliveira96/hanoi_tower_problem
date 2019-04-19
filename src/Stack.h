#include "LinkedList.h"

#ifndef Stack_class
#define Stack_class

typedef struct _Stack {
    /* class methods */
    void (*push)(struct _Stack *self, Node *node);
    Node* (*pop)(struct _Stack *self);
    void (*print)(struct _Stack *self);

    /* attributes */
    LinkedList *___stack_list;
} Stack;

/* constructor */
Stack *new_Stack();    
/* public methods */
void  ___push_____stack___(Stack *self, Node *node);
Node* ___pop_____stack___(Stack *self);
void ___print_____stack___(Stack *self);


Stack *new_Stack() {
    /* allocating memory */
    Stack *stack = (Stack *) malloc ( sizeof(Stack) );
    
    
    /* Assigning attributes */
    stack->___stack_list = new_LinkedList();
    
    /* Assigning methods */
    stack->push = &___push_____stack___;
    stack->pop = &___pop_____stack___;
    stack->print = &___print_____stack___;

    return stack;
}

void  ___push_____stack___(Stack *self, Node *node) {
    self->___stack_list->add_first( self->___stack_list, node );
}

Node*  ___pop_____stack___(Stack *self) {
    return self->___stack_list->remove_first( self->___stack_list );
}

void ___print_____stack___(Stack *self) {
    self->___stack_list->println(self->___stack_list);
}




#endif




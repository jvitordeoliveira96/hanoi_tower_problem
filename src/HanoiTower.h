#include "Stack.h"
#include <stdio.h>

#ifndef HanoiTower_class
#define HanoiTower_class


typedef struct _HanoiTower {
    /* class methods */
    void (*print)(struct _HanoiTower *self);
    void (*simulate)(struct _HanoiTower *self);

    /* attributes */
    Stack *___stack_a, *___stack_b, *___stack_c;
    int ___ndisks;
} HanoiTower;

/* constructor */
HanoiTower *new_HanoiTower(int ndisks);    
/* private methods */
void moveDisk(HanoiTower *self, int n, Stack *stack_src, Stack *stack_temp, Stack *stack_dest);
/* public methods */
void ___print_____htower___(HanoiTower *self);
void ___simulate_____htower___(HanoiTower *self);  



HanoiTower *new_HanoiTower(int ndisks) {
    /* allocating memory */
    HanoiTower *htower = (HanoiTower *) malloc ( sizeof(HanoiTower) );
    /* generating initial stacks */
    Stack *stack_a = new_Stack();
    Stack *stack_b = new_Stack();
    Stack *stack_c = new_Stack();
    int i;
    
    /* filling initial stack */
    for(i = ndisks; i > 0; i--) {
        stack_a->push( stack_a, new_Node(i) );
    }
    
    /* Assigning attributes */
    htower->___stack_a = stack_a;
    htower->___stack_b = stack_b;
    htower->___stack_c = stack_c;
    htower->___ndisks = ndisks;
    /* Assigning methods */
    htower->print = &___print_____htower___;
    htower->simulate = &___simulate_____htower___; 


    return htower;
}


int ___get_ndisks_____htower___(HanoiTower *self) {
    return self->___ndisks;
}

void ___print_____htower___(HanoiTower *self) {
    printf("++++++++++++++ Tower A ++++++++++++++++++\n");
    self->___stack_a->print(self->___stack_a);
    printf("++++++++++++++ Tower B ++++++++++++++++++\n");
    self->___stack_b->print(self->___stack_b);
    printf("++++++++++++++ Tower C ++++++++++++++++++\n");
    self->___stack_c->print(self->___stack_c);
}

void ___simulate_____htower___(HanoiTower *self) {
    /* printing results */
    printf("\n **************** \n Starting simulation: \n");
    self->print(self);
    moveDisk(self, self->___ndisks, self->___stack_a, self->___stack_b, self->___stack_c);
}

void moveDisk(HanoiTower *self, int n, Stack *stack_src, Stack *stack_temp, Stack *stack_dest) {
    /* check if base case of not */
    if(n > 0) {
        /* move all n - 1 disks to the temporary stack */
        moveDisk(self, n - 1, stack_src, stack_dest, stack_temp);

        /* moving the last disk from the source stack to the destination stack */
        stack_dest->push(stack_dest, stack_src->pop(stack_src) );

        /* printing results */
        printf("\n **************** \n Iteration: \n");
        self->print(self);

        /* move the n - 1 disks deposited previously on the temporary stack to the destination */
        moveDisk(self, n - 1, stack_temp, stack_src, stack_dest); 
    }    
}



#endif













































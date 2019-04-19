#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include <time.h>
#define RANDR 120
           

int main(void) {
    
    srand(time(NULL));  /* random number seed */    
    Stack *stack = new_Stack();  /*  creating a Stack */

    /* filling stack */
    stack->push(stack, new_Node( rand() %RANDR ));
    stack->print(stack);
    stack->push(stack, new_Node( rand() %RANDR ));
    stack->print(stack);    
    stack->push(stack, new_Node( rand() %RANDR ));
    stack->print(stack);
    
    
    /* after  first pop*/
    stack->pop(stack);
    stack->print(stack);
    /* after only one element remains  */
    stack->pop(stack);
    stack->print(stack);
    
    /* after the list ends up empty  */
    stack->pop(stack);
    stack->print(stack);

    /* adding one element again    */
    stack->push(stack, new_Node( rand() %RANDR ));
    stack->print(stack);


    return 0;
}
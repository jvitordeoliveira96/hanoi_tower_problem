#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <time.h>
#define RANDR 120
           

int main(void) {
    LinkedList *list = new_LinkedList();  /*  creating a LinkedList */
    srand(time(NULL));  /* random number seed */

    /* filling list */
    list->add_last(list, new_Node( rand() %RANDR ) );
    list->println(list);
    list->add_last(list, new_Node( rand() % RANDR) );
    list->println(list);
    list->add_last(list, new_Node( rand() % RANDR) );    
    list->println(list);
    list->add_last(list, new_Node( rand() % RANDR) );
    list->println(list);
    
    /* after deleting head and tail */
    list->remove_last(list);
    list->remove_first(list);
    list->println(list);

    /* after only one element remains  */
    list->remove_last(list);
    list->println(list);
    
    /* after the list ends up empty  */
    list->remove_last(list);
    list->println(list);

    /* adding one element again    */
    list->add_first(list, new_Node(-58259));
    list->println(list);

    list->destroy(list);

    return 0;
}
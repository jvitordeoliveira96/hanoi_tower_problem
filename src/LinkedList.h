#include "Node.h"
#include <stdio.h>

#ifndef LinkedList_class
#define LinkedList_class



typedef struct _LinkedList {
    /* class methods */
    void (*add_first)(struct _LinkedList *self, Node *node);
    void (*add_last)(struct _LinkedList *self, Node *node);
    Node * (*find)(struct _LinkedList *self, Node *knode);
    Node * (*remove) (struct _LinkedList *self, Node *knode);
    Node * (*remove_first) (struct _LinkedList *self);
    Node * (*remove_last) (struct _LinkedList *self);
    void (*print)(struct _LinkedList *self);
    void (*println)(struct _LinkedList *self);
    void (*destroy)(struct _LinkedList *self);

    /* attributes */
    Node *head;
    Node *tail;
} LinkedList;

/* constructor */
LinkedList *new_LinkedList();
/* public methods */
void _______list_add_first(LinkedList *self, Node *node);
void _______list_add_last(LinkedList *self, Node *node);
void _______list_print(LinkedList *self);
void _______list_print_vert(LinkedList *self);
Node *_______list_find(LinkedList *self, Node *knode);
Node * _______list_remove(LinkedList *self, Node *node);
Node* _______list_remove_general(LinkedList *self, Node *knode);
Node* _______list_remove_first(LinkedList *self);
Node* _______list_remove_last(LinkedList *self);
void  _______destroy_linkedlist(LinkedList *self);


LinkedList *new_LinkedList() {
    LinkedList *list =  (LinkedList *) malloc ( sizeof(LinkedList) );
    
    /* Assigning methods */
    list->add_first = &_______list_add_first;
    list->add_last = &_______list_add_last;
    list->print = &_______list_print;
    list->println = &_______list_print_vert;
    list->find = &_______list_find;
    list->remove = &_______list_remove;
    list->remove_first = &_______list_remove_first;
    list->remove_last = &_______list_remove_last;
    list->destroy = &_______destroy_linkedlist;
    
    return list;
}


void _______list_add_first(LinkedList *self, Node *node) {
    node->next = self->head;
    if( (self->head) ) { /* if head is not empty */
        self->head->prev = node;
    }

    self->head = node;

    if( !(self->tail) ) { /* if tail is empty */
        self->tail = self->head; 
    } 

    node->prev = NULL; /* not necessary, just for readability */

}

void _______list_add_last(LinkedList *self, Node *node) {
    node->prev = self->tail;
    if( (self->tail) ) { /* if tail is not empty */
        self->tail->next = node;
    }
    
    self->tail = node;
    
    if( !(self->head) ) { /* if head is empty */
        self->head = self->tail; 
    } 
    
    node->next = NULL; /* not necessary, just for readability  */

}

void _______list_print(LinkedList *self) {
    Node *node = self->head;

    /* checking if list is empty */
    if(!node) {
        printf("The list is empty.\n");
    }

    else { 
        /* until tail is found, print out node and head for the next one  */
        while(node) {
            printf("|%d| ", node->data);
            node = node->next;
        }
        /* printf("\nHead is: %d, tail is: %d\n", self->head->data, self->tail->data); */
    } 

}

void _______list_print_vert(LinkedList *self) {
    Node *node = self->head;
    
    /* Separating previous prints */
    printf("------------------------------------\n");
    /* checking if list is empty */
    if(!node) {
        printf("| |\n");
    }

    else { 
        /* until tail is found, print out node and head for the next one  */
        
        while(node) {
            printf("|%d|\n", node->data);
            node = node->next;
        }
        /* printf("\nHead is: %d, tail is: %d\n", self->head->data, self->tail->data); */     
    } 

}

Node *_______list_find(LinkedList *self, Node *knode) {
    Node *node = self->head;
    while(node->next) {
        if(node->data == knode->data) return node;
        node = node->next;
    }
    if(node->data == knode->data) return node;
    else return NULL; 

}

Node * _______list_remove(LinkedList *self, Node *node) {
    if(node) {
        if(node->prev) node->prev->next = node->next;
        else self->head = node->next;  /* update head if the first one is deleted */
        
        if(node->next) node->next->prev = node->prev;
        else self->tail = node->prev; /* update tail if the last one is deleted */
    }    

    return node;
}

Node* _______list_remove_general(LinkedList *self, Node *knode) {
    Node *node = _______list_find(self, knode);
    return _______list_remove(self, node);
}

Node* _______list_remove_first(LinkedList *self) {
    Node *node = self->head;
    return _______list_remove(self, node);
}

Node* _______list_remove_last(LinkedList *self) {
    Node *node = self->tail;
    return _______list_remove(self, node);
}

void  _______destroy_linkedlist(LinkedList *self) {
    /* freeing attributes */
    Node *node = self->head;
    while(node) {
        node = node->destroy(node);
    }
    /* freeing class */
    free(self);
}

#endif
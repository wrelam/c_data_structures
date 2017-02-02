/***************************************************************************//**
    @file   doubly_linked_list.h

    @brief  Interface to the doubly linked list library
*******************************************************************************/
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <string.h>

#define NULL_NODE   NULL

typedef struct dll_node {
    struct dll_node *next;
    struct dll_node *prev;
    void *data;
} * dll_node;

dll_node
dll_create_node(void);

void
dll_destroy_node(dll_node elem);

#endif /* DOUBLY_LINKED_LIST_H */


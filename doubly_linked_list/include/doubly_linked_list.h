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

dll_node
dll_insert_after(dll_node elem, dll_node new);

dll_node
dll_insert_at_end(dll_node elem, dll_node new);

dll_node
dll_insert_before(dll_node elem, dll_node new);

void
dll_remove(dll_node elem)

#endif /* DOUBLY_LINKED_LIST_H */


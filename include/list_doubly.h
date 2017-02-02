/***************************************************************************//**
    @file   doubly_linked_list.h

    @brief  Interface to a doubly linked list implementation
*******************************************************************************/
#ifndef LIST_DOUBLY_H
#define LIST_DOUBLY_H

#include <string.h>

#ifndef NULL_NODE
#define NULL_NODE   NULL
#endif /* NULL_NODE */

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
dll_remove(dll_node elem);

#endif /* LIST_DOUBLY_H */


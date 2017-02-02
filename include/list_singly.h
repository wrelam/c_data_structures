/***************************************************************************//**
    @file   list_singly.h

    @brief  Interface to a singly linked list implementation
*******************************************************************************/
#ifndef LIST_SINGLY_H
#define LIST_SINGLY_H

#include <string.h>

#ifndef NULL_NODE
#define NULL_NODE   NULL
#endif /* NULL_NODE */

typedef struct sll_node {
    struct sll_node *next;
    void *data;
} * sll_node;

sll_node
sll_create_node(void);

void
sll_destroy_node(sll_node elem);

sll_node
sll_insert_after(sll_node elem, sll_node new);

sll_node
sll_insert_at_end(sll_node elem, sll_node new);

sll_node
sll_insert_before(sll_node elem, sll_node new);

sll_node
sll_remove_after(sll_node elem);

sll_node
sll_reverse_list(sll_node head);

#endif /* LIST_SINGLY_H */


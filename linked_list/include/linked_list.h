/***************************************************************************//**
    @file   linked_list.h

    @brief  Interface to the linked list library
*******************************************************************************/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct ll_node {
    struct ll_node *next;
    void *data;
} * ll_node;

ll_node
ll_create_node(void);

void
ll_destroy_node(ll_node elem);

ll_node
ll_insert_after(ll_node elem, ll_node new);

ll_node
ll_insert_before(ll_node elem, ll_node new);

ll_node
ll_insert_at_end(ll_node elem, ll_node new);

#endif /* LINKED_LIST_H */


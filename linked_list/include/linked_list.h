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
ll_destroy_node(ll_node node);

ll_node
ll_insert_after(ll_node base, ll_node new);

#endif /* LINKED_LIST_H */


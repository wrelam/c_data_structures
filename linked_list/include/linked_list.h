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

#endif /* LINKED_LIST_H */


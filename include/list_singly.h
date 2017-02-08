/***************************************************************************//**
    @file   list_singly.h

    @brief  Interface to a singly linked list implementation
*******************************************************************************/
#ifndef LIST_SINGLY_H
#define LIST_SINGLY_H

#include <string.h>

typedef struct sll_node {
    struct sll_node *next;
} sll_node;

typedef struct sll_list {
    struct sll_node *head;
} sll_list;

sll_node *
sll_insert_after(sll_node *elem, sll_node *new);

sll_list *
sll_insert_back(sll_list *list, sll_node *new);

sll_list *
sll_insert_front(sll_list *list, sll_node *new);

int
sll_is_empty(sll_list *list);

sll_node *
sll_remove_after(sll_node *elem);

sll_list *
sll_remove_back(sll_list *list);

sll_list *
sll_remove_front(sll_list *list);

sll_list *
sll_reverse(sll_list *list);

#endif /* LIST_SINGLY_H */


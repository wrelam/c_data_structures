/***************************************************************************//**
    @file   list_singly.h

    @brief  Interface to a singly linked list implementation

    When used, an sll_node/list should be the first member in a struct.
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

/*******************************************************************************
    sll_for_each
*//**
    @brief  Iterates over an sll_list
    @param  _listPtr   Pointer to an sll_list struct to iterate over
    @param  _curPtr     Pointer to a variable holding each member of the list
    @param  _type       Type of _cur
    @param  _member     sll_node member name within _type
*******************************************************************************/
#define sll_for_each(_listPtr, _curPtr, _type, _member) \
    for ((_curPtr) = (_type) (_listPtr)->head;          \
         NULL != (_curPtr);                             \
         (_curPtr) = (_type) (_curPtr)->_member.next)

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


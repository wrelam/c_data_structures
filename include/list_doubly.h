/***************************************************************************//**
    @file   doubly_linked_list.h

    @brief  Interface to a doubly linked list implementation
*******************************************************************************/
#ifndef LIST_DOUBLY_H
#define LIST_DOUBLY_H

#include <stdlib.h>

typedef struct dll_node {
    struct dll_node *next;
    struct dll_node *prev;
    void *data;
} dll_node;

typedef struct dll_list {
    struct dll_node *head;
} dll_list;

/*******************************************************************************
    dll_for_each
*//**
    @brief  Iterates over a dll_list
    @param  _listPtr    Pointer to an dll_list struct to iterate over
    @param  _curPtr     Pointer to a variable holding each member of the list
    @param  _type       Type of _cur
    @param  _member     dll_node member name within _type
    @param  _tmpPtr     Temporary pointer to prevent issues when deleting nodes

    The ", 1" ensures that the only condition that applies is the NULL check on
    curPtr and that a NULL next entry does not prematurely stop the loop.
*******************************************************************************/
#define dll_for_each(_listPtr, _curPtr, _type, _member, _tmpPtr)               \
    for ((_curPtr) = (_type) (_listPtr)->head;                                 \
         NULL != (_curPtr) && ((_tmpPtr) = (_type) (_curPtr)->_member.next, 1);\

/*******************************************************************************
    dll_for_each_rev
*//**
    @brief  Iterates over a dll_list in reverse
    @param  _listPtr    Pointer to an dll_list struct to iterate over
    @param  _curPtr     Pointer to a variable holding each member of the list
    @param  _type       Type of _cur
    @param  _member     dll_node member name within _type
    @param  _tmpPtr     Temporary pointer to prevent issues when deleting nodes

    The ", 1" ensures that the only condition that applies is the NULL check on
    curPtr and that a NULL next entry does not prematurely stop the loop.
*******************************************************************************/
#define dll_for_eachrev(_listPtr, _curPtr, _type, _member, _tmpPtr)            \
    dll_node *_backPtr = (_listPtr)->head;                                     \
    while (NULL != _backPtr->next)                                             \
    {                                                                          \
        _backPtr = backPtr->next;                                              \
    }                                                                          \
    for ((_curPtr) = (_type) _backPtr;                                         \
         NULL != (_curPtr) && ((_tmpPtr) = (_type) (_curPtr)->_member.prev, 1);\
         (_curPtr) = (_tmpPtr))

dll_node *
dll_insert_after(dll_node *elem, dll_node *new);

dll_list *
dll_insert_back(dll_list *list, dll_node * new);

dll_node *
dll_insert_before(dll_node *elem, dll_node *new);

dll_list *
dll_insert_front(dll_list *list, dll_node *new);

int
dll_is_empty(dll_list *list);

void
dll_remove(dll_node *elem);

dll_list *
dll_remove_back(dll_list *list);

dll_list *
dll_remove_front(dll_list *list);

dll_list *
dll_reverse(dll_list *list);

#endif /* LIST_DOUBLY_H */


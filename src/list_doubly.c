/***************************************************************************//**
    @file   list_doubly.c

    @brief  Implementation of a doubly linked list
*******************************************************************************/
#include <stdlib.h>

#include "list_doubly.h"

/*******************************************************************************
    dll_insert_after
*//**
    @brief  Inserts one node after another
    @param  *elem   List node after which the new node is inserted
    @param  *new    List node being inserted

    @return Frontmost node of the pair
    @retval NULL    Given node was NULL
*******************************************************************************/
dll_node *
dll_insert_after(dll_node *elem, dll_node *new)
{
    if ((NULL != elem) &&
        (NULL != new))
    {
        new->prev = elem;
        new->next = elem->next;
        if (NULL != elem->next)
        {
            elem->next->prev = new;
        }
        elem->next = new;
    }

    return elem;
}


/*******************************************************************************
    dll_insert_back
*//**
    @brief  Inserts a node at the end of a list
    @param  *list   List to modify
    @param  *new    List node being inserted

    @see    dll_insert_after()

    @return Modified list
    @retval NULL    List does not exist
*******************************************************************************/
dll_list *
dll_insert_back(dll_list *list, dll_node *new)
{
    dll_node *iter = NULL;

    if (NULL != list)
    {
        /* Adding the initial node to the list */
        if (NULL == list->head)
        {
            list->head = new;
        }
        /* Find the last node and append */
        else
        {
            iter = list->head;

            while (NULL != iter->next)
            {
                iter = iter->next;
            }

            iter = dll_insert_after(iter, new);
        }
    }

    return list;
}


/*******************************************************************************
    dll_insert_before
*//**
    @brief  Inserts one node before another
    @param  *elem   List node before which a node will be added
    @param  *new    List node being inserted

    @return Frontmost node of the pair
    @retval NULL    Given node was NULL
*******************************************************************************/
dll_node *
dll_insert_before(dll_node *elem, dll_node *new)
{
    if ((NULL != elem) &&
        (NULL != new))
    {
        new->next = elem;
        new->prev = elem->prev;
        if (NULL != elem->prev)
        {
            elem->prev->next = new;
        }
        elem->prev = new;
    }

    return new;
}


/*******************************************************************************
    dll_insert_front
*//**
    @brief  Inserts a node at the beginning of a list
    @param  *list   List to modify
    @param  *new    List node being inserted

    @return Modified list
    @retval NULL    List does not exist
*******************************************************************************/
dll_list *
dll_insert_front(dll_list *list, dll_node *new)
{
    if (NULL != list)
    {
        if (NULL != list->head)
        {
            new = dll_insert_after(new, list->head);
        }

        list->head = new;
    }

    return list;
}


/*******************************************************************************
    dll_is_empty
*//**
    @brief  Determines if a list is empty or not
    @param  *list   List to check

    @return Boolean indicating emptiness
    @retval 0   List is not empty
    @retval !0  List is empty
*******************************************************************************/
int
dll_is_empty(dll_list *list)
{
    return !((NULL != list) && (NULL != list->head));
}


/*******************************************************************************
    dll_remove
*//**
    @brief  Removes a node from the list to which it belongs
    @param  *elem   The list node to remove
*******************************************************************************/
void
dll_remove(dll_node *elem)
{
    if (NULL != elem)
    {
        if (NULL != elem->next)
        {
            elem->next->prev = elem->prev;
            elem->next = NULL;
        }

        if (NULL != elem->prev)
        {
            elem->prev->next = elem->next;
            elem->prev = NULL;
        }

    }
}


/*******************************************************************************
    dll_remove_back
*//**
    @brief  Removes the element at the back of the list
    @param  *list   List from which the back element will be removed

    @see    dll_remove()

    @return Modified list
    @retval NULL    List does not exist
*******************************************************************************/
dll_list *
dll_remove_back(dll_list *list)
{
    dll_node *iter = NULL;

    if (NULL != list)
    {
        iter = list->head;

        while (NULL != iter->next)
        {
            iter = iter->next;
        }

        dll_remove(iter);
    }

    return list;
}


/*******************************************************************************
    dll_remove_front
*//**
    @brief  Removes the element at the front of the list
    @param  *list   List from which the front element will be removed

    @see    dll_remove()

    @return Modified list
    @retval NULL    List does not exist
*******************************************************************************/
dll_list *
dll_remove_front(dll_list *list)
{
    dll_node *newHead = NULL;

    if (!dll_is_empty(list))
    {
        newHead = list->head->next;

        if (NULL != list->head->next)
        {
            list->head->next->prev = NULL;
        }

        dll_remove(list->head);
        list->head = newHead;
    }

    return list;
}


/*******************************************************************************
    dll_reverse
*//**
    @brief  Reverses a list
    @param  *list   List to reverse

    @return Reversed list
    @retval NULL    List does not exist
*******************************************************************************/
dll_list *
dll_reverse(dll_list *list)
{
    dll_node *tmp = NULL;

    if (!dll_is_empty(list))
    {
        while (NULL != list->head)
        {
            tmp = list->head->next;
            list->head->next = list->head->prev;
            list->head->prev = list->head->next;
            list->head = tmp;
        }
    }

    return list;
}


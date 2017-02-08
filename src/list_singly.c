/***************************************************************************//**
    @file   list_singly.c

    @brief  Implementation of a singly linked list
*******************************************************************************/
#include <stdlib.h>

#include "list_singly.h"

/*******************************************************************************
    sll_insert_after
*//**
    @brief  Inserts one node after another
    @param  *elem   List node having a node inserted after it
    @param  *new    List node being inserted

    @return Frontmost node of the pair
    @retval NULL    Given node was NULL
*******************************************************************************/
sll_node *
sll_insert_after(sll_node *elem, sll_node *new)
{
    if ((NULL != elem) &&
        (NULL != new))
    {
        new->next = elem->next;
        elem->next = new;
    }

    return elem;
}


/*******************************************************************************
    sll_insert_back
*//**
    @brief  Inserts a node at the end of a list
    @param  *list   List to modify
    @oaram  *new    List node being inserted

    @return Modified list
    @retval NULL    List does not exist
*******************************************************************************/
sll_list *
sll_insert_back(sll_list *list, sll_node *new)
{
    sll_node *iter = NULL;

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

            iter = sll_insert_after(iter, new);
        }
    }

    return list;
}


/*******************************************************************************
    sll_insert_front
*//**
    @brief  Inserts a node at the beginning of a list
    @param  *list   List to modify
    @param  *new    List node being inserted

    @return Modified list
    @retval NULL    List does not exist
*******************************************************************************/
sll_list *
sll_insert_front(sll_list *list, sll_node *new)
{
    if (NULL != list)
    {
        if (NULL != list->head)
        {
            new = sll_insert_after(new, list->head);
        }

        list->head = new;
    }

    return list;
}


/*******************************************************************************
    sll_is_empty
*//**
    @brief  Determines if a list is empty or not
    @param  *list   List to check

    @return Boolean indicating emptiness
    @retval 0   List is not empty
    @retval !0  List is empty
*******************************************************************************/
int
sll_is_empty(sll_list *list)
{
    return !((NULL != list) && (NULL != list->head));
}


/*******************************************************************************
    sll_remove_after
*//**
    @brief  Removes the node following the given node
    @param  *elem   List node having the node after it removed

    @return Provided node
*******************************************************************************/
sll_node *
sll_remove_after(sll_node *elem)
{
    sll_node *del = NULL;

    /* Nodes exist after the given node */
    if ((NULL != elem) &&
        (NULL != elem->next))
    {
        del = elem->next;
        elem->next = elem->next->next;
        del->next = NULL;
    }

    return elem;
}


/*******************************************************************************
    sll_remove_back
*//**
    @brief  Removes the element at the back of the list
    @param  *list   List to remove from

    @return Modified list
*******************************************************************************/
sll_list *
sll_remove_back(sll_list *list)
{
    sll_node *del = NULL;
    sll_node **iter = NULL;

    if (!sll_is_empty(list))
    {
        iter = &(list->head);
        del = list->head;

        while (NULL != del->next)
        {
            iter = &(del->next);
            del = del->next;
        }

        *iter = NULL;
    }

    return list;
}

/*******************************************************************************
    sll_remove_front
*//**
    @brief  Removes the element at the front of the list
    @param  *list   List to remove from

    @return Modified list
*******************************************************************************/
sll_list *
sll_remove_front(sll_list *list)
{
    sll_node *newHead = NULL;

    if (!sll_is_empty(list))
    {
        newHead = list->head->next;
        list->head->next = NULL;
        list->head = newHead;
    }

    return list;
}


/*******************************************************************************
    sll_reverse
*//**
    @brief  Reverses a linked list
    @param  *list   List to reverse

    @return Reversed list
*******************************************************************************/
sll_list *
sll_reverse(sll_list *list)
{
    sll_node *tmp = NULL;
    sll_node *prev = NULL;

    if (!sll_is_empty(list))
    {
        while (NULL != list->head)
        {
            tmp = list->head->next;
            list->head->next = prev;
            prev = list->head;
            list->head = tmp;
        }

        list->head = prev;
    }

    return list;
}


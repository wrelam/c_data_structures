/***************************************************************************//**
    @file   tree_mary.c

    @brief  Implementation of an M-ary tree
*******************************************************************************/
#include <stddef.h>

#include "list_doubly.h"
#include "tree_mary.h"

/*******************************************************************************
    mt_add_child
*//**
    @brief  Adds a new child to an existing node
    @param  *node   Node receiving a new child
    @param  *child  Node being added
*******************************************************************************/
void
mt_add_child(MTreeNode *node, MTreeNode *child)
{
    if ((NULL != node) &&
        (NULL != child))
    {
        dll_insert_back(&(node->children), &(child->link));
        child->parent = node;
    }
}


/*******************************************************************************
    mt_add_child_front
*//**
    @brief  Adds a node as the first child of an existing node
    @param  *node   Node receiving a new child
    @param  *child  Node being added
*******************************************************************************/
void
mt_add_child_front(MTreeNode *node, MTreeNode *child)
{
    if ((NULL != node) &&
        (NULL != child))
    {
        dll_insert_front(&(node->children), &(child->link));
        child->parent = node;
    }
}


/*******************************************************************************
    mt_add_sibling
*//**
    @brief  Adds a sibling to an existing node
    @param  *node       Node receiving a new sibling
    @param  *sibling    Node being added as a sibling
*******************************************************************************/
void
mt_add_sibling(MTreeNode *node, MTreeNode *sibling)
{
    if ((NULL != node) &&
        (NULL != sibling))
    {
        dll_insert_after(&(node->link), &(sibling->link));
        sibling->parent = node->parent;
    }
}


/*******************************************************************************
    mt_rem_child
*//**
    @brief  Removes a child from its parent
    @param  *node   Node to be orphaned
*******************************************************************************/
void
mt_rem_child(MTreeNode *node)
{
    if (NULL != node)
    {
        dll_remove(&(node->link));
    }
}


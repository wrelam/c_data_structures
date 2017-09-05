/***************************************************************************//**
    @file   stack.c

    @brief  Implementation of a stack using an array
*******************************************************************************/
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "stack.h"

/*******************************************************************************
    s_push
*//**
    @brief  Push an element onto a stack
    @param  *stack  Stack receiving a new element
    @param  elm     Element to be added
*******************************************************************************/
void
s_push(Stack *stack, void *elm)
{
    void *new = NULL;

    if (stack)
    {
        if ((MAX_STACK_DEPTH - 1) > stack->top)
        {
            new = calloc(1, stack->elm_len);
            if (new)
            {
                memcpy(new, elm, stack->elm_len);
                stack->stack[++stack->top] = new;
            }
        }
    }
}


/*******************************************************************************
    s_pop
*//**
    @brief  Pop an elm from a stack
    @param  *stack  Stack to pop from
    @param  *dst    Where to write the popped value (optional)

    @return An element from the stack
*******************************************************************************/
void
s_pop(Stack *stack, void *dst)
{
    if (stack)
    {
        if (dst)
        {
            memcpy(dst, stack->stack[stack->top], stack->elm_len);
        }
        free(stack->stack[stack->top]);
        stack->stack[stack->top] = NULL;
        stack->top--;
    }
}


/*******************************************************************************
    s_peek
*//**
    @brief  Peek the element at the top of a stack
    @param  *stack  Stack to be peeked
*******************************************************************************/
void
s_peek(Stack *stack, void *dst)
{
    if (stack && dst)
    {
        memcpy(dst, stack->stack[stack->top], stack->elm_len);
    }
}


/*******************************************************************************
    s_is_empty
*//**
    @brief  Indicates whether a stack is empty or not
    @param  *stack  Stack in question

    @return Boolean indicator
    @retval 0   Stack is not empty
    @retval !0  Stack is empty
*******************************************************************************/
int
s_is_empty(Stack *stack)
{
    return (stack) ? (0 == stack->top) : 1;
}


/*******************************************************************************
    s_pop_all
*//**
    @brief  Pops all elements off of a stack
    @param  *stack  Stack from which elements will be popped
*******************************************************************************/
void
s_pop_all(Stack *stack)
{
    while ( !s_is_empty(stack) )
    {
        s_pop(stack, NULL);
    }
}


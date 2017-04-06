/***************************************************************************//**
    @file   stack.h

    @brief  Interface to a stack implementation using an array
*******************************************************************************/
#ifndef STACK_H
#define STACK_H

#include <stddef.h>

#define MAX_STACK_DEPTH     (10000)

typedef struct Stack
{
    void * stack[MAX_STACK_DEPTH];
    int top;
    size_t elm_len;
} Stack;

void
s_push(Stack *stack, void *elm);

void
s_pop(Stack *stack, void *dst);

void
s_peek(Stack *stack, void *dst);

int
s_is_empty(Stack *stack);

void
s_pop_all(Stack *stack);

#endif /* STACK_H */


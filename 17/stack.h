#include <stdio.h>
#include <stdlib.h>

typedef struct nodes
{
    int data;
    struct nodes *left;
    struct nodes *right;
}branch;

typedef struct cel
{
    branch *node;
    struct cel *next;
}cell;

typedef struct stacks
{
    cell *root;
}stack;

void makenullStack(cell *s)
{
    if (s == NULL)
    {
        free(s);
        return;
    }
    else
    {
        makenullStack(s -> next);
    }
}

stack *createStack()
{
    stack *s;
    s = (stack*)malloc(sizeof(stack));

    s -> root = NULL;
    return s;
}

void push(stack *s, branch *a)
{
    cell *c;
    c = (cell*)malloc(sizeof(cell));
    c -> node = a;
    c -> next = s -> root;

    s -> root = c;
    return;
}

void pop(stack *s)
{
    if (s == NULL)
    {
        printf("Stack already empty\n");
        return;
    }
    else
    {
        cell* temp;

        temp = s -> root;
        s -> root = s -> root -> next;
        free(temp);
        return;
    }
}

int top(stack *s)
{
    return s -> root -> node -> data;
}

int isEmpty(stack *s)
{
    if (s == NULL) return 1;
    else return 0;
}

int size(stack *s)
{
    int counter = 0;

    cell *runner = s -> root;

    while (runner != NULL)
    {
        counter++;
        runner = runner -> next;
    }
    return counter;
}

void printStack(stack *s)
{
    cell *runner = s -> root;

    while (runner != NULL)
    {
        printf("%c\t", runner -> node -> data);
        runner = runner -> next;
    }
    printf("\n");
    return;
}
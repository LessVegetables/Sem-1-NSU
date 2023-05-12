#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int data;
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

void push(stack *s, int a)
{
    cell *c;
    c = (cell*)malloc(sizeof(cell));
    c -> data = a;
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
    return s -> root -> data;
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
        printf("%d\t", runner -> data);
        runner = runner -> next;
    }
    printf("\n");
    return;
}


int main()
{
    stack* s = createStack();

    for (int i = 0; i < 10; i++)
    {
        push(s, i);
    }

    printStack(s);
    printf("size: %d\ntop: %d\n", size(s), top(s));
    
    pop(s);

    printStack(s);
    printf("size: %d\nis it empty? %d\n", size(s), isEmpty(s));
    
    makenullStack(s -> root);
    
    printf("size: %d\nis it empty? %d\n", size(s), isEmpty(s));
    
    pop(s);
    
    printStack(s);


    return 0;
}
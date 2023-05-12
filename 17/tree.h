#include <stdio.h>
#include <stdlib.h>


typedef struct nodes
{
    int data;
    struct nodes *left;
    struct nodes *right;
}branch;


typedef struct tree
{
    branch *root;
}Tree;

typedef struct cel
{
    branch *node;
    struct cel *next;
}cell;

typedef struct stacks
{
    cell *root;
}stack;


void makenullTree(branch *t)
{
    if (t == NULL)
    {
        free(t);
        return;
    }
    else
    {
        makenullTree(t -> left);
        makenullTree(t -> right);
    }
}


Tree *createTree()
{
    Tree *t;
    t = (Tree*) malloc(sizeof(Tree));

    t -> root = NULL;
    return t;
}


void printInner(branch *b) //внутренний обход
{
    if (b -> left != NULL)
    {
        printInner(b -> left);
    }
    printf("%c ", b -> data);
    if (b -> right != NULL)
    {
        printInner(b -> right);
    }
}


void printTree(Tree *F)
{
    printInner(F -> root);
}


char getTree(Tree *F)
{
    return getInner(F -> root);
}


char getInner(branch *b) //внутренний обход
{
    if (b -> left != NULL)
    {
        return getInner(b -> left);
    }
    return (b -> data);
    if (b -> right != NULL)
    {
        return getInner(b -> right);
    }
}
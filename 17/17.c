// 17. Определить, эквивалентна ли заданная логическая формула формуле FALSE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// start of binary tree
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}branch;

typedef struct tree
{
    branch *root;
}Tree;

void makenull(branch *t);

Tree *create();

void grow(branch *t, char a);

void add(Tree *tree, char a);

void printInner(branch *b);

void print(Tree *F);
// end of bianry tree

// determins wether or not a char is an element (1) or an operand/braket (0)
// & — and 
// + — or 
// > — implication
// ~ — not
int element(char temp);


int priority(char c);


// returns the result of the passed logical function (only: and, or, implication)
int function(int a, char operand, int b);


// constructing the column of 1's and 0's for an element
// Note: serves a greater purpous. In main — there's a loop that does this for all of the inputed elements
void adding(int *subtable, int frequency, int lenght);


char* elementPointer;
int whatTheElement(char temp);
// returns the element index, to know from what column of 1s0s to read from in logic();

int** globalTablePointer;
// recursive function that does the "main" part — solves the inputed logical problem for row j
int logic(char* start, char* end, int j);


int main()
{
    int elementCount = 0;
    
    char input[100];
    Tree *input = create();
    char elements[15], symb; // if 15 to be changed, change in whatTheElement(), too
    elementPointer = elements; // needed for whatTheElement

    printf("& — and\n+ — or\n> — implication\n~ — not\nEnter the logical equation:\t");
    fgets(input, sizeof(input), stdin);
    
    printf("You've inputed:\tF = ");
    puts(input);

    


    int end;    //needed for pasing the input into logic()
    for (int i = 0; i < 100; i++)
    {
        symb = input[i];
        //printf("pointer:\t %c\t", *&symb);
        if (symb == NULL)
        {
            end = i - 2; // if end=i-1, then input[end] would be '\n'
            break;
        }
        
        if (element(symb))
        {
            elements[elementCount] = symb;
            elementCount++;
        }
    }

    printf("element count:\t%d\n", elementCount);


    // initialization of the table of 1's and 0's of the elements
    int rowCount = (int)pow(2, elementCount);
    int** table = (int**)malloc(elementCount * sizeof(int*));
    globalTablePointer = table;
    for (int i = 0; i < elementCount; i++)
    {
        table[i] = (int*)malloc(rowCount * sizeof(int));
    }

    // adding 0 and 1 into the array
    for (int i = 0; i < elementCount; i++)
    {
        adding(table[i], (int)pow(2, i), rowCount);
    }





    // for (int i = 0; i < elementCount; i++)
    // {
    //     printf("%c\t", elements[i]);
    // }
    // printf("\n");

// start of my visualisation (comment before submitting)
    for (int i = 0; i < elementCount; i++)
    {
        printf("%c\t", elements[i]);

        for (int j = 0; j < rowCount; j++)
        {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rowCount + 1; i++)
    {
        printf("|\t");
    }
    //printf("\n");

    printf("\nF\t");
    int output = 0, temp;
    for (int j = 0; j < rowCount; j++)
    {
        temp = logic(input, input + end, j);    // this is the stuff
        output = (output || temp);              // ? why? why not: output = temp; oh right — bc "output" is the ответ задачи, while temp — is for the visualization
        printf("%d\t", temp);
    }
// end of my visualisation


    if (output) printf("\nNO\n");
    else printf("\nYES\n");


    for (int i = 0; i < elementCount; i++)
    {
        free(table[i]);
    }
    free(table);

    makenull(input -> root);
    free(input);

    return 0;
}


// (, ), &, +, >;
int element(char temp)
{
    if (temp == '(' || temp == ')' || temp == '&' || temp == '+' || temp == '>' || temp == '~' || temp == ' ' || temp == '\n')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int priority(char c)
{
    switch (c)
    {
    case '~':
        return 5;
    case '&':
        return 4;
    case '+':
        return 3;
    case '>':
        return 2;
    default:
        return 1;
    }
}

int function(int a, char operand, int b)
{
    switch (operand)
    {
    case '+':
        return (a || b);
    case '&':
        return (a && b);
    case '>':
        return ((!a) || b);
    
    default:
        break;
    }
    return 2;
}


void adding(int *subtable, int frequency, int lenght)
{
    int bit = 0;
    for (int i = 0; i < lenght;)
    {
        for (int j = 0; j < frequency; j++)
        {
            subtable[i] = bit;
            i++;
        }
        bit = !bit;
    }
}


int whatTheElement(char temp)
{
    for (int i = 0; i < 15; i++)    // 15 — bc thats the size of the array defined in main()
    {
        if (temp == *(elementPointer + i))
        {
            return i;
        }
    }
    return 15; // makeshift error message (since 15 could not be returned in a normal situation)
}


int logic(char* start, char* end, int j)
{
    if (start == end + 1) return 1;

    char c = *start;

    switch (c)
    {
        case ('('):
            start += 1;
            return logic(start, end, j);            
            break;

        case (')'):
            return;
            break;

        case ('~'):
            start += 1;
            return !logic(start, end, j);
            break;

        case ('&'):
            /* code */
            break;

        case ('+'):
            /* code */
            break;

        case ('>'):
            /* code */
            break;

        default:
            return globalTablePointer[whatTheElement(c), j];    // to be tested (mb need to swap i and j)
            break;
    }






    // int bracketCount = 0;

    // char* newStart;

    // //printf("start: %p\t end: %p\n", start, end);

    // for (char* i = start; i != end + 1; i++)
    // {
    //     if (*i == '(') bracketCount++;
    // }

    return 2;
}


// start of binary tree

void makenull(branch *t)
{
    if (t == NULL)
    {
        free(t);
        return;
    }
    else
    {
        makenull(t -> left);
        makenull(t -> right);
    }
}


Tree *create()
{
    Tree *t;
    t = (Tree*) malloc(sizeof(Tree));

    t -> root = NULL;
    return t;
}


void grow(branch *t, char a)
{

    if (priority(t -> data) >= priority(a))
    {
        if (t -> left == NULL)
        {
            branch *b;
            b = (branch*) malloc (sizeof(branch));
            b -> data = a;
            b -> left = NULL;
            b -> right = NULL;
            t -> left = b;
        }
        else 
        {
            grow(t -> left, a);
        }
    }
    else if (t -> data < a)
    {
        if (t -> right == NULL)
        {
            branch *b;
            b = (branch*) malloc (sizeof(branch));
            b -> data = a;
            b -> left = NULL;
            b -> right = NULL;
            t -> right = b;
        }
        else 
        {
            grow(t -> right, a);
        }
    }
}


void add(Tree *tree, char a)
{
    if (tree -> root == NULL)
    {
        branch *b;
        b = (branch*) malloc (sizeof(branch));
        b -> data = a;
        b -> left = NULL;
        b -> right = NULL;
        tree -> root = b;
    }
    else
    {
        grow(tree -> root, a);
    }
}

void printInner(branch *b) //внутренний обход (видимо лол)
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

void print(Tree *F)
{
    printInner(F -> root);
}

// end of binary tree
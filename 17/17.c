// 17. Определить, эквивалентна ли заданная логическая формула формуле FALSE


/* 
FIX the grow() function
Complete the Logic() function

and you're done
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #include <stack.h>
// #include <tree.h>


typedef struct nodes
{
    char data;
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
}treeCell;
typedef struct stacks
{
    treeCell *root;
}treeStack;


typedef struct cell
{
    char data;
    struct cell *next;
}charCell;
typedef struct stack
{
    charCell *root;
}charStack;

// determins wether or not a char is an element (1) or an operand/braket (0)
// * — and 
// + — or 
// > — implication
// ~ — not
int element(char temp);

int inArray(char* operands, char a);

// 4 abc
// 3 ~
// 2 *
// 1 +
// 0 >
int priority(char c);


// never used this...
// returns the result of the passed logical function (only: and, or, implication)
int function(int a, char operand, int b);


// constructing the column of 1's and 0's for an element
// Note: serves a greater purpous. In main — there's a loop that does this for all of the inputed operands
void adding(int *subtable, int frequency, int lenght);


char* operandPointer;
int* operandCountPointer;
int whatTheElement(char temp);
// returns the element index, to know from what column of 1s0s to read from in logic();


int** globalTablePointer;
// recursive function that does the "main" part — solves the inputed logical problem for row j
int logic(branch* b, int j);

// START OF TREE STUFF
void makenullTree(branch *t);

Tree *createTree();

void printInner(branch *b); //внутренний обход

void printTree(Tree *F);

char getTree(Tree *F);

char getInner(branch *b); //внутренний обход

// END OF TREE STUFF


// START OF TREESTACK STUFF
void makenullTreeStack(treeCell *s);

treeStack *createTreeStack();

void pushT(treeStack *s, branch *a);

void popT(treeStack *s);

branch* topT(treeStack *s);                     // try removing the pointer if all else fails

int isEmptyT(treeStack *s);

int sizeT(treeStack *s);

void printTreeStack(treeStack *s);
// END OF TREESTACK STUFF


// START OF CHARSTACK STUFF
void makenullCharStack(charCell *s);

charStack *createCharStack();

void pushC(charStack *s, char a);

void popC(charStack *s);

char topC(charStack *s);

int isEmptyC(charStack *s);

int sizeC(charStack *s);

void printCharStack(charStack *s);
// END OF CHARSTACK STUFF



// build Expression Tree from inputed string
int *inputSizePointer;
branch *build(char* s);

int main()
{
    // preperation for inputting
    int inputSize = 0;
    char* input = (char*)malloc(inputSize * sizeof(char));

    inputSizePointer = &inputSize;          // needed for build

    int operandCount = 0;
    char* operands = (char*)malloc(operandCount * sizeof(char));

    operandPointer = operands;              // needed for whatTheElement
    operandCountPointer = &operandCount;    // needed for whatTheElement


    printf("* — and\n+ — or\n> — implication\n~ — not\nEnter the logical equation:\t");


    // inputting
    char in; int counterIn = 0;
    scanf("%c", &in);
    while (in != '\n')
    {
        inputSize++;
        input = (char*)realloc(input, inputSize * sizeof(char));
        input[inputSize - 1] = in;

        if (element(in))
        {
            if (!inArray(operands, in))
            {
                operandCount++;
                operands = (char*)realloc(operands, operandCount * sizeof(char));
                operands[operandCount - 1] = in;
            }
        }

        scanf("%c", &in);
    }


    // converting to tree
    Tree* expTree = createTree();
    expTree -> root = build(input);


    printf("You've inputed:\tF = ");
    for (int i = 0; i < inputSize; i++)
    {
        printf("%c", input[i]);
    }
    printf("\nOperand count:\t%d\n\n", operandCount);


    // initialization of the table of 1's and 0's of the elements
    int rowCount = (int)pow(2, operandCount);
    int** table = (int**)malloc(operandCount * sizeof(int*));
    globalTablePointer = table;
    for (int i = 0; i < operandCount; i++)
    {
        table[i] = (int*)malloc(rowCount * sizeof(int));
    }


    // adding 0 and 1 into the array
    for (int i = 0; i < operandCount; i++)
    {
        adding(table[i], (int)pow(2, i), rowCount);
    }


// start of my visualisation (comment before submitting ^but dont, bc logic() is in here)
    for (int i = 0; i < operandCount; i++)
    {
        printf("%c\t", operands[i]);

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
        temp = logic(expTree -> root, j);    // this is the stuff
        output = (output || temp);         // ? why? why not: output = temp; oh right — bc "output" is the ответ задачи, while temp — is for the visualization
        printf("%d\t", temp);
    }
// end of my visualisation


    // answer
    if (output) printf("\n\nNO\n");
    else printf("\n\nYES\n");


    // cleanup
    for (int i = 0; i < operandCount; i++)
    {
        free(table[i]);
    }
    free(table);
    free(operands);
    free(input);
    makenullTree(expTree -> root);
    free(expTree);


    return 0;
}


// (, ), *, +, >;
int element(char temp)
{
    if (temp == '(' || temp == ')' || temp == '*' || temp == '+' || temp == '>' || temp == '~' || temp == ' ' || temp == '\n')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int inArray(char* operands, char a)
{
    for (int i = 0; i < *operandCountPointer; i++)
    {
        if (operands[i] == a)
        {
            return 1;
        }
    }
    return 0;
}

int priority(char c)
{
    switch (c)
    {
    case '~':
        return 3;
    case '*':
        return 2;
    case '+':
        return 1;
    case '>':
        return 0;
    default:
        return 4;
    }
}


// never used this...
int function(int a, char operand, int b)
{
    switch (operand)
    {
    case '+':
        return (a || b);
    case '*':
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
    for (int i = 0; i < *operandCountPointer; i++)
    {
        if (temp == *(operandPointer + i))
        {
            return i;
        }
    }
    return -1; // makeshift error message (since -1 could not be returned in a normal situation)
}


int logic(branch* b, int j)
{
    char curData = b -> data;

    switch (curData)
    {
        case ('~'):
            return !logic(b -> left, j);
            break;

        case ('*'):
            return (logic(b -> left, j) && logic(b -> right, j));
            break;

        case ('+'):
            return (logic(b -> left, j) || logic(b -> right, j));
            break;

        case ('>'):
            return ((!logic(b -> left, j)) || logic(b -> right, j));
            break;

        default:
            if (whatTheElement(curData) == -1)
            {
                printf("whatTheElement(%c) returned -1", curData);
                break;
            }
            return globalTablePointer[whatTheElement(curData)][j];    // to be tested (mb need to swap i and j)
            break;
    }

    return 2;
}

// START OF TREE STUFF
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
// END OF TREE STUFF


// START OF TREESTACK STUFF
void makenullTreeStack(treeCell *s)
{
    if (s == NULL)
    {
        free(s);
        return;
    }
    else
    {
        makenullTreeStack(s -> next);
    }
}

treeStack *createTreeStack()
{
    treeStack *s;
    s = (treeStack*)malloc(sizeof(treeStack));

    s -> root = NULL;
    return s;
}

void pushT(treeStack *s, branch *a)
{
    treeCell *c;
    c = (treeCell*)malloc(sizeof(treeCell));
    c -> node = a;
    c -> next = s -> root;

    s -> root = c;
    return;
}

void popT(treeStack *s)
{
    if (s == NULL)
    {
        printf("Stack already empty\n");
        return;
    }
    else
    {
        treeCell* temp;

        temp = s -> root;
        s -> root = s -> root -> next;
        free(temp);
        return;
    }
}

branch* topT(treeStack *s)
{
    return s -> root -> node;
}

int isEmptyT(treeStack *s)
{
    if (s == NULL) return 1;
    else return 0;
}

int sizeT(treeStack *s)
{
    int counter = 0;

    treeCell *runner = s -> root;

    while (runner != NULL)
    {
        counter++;
        runner = runner -> next;
    }
    return counter;
}

void printTreeStack(treeStack *s)
{
    treeCell *runner = s -> root;

    while (runner != NULL)
    {
        printf("%c\t", runner -> node -> data);
        runner = runner -> next;
    }
    printf("\n");
    return;
}
// END OF TREESTACK STUFF

// START OF CHARSTACK STUFF
void makenullCharStack(charCell *s)
{
    if (s == NULL)
    {
        free(s);
        return;
    }
    else
    {
        makenullCharStack(s -> next);
    }
}

charStack *createCharStack()
{
    charStack *s;
    s = (charStack*)malloc(sizeof(charStack));

    s -> root = NULL;
    return s;
}

void pushC(charStack *s, char a)
{
    charCell *c;
    c = (charCell*)malloc(sizeof(charCell));
    c -> data = a;
    c -> next = s -> root;

    s -> root = c;
    return;
}

void popC(charStack *s)
{
    if (s == NULL)
    {
        printf("Stack empty\n");
        return;
    }
    else
    {
        charCell* temp = s -> root;
        s -> root = s -> root -> next;

        free(temp);
        return;
    }
}

char topC(charStack *s)
{
    return s -> root -> data;
}

int isEmptyC(charStack *s)
{
    if (s == NULL) return 1;
    else return 0;
}

int sizeC(charStack *s)
{
    int counter = 0;

    charCell *runner = s -> root;

    while (runner != NULL)
    {
        counter++;
        runner = runner -> next;
    }
    return counter;
}

void printCharStack(charStack *s)
{
    charCell *runner = s -> root;

    while (runner != NULL)
    {
        printf("%c\t", runner -> data);
        runner = runner -> next;
    }
    printf("\n");
    return;
}
// END OF CHARSTACK STUFF

branch *build(char* input)
{
 
    // Stack to hold nodes stN
    treeStack* nodesStack = createTreeStack();
 
    // Stack to hold chars stC
    charStack* cStack = createCharStack();
    branch*t, *t1, *t2;
 
    // Prioritising the operators
    int p[130] = { 0 };
    p['>'] = 1, p['+'] = 2, p['*'] = 3, p['~'] = 4, p[')'] = 0;
    
    for (int i = 0; i < *inputSizePointer; i++)
    {
        if (input[i] == '(') {
 
            // Push '(' in char charStack

            pushC(cStack, input[i]);
        }
 
        // Push the operands in node treeStack
        else if (element(input[i]))
        {
            // pushT(nodesStack, newBranch(input[i])); or
            t = (branch*)malloc(sizeof(branch));
            t -> data = input[i];
            t -> left = NULL;
            t -> right = NULL;

            pushT(nodesStack, t);
        }
        else if (p[input[i]] > 0)
        {
            // If an operator with lower or
            // same associativity appears
            while (!isEmptyC(cStack) && topC(cStack) != '(' && ((input[i] != '~' && p[topC(cStack)] >= p[input[i]]) || (input[i] == '~' && p[topC(cStack)] > p[input[i]])))
            {
                // Get and remove the top element
                // from the node treeStack
                t1 = (branch*)malloc(sizeof(branch));
                t1 = topT(nodesStack);
                popT(nodesStack);
                
                // Get and remove the currently top
                // element from the node treeStack
                t2 = (branch*)malloc(sizeof(branch));
                t2 = topT(nodesStack);
                popT(nodesStack);
 
                // Get and remove the top element
                // from the character treeStack
                t = (branch*)malloc(sizeof(branch));
                t -> data = topC(cStack);
                t -> left = t2;
                t -> right = t1;
                popC(cStack);
 
                // Push the node to the node Stack
                pushT(nodesStack, t);
            }
 
            // Push s[i] to char Stack
            pushC(cStack, input[i]);
        }
        else if (input[i] == ')') {
            while (!isEmptyC(cStack) && topC(cStack) != '(')
            {
                t1 = topT(nodesStack);
                popT(nodesStack);

                t2 = topT(nodesStack);
                popT(nodesStack);

                t = (branch*)malloc(sizeof(branch));
                t -> data = topC(cStack);
                t -> left = t2;
                t -> right = t1;
                popC(cStack);

                pushT(nodesStack, t);
            }
            popC(cStack);
        }
    }
    t = topT(nodesStack);
    return t;
}
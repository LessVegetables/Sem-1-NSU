// 17. Определить, эквивалентна ли заданная логическая формула формуле FALSE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// determins wether or not a char is an element (1) or an operand/braket (0)
// & — and 
// + — or 
// > — implication
// ~ — not
int element(char temp);


// returns the result of the passed logical function (only: and, or, implication)
int function(int a, char operand, int b);


// constructing the column of 1's and 0's for an element
// Note: serves a greater purpous. In main — there's a loop that does this for all of the inputed elements
void adding(int *subtable, int frequency, int lenght);


char* elementPointer;
int whatTheElement(char temp);
// returns the element index, to know from what column of 1s0s to read from in logic();


// recursive function that does the "main" part — solves the inputed logical problem for row j
int logic(char* start, char* end, int j);


int main()
{
    int elementCount = 0;
    
    char input[100];
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
        temp = logic(input, input + end, j);
        output = (output || temp);
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
    int bracketCount = 0;

    //printf("start: %p\t end: %p\n", start, end);

    // for (char* i = start; i != end + 1; i++)
    // {

    //     printf("%c", *i);
    // }
    // printf("\n");

    return 2;
}

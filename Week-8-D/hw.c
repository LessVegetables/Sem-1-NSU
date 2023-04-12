// pointers

// Вводится количество игроков и номер выбывающего.
// Программа как в считалочке должна вывести номер
// оставшегося игрока. Т.е. было 4 игрока ввели число 7,
// выбыл сначала 3 игрок, потом 7 отсчитали начиная с
// четвёртого - выбывает 4 игрок, потом первый - остается
// второй. Использовать замкнутый список и указатель.

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list* next;
    struct list* prev;
}cel;

typedef struct listing
{
    cel* head;
    cel* tail;
}List;

void makenull (List* s)
{
    cel* p;

    while (s -> head != s -> tail)
    {
        p = s -> head;
        s -> head = s -> head -> next;
        free(p);
    }
    p = s -> head;
    free(p);
}

List *create()
{
    List* s;
    s = (List*) malloc (sizeof (List));
    s -> head = NULL;
    s -> tail = NULL;
    return s;
}

void pushback(List* s, int a)
{
    cel *p;
    p = (cel*) malloc(sizeof(cel));
    p -> data = a;

    p -> prev = s -> tail;
    p -> next = s -> head;

    if (s -> tail == NULL)
    {
        s -> head = p;
        s -> tail = p;
    }
    else
    {
        s -> tail -> next = p;
        s -> head -> prev = p;
        s -> tail = p;
    }
}

void printList(List* s)
{
    cel* temp;
    temp = s -> head;

    while (temp != s -> tail)
    {
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }

    if (temp != NULL)
    {
        printf("%d\n", temp -> data);
    }
}

int main()
{
    List *arr = create();

    int p = 4, n = 7; // p — player count; n — "считалочка";
    scanf("%d %d", &p, &n);

    

    for (int i = 1; i <= p; i++)
    {
        pushback(arr, i);
    }

    printList(arr);

    cel* cur = arr -> head;
    //printf("%p\n", cur);

    int tempP = p, tempN = n - 1;
    while (tempP != 1)
    {
        if (tempN == 0 && cur -> data != 0)
        {
            //printf("DELETING %d\t", cur -> data);
            cur -> data = 0;
            tempP--;
            //cur = cur -> next;
            tempN = n - 1;
            //printf("tempP: %d tempN: %d\n", tempP, tempN);
        }
        else if (cur -> data == 0)
        {
            //printf("Issa zero, moving on\n");
            cur = cur -> next;
        }
        else
        {
            //printf("Issa not zero, tempN = %d\n", tempN);
            cur = cur -> next;
            tempN--;
        }
    }

    //printList(arr);

    cur = arr -> head;
    for (int i = 0; i < p; i++)
    {
        if(cur -> data != 0)
        {
            printf("%d\n", cur -> data);
            break;
        }
        cur = cur -> next;
    }

    makenull(arr);

    return 0;
}

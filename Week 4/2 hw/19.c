// hw 
// касьянов. курс программирования на паскале
// все задания на рекурсию (никаких циклов)

// стр 260 номер 19 при n == 0

#include <stdio.h>

int n = 0;

void literIt(int depth)
{
    //printf("DEPTH: %d\t", depth);
    char a;
    scanf("%c", &a);
    if (a == '\n')
    {
        return;
    }

    if (depth < 5)
    {
        //n++;
        literIt(depth + 1);
        printf("%c", a);
    }
    else
    {
        printf("%c", a);
        //literIt(1);
        //n = 0;
    }
    if (depth == 1)
    {
        literIt(1);
    }
}

int main()
{
    literIt(1);
    return 0;
}
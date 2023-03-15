#include <stdio.h>

void f()
{
    char a, dot = '.';
    scanf("%c", &a);
    if (a != dot)
    {
        f();
    }
    printf("%c", a);

}

int main()
{
    f();
    return 0;
}
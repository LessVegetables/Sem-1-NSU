#include <stdio.h>
#include <math.h>

int main()
{
    int l = 0;
    int y, a, s = 0;
    
    scanf("%d %d", l, y);
    
    for (int i = 1; i <= l; i++)
    {
        scanf("%d", &a);
        s = s * y + a;
    }

    printf("%d", s);

    return 0;
}
#include <stdio.h>
#include <math.h>

int main()
{
    float x, intermid, a, sinus;

    scanf("%f", &x);

    while (x >= 0)
    {
        a = x;
        sinus = a;
        int i = 0;
        while (fabs(a) - 0.0001 > 0)
        {
            a = a * (-pow(x, 2.0)/((2*i + 3)*(2*i+2)));
            sinus += a;
            i++;
        }
        printf("sin(%f) = %f\n", x, sinus);
        scanf("%f", &x);
    }

    return 0;
}
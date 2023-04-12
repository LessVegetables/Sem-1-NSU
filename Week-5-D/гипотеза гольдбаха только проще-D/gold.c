// Проблема Гольдбаха
// hw due 08.03.2023
// Проблема Гольдбаха (гипотеза Гольдбаха, проблема Эйлера,
// бинарная проблема Гольдбаха) — утверждение о том, что
// любое чётное число, начиная с 4, можно представить в виде
// суммы двух простых чисел.

// Без циклов. Рекурсией.

#include <stdio.h>


// проверка на то, простое ли число y; pass in x 2
int prime(int x, int y)
{
    //printf("%d %d \n", x, y);
    if (y == 1)
    {
        return 1;
    }
    if (x == y)
    {
        return 1;
    }
    else
    {
        return ((y % x != 0) && prime(x + 1, y));
    }
}

void goldbah(int i, int n)
{
    if (i == n || i > n/2)
    {
        return;
    }

    if (prime(2, i))
    {
        if (prime(2, n-i))
        {
            printf("%d %d\n", i, n-i);
        }
    }
    //i++; — doesn't work if you pass it in the function lol: goldbah(i++, n) — it passes the i, not i+1.
    goldbah(i += 1, n);
}



int main()
{
    int n;

    scanf("%d", &n);

    if (n < 2 || n % 2 != 0)
    {
        printf("can't do that, chief\n");
    }
    else
    {
        goldbah(1, n);
        // for (int i = 1; i < n; i++)
        // {
        //     if (prime(2, i))
        //     {
        //         if (prime(2, n-i))
        //         {
        //             printf("%d %d\n", i, n-i);
        //         }
        //     }
        // }
    }

    return 0;
}
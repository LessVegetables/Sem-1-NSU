// Проблема Гольдбаха
// hw due 08.03.2023
// Проблема Гольдбаха (гипотеза Гольдбаха, проблема Эйлера,
// бинарная проблема Гольдбаха) — утверждение о том, что
// любое чётное число, начиная с 4, можно представить в виде
// суммы двух простых чисел.

// Без циклов. Рекурсией.

#include <stdio.h>
#include <stdlib.h>

/*
Решето Эратосфена:

n = input("n=")
a = range(n+1)
a[1] = 0
lst = []

i = 2
while i <= n:
    if a[i] != 0:
        lst.append(a[i])
        for j in xrange(i, n+1, i):
            a[j] = 0
    i += 1
print lst
*/

void erato(int* p, int n);

int main()
{
    int* prime;
    return 0;
}

void erato(int* p, int n)
{
    int* temp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        temp[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if(temp[j] == 0) continue;
            if(j % i == 0)
            {
                temp[j] = 0;
                continue;
            }
        }
        if (i * i > n) break;
    }

    int tempSize = 1;
    p = (int*)malloc(tempSize * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if (temp[i] != 0)
        {
            p[tempSize - 1] = temp[i];
            tempSize++;
            p = (int*)realloc(p, tempSize * sizeof(int));
        }
    }
}


/*
Письменный экзамен
89039304606

Воранкова Полина Сергеевна


*/
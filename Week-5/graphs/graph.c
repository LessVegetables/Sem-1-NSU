#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main()
{
    // signed int iMax = (unsigned int)~0 >> 1; // если хочется выпенриться своими умениями копировать загуглинный код

    int n, s, e, w, max = INT_MAX;

    scanf("%d", &n);

    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = max;
        }
    }

    scanf("%d%d%d", &s, &e, &w);
    while (s != -1 && e != -1 && w != -1)
    {
        arr[s - 1][e - 1] = w;
        scanf("%d%d%d", &s, &e, &w);
    }

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < n - 1; i++)
    {
        
    }


    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
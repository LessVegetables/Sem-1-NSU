// quick sort 2.0 
// 2023

#include <stdio.h>

int a[6];

void print()
{
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void quicksort(int m, int n)
{
    int x, i, j, temp;
    i = m; j = n; x = a[(i+j)/2];

    while (i <= j)
    {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        
        if(i <= j)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
        i++;
        j--;
    }
    if(m < j){ quicksort(m, j);}
    if(i < n){ quicksort(i, n);}
}


int main()
{
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &a[i]);
    }
    print();
    quicksort(0, 5);
    print();
    return 0;
}
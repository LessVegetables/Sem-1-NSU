#include <stdio.h>
#include <time.h>

void bruh(int n)
{
    if (n == 0) return;
    
    int i = 10;
    while(i)
    {
        i--;
        bruh(n - 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    clock_t start = clock();
    bruh(n);
    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f\n", elapsed);

    return 0;
}
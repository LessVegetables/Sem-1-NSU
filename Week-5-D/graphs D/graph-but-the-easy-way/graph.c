#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
    int ans = a, temp[10] = {a, b, c, d, e, f, g, h, i, j};
    for (int q = 0; q < 10; q++)
    {
        if (temp[q] < ans)
        {
            ans = temp[q];
        }
    }
    return ans;
}


int main()
{
    int n, s, e, w, max = 16000;
    int arr[10][10];

    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = max;
        }
    }

    int flag = 0;
    char inp;

    printf("Input from file?\tY/N\n");
    scanf("%c", &inp);
    if(inp == 'Y') flag = 1;

    if (flag)
    {
        FILE *fptr;
        if ((fptr = fopen("/Users/danielgehrman/Documents/Programming/Uni/Sem-1-NSU/Week-5/graphs/graph-but-the-easy-way/input.txt","r")) == NULL)
        {
            printf("Error! opening file");
            // Program exits if the file pointer returns NULL.
            exit(1);
        }

        fscanf(fptr,"%d%d%d%d", &n, &s, &e, &w);

        while (s != -1 && e != -1 && w != -1)
        {
            arr[s - 1][e - 1] = w;
            fscanf(fptr,"%d%d%d", &s, &e, &w);
        }

        fclose(fptr); 
    }
    else
    {
        scanf("%d%d%d%d", &n, &s, &e, &w);

        while (s != -1 && e != -1 && w != -1)
        {
            arr[s - 1][e - 1] = w;
            scanf("%d%d%d", &s, &e, &w);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }


    int ans[10][10];
    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            ans[i][j] = arr[i][j];
        }
    }


    for (int i = 0; i < n - 1; i++)
    {
        for (int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
               ans[i][j] = min(ans[i][0] + arr[0][j], ans[i][1] + arr[1][j], ans[i][2] + arr[2][j], ans[i][3] + arr[3][j], ans[i][4] + arr[4][j], ans[i][5] + arr[5][j], ans[i][6] + arr[6][j], ans[i][7] + arr[7][j], ans[i][8] + arr[8][j], ans[i][9] + arr[9][j]);
            }
        }
    }


    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d\t", ans[i][j]);
        }
        printf("\n");
    }


    return 0;
}
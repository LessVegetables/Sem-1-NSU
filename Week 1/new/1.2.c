#include <stdio.h>
#include <math.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        float x1, y1, x2, y2, x3, y3;
        printf("Enter the coordinates: ");
        scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);


        float S0, S1, S2, S3;
        S0 = 0.5 * fabs((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1));
        S1 = 0.5 * fabs((x2 - 0)*(y3 - 0) - (x3 - 0)*(y2 - 0));
        S2 = 0.5 * fabs((0 - x1)*(y3 - y1) - (x3 - x1)*(0 - y1));
        S3 = 0.5 * fabs((x2 - x1)*(0 - y1) - (0 - x1)*(y2 - y1));
        
        printf("S0:\t%f\nS1:\t%f\nS2:\t%f\nS3\t%f\n", S0, S1, S2, S3);

        if (S1 + S2 + S3 == S0)
        {
            if (S1 && S2 && S3)
            {
                printf("inside\n");
            }
            else
            {
                printf("I walk the line\n");
            }
        }
        else
        {
            printf("outside\n");
        }
    }
    return 0;
}
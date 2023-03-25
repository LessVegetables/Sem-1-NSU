#include <stdio.h>
#include <math.h>

int main()
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

    if (S0 == S1 + S2 + S3)
    {
        float k1, b1, k2, b2, k3, b3;

        k1 = (y1 - y2) / (x1 - x2);
        k2 = (y2 - y3) / (x2 - x3);
        k3 = (y3 - y1) / (x3 - x1);
        b1 = y1 - k1 * x1;
        b2 = y2 - k2 * x2;
        b3 = y3 - k3 * x3;
        printf("y1 = %f*x1 + %f \ny2 = %f*x2 + %f \ny3 = %f*x3 + %f \n", k1, b1, k2, b2, k3, b3);
        
        if (b1 == 0 || b2 == 0 || b3 == 0)
        {
            printf("on the side\n");
        }
        else
        {
            printf("inside\n");
        }
    }
    else
    {
        printf("outside\n");
    }

    return 0;
}
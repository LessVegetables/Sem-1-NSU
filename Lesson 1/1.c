#include <stdio.h>
#include <math.h>

int main()
{
    float x1, y1, x2, y2, x3, y3;
    int state = 0;
    printf("Enter the coordinates: ");
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);



    float S0, S1, S2, S3;
    S0 = 0.5 * fabs((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1));
    S1 = 0.5 * fabs((x2 - 0)*(y3 - 0) - (x3 - 0)*(y2 - y1));
    S2 = 0.5 * fabs((0 - x1)*(y3 - y1) - (x3 - x1)*(0 - y1));
    S3 = 0.5 * fabs((x2 - x1)*(0 - y1) - (0 - x1)*(y2 - y1));

    printf("S0:\t%f\nS1:\t%f\nS2:\t%f\nS3\t%f\n", S0, S1, S2, S3);
    if (S0 == S1 + S2 + S3)
    {
        printf("inside");
    }



    float k1, b1, k2, b2, k3, b3;

    k1 = (y1 - y2) / (x1 - x2);
    k2 = (y2 - y3) / (x2 - x3);
    k3 = (y3 - y1) / (x3 - x1);
    b1 = y1 - k1 * x1;
    b2 = y2 - k2 * x2;
    b3 = y3 - k3 * x3;

    int match1 = 0, match2 = 0, match3 = 0;

    if ((k2*x1 + b2 - y1)*b2 >= 0){ match1 = 1;}
    if ((k3*x2 + b3 - y3)*b3 >= 0){ match2 = 1;}
    if ((k1*x3 + b1 - y3)*b3 >= 0){ match3 = 1;}

    if (match1 * match2 * match3 == 1) { state = 1; /*inside*/}
    else if (match1 * match2 * match3 == 0) { state = 0; /*outside*/}

    if (state)
    {
        if (b1*b2*b3 == 0)
        {
            state = 2; /*on the side*/
        }
    }

    if (state == 0){ printf("outside");}
    if (state == 1){ printf("inside");}
    if (state == 2){ printf("on the side");}

    printf("%f %f, %f %f, %f %f", x1, y1, x2, y2, x3, y3);
    
    return 0;
}
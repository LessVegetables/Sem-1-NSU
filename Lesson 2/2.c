#include <stdio.h>
#include <math.h>

int main()
{
    float x, eps;

    scanf("%f %f", &x, &eps);

    int chis = 1, znam = 2;

    float ans = x, con = chis / znam, intermid = con * pow(x, 3.0) / 3;

    while (fabs(intermid) - eps > 0)
    {
        ans += intermid;
        chis += 2;
        znam += 2;

        con = con * chis / znam;

        intermid = con * pow(x, znam + 1);
    }
    ans += intermid;

    printf(ans);

    return 0;
}
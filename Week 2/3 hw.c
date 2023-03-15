#include <stdio.h>
#include <math.h>


// написать програмы для вычисления определённого интеграла
// точность — 20 участков
// площадь участков считаем в середине
// интеграл: \int_{-1}^2 \frac{x^2}{(x^2 + 1)^2} dx

// double f(double x)
// {
//     return x / pow(pow(x, 2.0) + 1.0, 2.0);
// }


int main()
{
    double delta = 0.15, x, S = 0, temp;

    for (double i = -1.0; i < 2.0; i += delta)
    {
        x = i + 0.5 * delta;
        temp = x / pow(pow(x, 2.0) + 1.0, 2.0) * delta;
        S += temp;
    }
    S -= temp;

    printf("%f\n", S);

    return 0;
}